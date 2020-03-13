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
  bzeor(&serv_addr, sizeof(serv_addr));
  serv_addr.sin_family = AF_INET;
  serv_addr.sin_port = htons(SERV_PORT);
  inet_pton(AF_INET, argv[1], &serv_addr.sin_addr);
}