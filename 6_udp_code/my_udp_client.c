#include "../header/common.h"

#define NDG         2000
#define DGLEN       1400


int main(int argc, char* argv[]) {
  if(argc != 2) {
    printf("使用方法：./udpclient ${IPaddress}\n");
    exit(1);
  }
  int socket_fd;
  socket_fd = socket(AF_INET, SOCK_DGRAM, 0);

  struct sockaddr_in serv_addr;
  bzero(&serv_addr, sizeof(serv_addr));
  serv_addr.sin_family = AF_INET;
  serv_addr.sin_port = htons(SERV_PORT);
  // 我想下面最后那里这样写没问题？
  inet_pton(AF_INET, argv[1], &serv_addr.sin_addr.s_addr);

  socklen_t server_len = sizeof(serv_addr);

  struct sockaddr* reply_addr;
  reply_addr = malloc(server_len); // 分配空间

  char send_line[MAXLINE], recv_line[MAXLINE + 1];
  socklen_t len;
  int n;
  // fgets 和 fput 要换行符
  while(fgets(send_line, MAXLINE, stdin) != NULL) {
    int i = strlen(send_line);
    if(send_line[i - 1] == '\n') {
      send_line[i - 1] = 0; // 因为服务端自己加了换行符
    }
    printf("现在发送: %s\n", send_line);
    size_t ret = sendto(socket_fd, send_line, strlen(send_line), 0, (const struct sockaddr*)&serv_addr, server_len);
    if(ret < 0) {
      perror("发送失败");
      exit(1);
    }
    printf("发送了 %d 字节\n", ret);

    len = 0;
    n = recvfrom(socket_fd, recv_line, MAXLINE, 0, (struct sockaddr*)reply_addr, &len);

    if(n < 0) {
      perror("接收失败");
      exit(1);
    }
    recv_line[n] = 0;
    fputs(recv_line, stdout);
    fputs("\n", stdout);
  }
  exit(0);
}