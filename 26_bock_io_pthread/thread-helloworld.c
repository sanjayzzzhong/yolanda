#include "../header/common.h"

int another_shared = 0;

void * thread_run(void *arg) {
    int *calculator = (int *) arg;
    // pthread_self() 返回线程id
    printf("hello, world, tid == %d \n", pthread_self());
    for (int i = 0; i < 10000; i++) {
        *calculator += 1;
        another_shared += 1;
    }
}

int main(int c, char **v) {
    int calculator;

    pthread_t tid1;
    pthread_t tid2;

    // int pthread_create(pthread_t *thread, const pthread_attr_t *attr,
    //                  void *(*start_routine)(void *), void *arg)
    // 成功返回0
    pthread_create(&tid1, NULL, thread_run, &calculator);
    pthread_create(&tid2, NULL, thread_run, &calculator);

    // 调用pthread_join，主线程等待子线程结束，回收已终止线程的资源
    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);

    // 终止线程可以用： pthread_exit(void *status);
    // 调用这个函数，父线程会等待其他子线程终止，之后父进程自己终止

    printf("calculator is %d \n", calculator);
    printf("another_shared is %d \n", another_shared);
}