#include "lib/common.h"

#define  THREAD_NUMBER      4
#define  BLOCK_QUEUE_SIZE   100

extern void loop_echo(int);

typedef struct {
    pthread_t thread_tid;        /* thread ID */
    long thread_count;    /* # connections handled */
} Thread;

Thread *thread_array;

typedef struct {
    int number; // 队列里能容纳描述符的最大个数
    int *fd;    // 描述符指针，也即数组
    int front;  // 队列头
    int rear;   // 队列尾
    pthread_mutex_t mutex;  // 锁
    pthread_cond_t cond;    // 条件变量 condition variables
} block_queue;


// 初始化队列
void block_queue_init(block_queue *blockQueue, int number) {
    blockQueue->number = number;
    blockQueue->fd = calloc(number, sizeof(int));
    blockQueue->front = blockQueue->rear = 0;
    pthread_mutex_init(&blockQueue->mutex, NULL);
    pthread_cond_init(&blockQueue->cond, NULL);
}

void block_queue_push(block_queue *blockQueue, int fd) {
    // push要加锁
    pthread_mutex_lock(&blockQueue->mutex);
    blockQueue->fd[blockQueue->rear] = fd;
    if (++blockQueue->rear == blockQueue->number) {
        blockQueue->rear = 0;
    }
    printf("push fd %d", fd);
    // 表示当前资源已经就绪
    pthread_cond_signal(&blockQueue->cond);
    pthread_mutex_unlock(&blockQueue->mutex);
}


int block_queue_pop(block_queue *blockQueue) {
    pthread_mutex_lock(&blockQueue->mutex);
    while (blockQueue->front == blockQueue->rear)
        // 等待资源就绪
        pthread_cond_wait(&blockQueue->cond, &blockQueue->mutex);
    int fd = blockQueue->fd[blockQueue->front];
    if (++blockQueue->front == blockQueue->number) {
        blockQueue->front = 0;
    }
    printf("pop fd %d", fd);
    pthread_mutex_unlock(&blockQueue->mutex);
    return fd;
}

void thread_run(void *arg) {
    pthread_t tid = pthread_self();
    pthread_detach(tid);

    block_queue *blockQueue = (block_queue *) arg;
    while (1) {
        // 从队列里取出fd
        int fd = block_queue_pop(blockQueue);
        printf("get fd in thread, fd==%d, tid == %d", fd, tid);
        loop_echo(fd);
    }
}

int main(int c, char **v) {
    int listener_fd = tcp_server_listen(SERV_PORT);

    block_queue blockQueue;
    block_queue_init(&blockQueue, BLOCK_QUEUE_SIZE);

    // 创建线程池
    // void *
    //  calloc(size_t count, size_t size);
    thread_array = calloc(THREAD_NUMBER, sizeof(Thread));
    int i;
    for (i = 0; i < THREAD_NUMBER; i++) {
        // 创建THREAD_NUMBER个线程
        pthread_create(&(thread_array[i].thread_tid), NULL, &thread_run, (void *) &blockQueue);
    }

    while (1) {
        struct sockaddr_storage ss;
        socklen_t slen = sizeof(ss);
        int fd = accept(listener_fd, (struct sockaddr *) &ss, &slen);
        if (fd < 0) {
            error(1, errno, "accept failed");
        } else {
            // 直接把fd放进描述符队列里即可
            block_queue_push(&blockQueue, fd);
        }
    }

    return 0;
}