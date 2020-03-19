/*
 * @Author: Sanjay Zhong 
 * @Date: 2020-03-19 15:47:18 
 * @Last Modified by: Sanjay Zhong
 * @Last Modified time: 2020-03-19 16:12:24
 */
#ifndef __COMMON_H__
#define __COMMON_H__

#define     SERV_PORT       12345
#define     MAXLINE         4096

// 设置监听最大队列数
#define     LISTENQ         1024

#define     BUFFER_SIZE     4096

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <errno.h>
#include <poll.h>



#include <sys/un.h> // for sockaddr_un


#include "log.h"
#include "read.h"

int tcp_server_listen(int port) ;


#endif