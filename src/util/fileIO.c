#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

#include "../../include/util.h"

char *openFile(const char *path) {
  int fd = open(path, O_RDONLY, S_IRUSR | S_IWUSR);
  struct stat sb;

  if (fd == -1) {
    perror("couldn't open file\n");
    return NULL;
  }
  if (fstat(fd, &sb) == -1)  // Get file size
    perror("couldn't get file size\n");

  char *file = malloc(sb.st_size + 1);

  read(fd, file, sb.st_size);
  file[sb.st_size] = 0;  // NULL terminating

  close(fd);

  return file;
}
