#include "lib/common.h"

#define MAX_LINE 4096

char
rot13_char(char c) {
    if ((c >= 'a' && c <= 'm') || (c >= 'A' && c <= 'M'))
        return c + 13;
    else if ((c >= 'n' && c <= 'z') || (c >= 'N' && c <= 'Z'))
        return c - 13;
    else
        return c;
}

void child_run(int fd) {
    char outbuf[MAX_LINE + 1];
    size_t outbuf_used = 0;
    ssize_t result;

    while (1) {
        char ch;
        result = recv(fd, &ch, 1, 0);
        if (result == 0) {
            break;
        } else if (result == -1) {
            perror("read");
            break;
        }

        /* We do this test to keep the user from overflowing the buffer. */
        if (outbuf_used < sizeof(outbuf)) {
            outbuf[outbuf_used++] = rot13_char(ch);
        }

        if (ch == '\n') {
            send(fd, outbuf, outbuf_used, 0);
            outbuf_used = 0;
            continue;
        }
    }
}


void sigchld_handler(int sig) {
    // 如果有子进程信号过来，回收， WNOHANG表示不阻塞
    // -1 表示等待第一个终止的子进程
    // 使用while的原因是，如果有多个进程死掉，同时发来SIGCHILD信号，只能处理一个。
    // waitpid的返回值：如果阻塞：错误返回0，否则返会子进程pid
    // 不阻塞的话，没有进程死掉，返回0，其他情况和阻塞一样
    while (waitpid(-1, 0, WNOHANG) > 0);
    return;
}

int main(int c, char **v) {
    int listener_fd = tcp_server_listen(SERV_PORT);
    // 注册子进程信号回收函数
    signal(SIGCHLD, sigchld_handler);
    while (1) {
        // 通用地址存储结构
        struct sockaddr_storage ss;
        socklen_t slen = sizeof(ss);
        int fd = accept(listener_fd, (struct sockaddr *) &ss, &slen);
        if (fd < 0) {
            error(1, errno, "accept failed");
            exit(1);
        }
        // 子进程
        if (fork() == 0) {
            // 关闭listener_fd
            close(listener_fd);
            child_run(fd);
            exit(0);
        } else {
            close(fd);
        }
    }

    return 0;
}