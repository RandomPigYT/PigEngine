#ifndef PIG_UTIL_H
#define PIG_UTIL_H

#include <stddef.h>
#include <stdint.h>

struct capacity {
  size_t size;
  size_t capacity;
};

char *openFile(const char *path);

#endif  // PIG_UTIL_H
