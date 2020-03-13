#include "../header/common.h"


static int count;

static void recvfrom_int(int signo) {
  printf("\n共接收到了 %d 字节的数据报\n", count);
  exit(0);
}

int main(int argc, char* argv[]) {
  int socket_fd;
  socket_fd = socket(AF_INET, SOCK_DGRAM, 0); // 0 采用默认协议

  // 初始化地址
  struct sockaddr_in server_addr;
  bzero(&server_addr, sizeof(server_addr));
  server_addr.sin_family = AF_INET;
  server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
  server_addr.sin_port = htons(SERV_PORT);

  // 将socket与地址绑定
  bind(socket_fd, (struct sockaddr*)&server_addr, sizeof(server_addr));

  // 客户端地址
  socklen_t client_len;
  char message[MAXLINE];
  count = 0;

  signal(SIGINT, recvfrom_int); // 注册信号函数
  struct sockaddr_in client_addr;
  client_len = sizeof(client_addr);
  for(;;) {
    // 接收数据
    int n = recvfrom(socket_fd, message, MAXLINE, 0, (struct sockaddr*)&client_addr, &client_len);
    message[n] = 0; // 给最后一个加上终止符
    printf("接收到 %d 字节的数据: %s\n", n, message);

    char send_line[MAXLINE];
    sprintf(send_line, "你好， %s", message);

    // 这个客户端最后的长度不需要地址
    sendto(socket_fd, send_line, strlen(send_line), 0, (const struct sockaddr*)&client_addr, client_len);

    ++count; // 统计发送多少次
  }

}