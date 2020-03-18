/*
 * @Author: Sanjay Zhong 
 * @Date: 2020-03-18 23:18:55 
 * @Last Modified by: Sanjay Zhong
 * @Last Modified time: 2020-03-18 23:21:36
 */
#include "common.h"

// 从一个fd中读入大小为size个字节到buffer中
size_t readn(int fd, void *buffer, size_t size) {
  char *buffer_pointer = buffer;
  int length = size;

  while (length > 0) {
    int result = read(fd, buffer_pointer, length);

    if (result < 0) {
      // 非阻塞情况会产生EINTR信号
      if (errno == EINTR)
        continue; /* 考虑非阻塞的情况，这里需要再次调用read */
      else
        return (-1);
    } else if (result == 0)
      break; /* EOF(End of File)表示套接字关闭 */

    length -= result;
    buffer_pointer += result;
  }
  return (size - length); /* 返回的是实际读取的字节数*/
}

size_t read_message(int fd, char *buffer, size_t length) {
  u_int32_t msg_length;
  u_int32_t msg_type;
  int rc;

  /* Retrieve the length of the record */

  rc = readn(fd, (char *)&msg_length, sizeof(u_int32_t));
  if (rc != sizeof(u_int32_t))
    return rc < 0 ? -1 : 0;
  msg_length = ntohl(msg_length);

  rc = readn(fd, (char *)&msg_type, sizeof(msg_type));
  // 这里并不判断是否类型是1，而是判断是否为4个字节
  if (rc != sizeof(u_int32_t))
    return rc < 0 ? -1 : 0;

  /* 判断buffer是否可以容纳下数据  */
  if (msg_length > length) {
    return -1;
  }

  /* Retrieve the record itself */
  rc = readn(fd, buffer, msg_length);
  if (rc != msg_length)
    return rc < 0 ? -1 : 0;
  return rc;
}