#include "../header/common.h"
#include "message_objecte.h"

#define    MAXLINE     4096
#define    KEEP_ALIVE_TIME  10
#define    KEEP_ALIVE_INTERVAL  3   // 间隔
#define    KEEP_ALIVE_PROBETIMES  3


int main(int argc, char **argv) {
    if (argc != 2) {
        printf("usage: tcpclient <IPaddress>\n");
        exit(1);
    }

    int socket_fd;
    socket_fd = socket(AF_INET, SOCK_STREAM, 0);

    struct sockaddr_in server_addr;
    bzero(&server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERV_PORT);
    inet_pton(AF_INET, argv[1], &server_addr.sin_addr);

    socklen_t server_len = sizeof(server_addr);
    int connect_rt = connect(socket_fd, (struct sockaddr *) &server_addr, server_len);
    if (connect_rt < 0) {
        perror("connect failed");
        exit(1);
    }

    char recv_line[MAXLINE + 1];
    int n;

    fd_set readmask;
    fd_set allreads;


    struct timeval tv;
    int heartbeats = 0;

    tv.tv_sec = KEEP_ALIVE_TIME;    // 10秒
    tv.tv_usec = 0;

    messageObject messageObject;

    FD_ZERO(&allreads);
    FD_SET(0, &allreads);
    FD_SET(socket_fd, &allreads);
    for (;;) {
        readmask = allreads;
        // 传入时间，如果在tv时间内没有收到信息，则返回0
        int rc = select(socket_fd + 1, &readmask, NULL, NULL, &tv);
        if (rc < 0) {
            perror("select failed");
            exit(1);
        }
        // 这里是保活的探测
        if (rc == 0) {
            if (++heartbeats > KEEP_ALIVE_PROBETIMES) {
                printf("connection dead\n");
                exit(1);
            }
            printf("sending heartbeat #%d\n", heartbeats);
            messageObject.type = htonl(MSG_PING);   // ping消息类型为1
            rc = send(socket_fd, (char *) &messageObject, sizeof(messageObject), 0);
            if (rc < 0) {
                perror("send failure");
                exit(1);
            }
            // 间隔三秒
            tv.tv_sec = KEEP_ALIVE_INTERVAL;
            continue;
        }
        if (FD_ISSET(socket_fd, &readmask)) {
            n = read(socket_fd, recv_line, MAXLINE);
            if (n < 0) {
                perror("read error");
                exit(1);
            } else if (n == 0) {
                printf("server terminated \n");
                exit(1);
            }
            printf("received heartbeat, make heartbeats to 0 \n");
            // 重置心跳
            heartbeats = 0;
            tv.tv_sec = KEEP_ALIVE_TIME;
        }
    }
}

