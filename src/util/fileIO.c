#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

#include "../../include/util.h"

char *openFile(const char *path, size_t *len) {
  int fd = open(path, O_RDONLY, S_IRUSR | S_IWUSR);
  struct stat sb;

  if (fd == -1) {
    perror("couldn't open file\n");
    return NULL;
  }
  if (fstat(fd, &sb) == -1)  // Get file size
    perror("couldn't get file size\n");

  char *file = mmap(NULL, sb.st_size, PROT_READ, MAP_PRIVATE, fd, 0);

  close(fd);

  *len = sb.st_size;
  return file;
}

void unmapFile(const char *file, size_t len) { munmap((void *)file, len); }
