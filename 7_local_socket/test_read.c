#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[]) {
  char buf[1024];
  bzero(buf, 1024);
  int n = 0;
  while((n = read(STDIN_FILENO, buf, 1024)) != 0) {
    write(STDOUT_FILENO, buf, n);
    printf("一共读取 %d 字节\n", n);
    bzero(buf, 1024);
  }

  return 0;
}