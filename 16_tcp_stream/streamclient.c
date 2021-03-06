/*
 * @Author: Sanjay Zhong 
 * @Date: 2020-03-18 22:30:00 
 * @Last Modified by:   Sanjay Zhong 
 * @Last Modified time: 2020-03-18 22:30:00 
 */

#include "../header/common.h"

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
        perror("connect failed ");
        exit(1);
    }

    struct {
        u_int32_t message_length;
        u_int32_t message_type;
        char data[128];
    } message;


    int n;

    while (fgets(message.data, sizeof(message.data), stdin) != NULL) {
        n = strlen(message.data);
        message.message_length = htonl(n);
        // 这里也转为网络字节序把？
        message.message_type = 1;
        if (send(socket_fd, (char *) &message, sizeof(message.message_length) + sizeof(message.message_type) + n, 0) <
            0) {
                perror("send error");
                exit(1);
            }
    }
    exit(0);
}

