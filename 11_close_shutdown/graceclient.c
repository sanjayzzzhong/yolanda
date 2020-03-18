# include "../header/common.h"

# define    MAXLINE     4096

int main(int argc, char **argv) {
    if (argc != 2) {
        perror("usage: graceclient <IPaddress>");
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

    char send_line[MAXLINE], recv_line[MAXLINE + 1];
    int n;

    // 读
    fd_set readmask;
    fd_set allreads;

    FD_ZERO(&allreads);
    // 设置监听0号fd
    FD_SET(0, &allreads);
    // 监听连接的socket fd
    FD_SET(socket_fd, &allreads);
    for (;;) {
        readmask = allreads;
        // 要将readmask拷贝到内核, select的第一个是maxfd1
        int rc = select(socket_fd + 1, &readmask, NULL, NULL, NULL);
        if (rc <= 0) {
            perror("select fail");
            exit(1);
        }
        // 只需判断两个
        if (FD_ISSET(socket_fd, &readmask)) {
            n = read(socket_fd, recv_line, MAXLINE);
            if (n < 0) {
                perror("read error");
                exit(1);
            } else if (n == 0) {
                printf("server teminated\n");
                exit(1);
            }
            // 将最后一个\n置为0
            recv_line[n] = 0;
            fputs(recv_line, stdout);
            fputs("\n", stdout);
        }
        // 检测标准输入是否准备好
        if (FD_ISSET(0, &readmask)) {
            if (fgets(send_line, MAXLINE, stdin) != NULL) {
                if (strncmp(send_line, "shutdown", 8) == 0) {
                    // 读取完之后，要把0清空，因为要关闭写方向
                    FD_CLR(0, &allreads);
                    // 关闭写方向
                    if (shutdown(socket_fd, 1) == -1) {
                        perror("shutdown failed");
                        exit(1);
                    }
                } else if (strncmp(send_line, "close", 5) == 0) {
                    FD_CLR(0, &allreads);
                    if (close(socket_fd)) {
                        perror("close failed");
                        exit(1);
                    }
                    sleep(6);
                    exit(0);
                } else {    // 如果不是上述两种关闭情况
                    int i = strlen(send_line);
                    if (send_line[i - 1] == '\n') {
                        send_line[i - 1] = 0;
                    }

                    printf("now sending %s\n", send_line);
                    size_t rt = write(socket_fd, send_line, strlen(send_line));
                    if (rt < 0) {
                        perror("write failed ");
                        exit(1);
                    }
                    printf("send bytes: %zu \n", rt);
                }

            }
        }

    }

}

