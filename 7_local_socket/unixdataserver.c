//
// Created by shengym on 2019-07-15.
//

#include  "../header/common.h"


int main(int argc, char **argv) {
    if (argc != 2) {
        perror("usage: unixdataserver <local_path>");
        exit(1);
    }

    int socket_fd;
    socket_fd = socket(AF_LOCAL, SOCK_DGRAM, 0);
    if (socket_fd < 0) {
        perror("socket create failed");
        exit(1);
    }

    struct sockaddr_un servaddr;
    char *local_path = argv[1];
    unlink(local_path);
    bzero(&servaddr, sizeof(servaddr));
    servaddr.sun_family = AF_LOCAL;
    strcpy(servaddr.sun_path, local_path);

    if (bind(socket_fd, (struct sockaddr *) &servaddr, sizeof(servaddr)) < 0) {
        perror("bind failed");
        exit(1);
    }

    char buf[BUFFER_SIZE];

    struct sockaddr_un client_addr;
    socklen_t client_len = sizeof(client_addr);
    while (1) {
        bzero(buf, sizeof(buf));
        // 只有客户端发送eof信号，接收到的才是0；否则阻塞
        if (recvfrom(socket_fd, buf, BUFFER_SIZE, 0, (struct sockaddr *) &client_addr, &client_len) == 0) {
            printf("client quit");
            break;
        }
        printf("Receive: %s \n", buf);

        char send_line[MAXLINE];
        bzero(send_line, MAXLINE);
        sprintf(send_line, "Hi, %s", buf);

        size_t nbytes = strlen(send_line);
        printf("now sending: %s \n", send_line);

        if (sendto(socket_fd, send_line, nbytes, 0, (struct sockaddr *) &client_addr, client_len) != nbytes) {
            perror("sendto error");
            exit(1);
        }
    }

    close(socket_fd);

    exit(0);

}