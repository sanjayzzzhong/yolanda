
#include "../header/common.h"

int main(int argc, char **argv) {
    if (argc != 2) {
        printf("usage: unixstreamclient <local_path>\n");
        exit(1);
    }

    int sockfd;
    struct sockaddr_un servaddr;

    sockfd = socket(AF_LOCAL, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket failed");
    }

    bzero(&servaddr, sizeof(servaddr));
    servaddr.sun_family = AF_LOCAL;
    // 同样是绑定 一个路径，文件名
    strcpy(servaddr.sun_path, argv[1]);

    if (connect(sockfd, (struct sockaddr *) &servaddr, sizeof(servaddr)) < 0) {
        perror("connect failed");
        exit(1);
    }

    char send_line[MAXLINE];
    bzero(send_line, MAXLINE);
    char recv_line[MAXLINE];

    // 同样， fgets会读取我们的换行符'\n'
    while (fgets(send_line, MAXLINE, stdin) != NULL) {

        int nbytes = sizeof(send_line);
        if (write(sockfd, send_line, nbytes) != nbytes) {
            printf("write error\n");
            exit(1);
        }

        if (read(sockfd, recv_line, MAXLINE) == 0) {
            printf("server terminated prematurely\n");
            exit(1);
        }

        fputs(recv_line, stdout);
    }

    exit(0);
}