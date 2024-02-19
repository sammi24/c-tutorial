#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

struct database_header_t
{
  unsigned short version;
  unsigned short employees;
  unsigned int filesize;
};

int main(int argc, char *argv[])
{
  if (argc != 2)
  {
    printf("Usage: %s <filename>\n", argv[0]);
    return 0;
  }

  int fd = open(argv[1], O_RDWR | O_CREAT, 0644);
  if (fd == -1)
  {
    perror("open");
    return -1;
  }

  char *mydata = "hello there file!\n";
  write(fd, mydata, strlen(mydata));

  close(fd);
  return 0;
}