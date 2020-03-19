/*
 * @Author: Sanjay Zhong 
 * @Date: 2020-03-19 15:56:00 
 * @Last Modified by: Sanjay Zhong
 * @Last Modified time: 2020-03-19 16:00:14
 */
#include "common.h"

int tcp_server_listen(int port) {
  int listenfd;
  listenfd = socket(AF_INET, SOCK_STREAM, 0);

  struct sockaddr_in server_addr;
  bzero(&server_addr, sizeof(server_addr));
  server_addr.sin_family = AF_INET;
  server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
  server_addr.sin_port = htons(port);

  int on = 1;
  setsockopt(listenfd, SOL_SOCKET, SO_REUSEADDR, &on, sizeof(on));

  int rt1 = bind(listenfd, (struct sockaddr *)&server_addr, sizeof(server_addr));
  if (rt1 < 0) {
    error(1, errno, "bind failed ");
  }

  int rt2 = listen(listenfd, LISTENQ);
  if (rt2 < 0) {
    error(1, errno, "listen failed ");
  }

  signal(SIGPIPE, SIG_IGN);

  return listenfd;
}