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



#include <sys/un.h> // for sockaddr_un


#include "log.h"
#include "read.h"

#endif