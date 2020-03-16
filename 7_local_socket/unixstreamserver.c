#include  "../header/common.h"


int main(int argc, char **argv) {
    if (argc != 2) {
        printf("usage: unixstreamserver <local_path>\n");
        exit(1);
    }

    int listenfd, connfd;
    socklen_t clilen;
    struct sockaddr_un cliaddr, servaddr;

    // 使用AF_LOCAL 代表本地套接字协议
    listenfd = socket(AF_LOCAL, SOCK_STREAM, 0);
    if (listenfd < 0) {
        perror("socket create failed");
        exit(1);
    }

    // 绑定一个本地文件
    char *local_path = argv[1];
    unlink(local_path);
    bzero(&servaddr, sizeof(servaddr));
    servaddr.sun_family = AF_LOCAL;
    // 把本地路径绑定到servaddr.sun_path
    strcpy(servaddr.sun_path, local_path);

    if (bind(listenfd, (struct sockaddr *) &servaddr, sizeof(servaddr)) < 0) {
        perror("bind failed");
        exit(1);
    }

    if (listen(listenfd, LISTENQ) < 0) {
        perror("listen failed");
    }

    clilen = sizeof(cliaddr);
    if ((connfd = accept(listenfd, (struct sockaddr *) &cliaddr, &clilen)) < 0) {
        perror("accept failed");
        exit(1);
    }

    char buf[BUFFER_SIZE];

    while (1) {
        bzero(buf, sizeof(buf));
        if (read(connfd, buf, BUFFER_SIZE) == 0) {
            printf("client quit\n");
            break;
        }
        printf("Receive: %s", buf); // read读进来的buf包含换行符'\n'!!! 不包含'\0'

        char send_line[MAXLINE];
        sprintf(send_line, "Hi, %s", buf);

        int nbytes = sizeof(send_line);

        if (write(connfd, send_line, nbytes) != nbytes){
            perror("write error");
            exit(1);
        }
    }

    // 关闭监听套接字和连接套接字
    close(listenfd);
    close(connfd);

    exit(0);

}
