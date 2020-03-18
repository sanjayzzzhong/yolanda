#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[]) {
  char buf[1024];
  bzero(buf, 1024);
  int n = 0;
  while((n = read(STDIN_FILENO, buf, 1024)) != 0) {
    buf[n - 1] = 0;
    int rt = write(STDOUT_FILENO, buf, strlen(buf));
    printf("一共读取 %d 字节\n", n);
    printf("一共写入 %d 字节\n", rt);
    bzero(buf, 1024);
  }

  return 0;
}