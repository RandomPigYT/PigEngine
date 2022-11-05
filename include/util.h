#ifndef PIG_UTIL_H
#define PIG_UTIL_H

#include <stddef.h>

// Returns pointer with mapped file and store file size in len
char *openFile(const char *path, size_t *len);

// Unmaps file
void unmapFile(const char *file, size_t len);

#endif  // PIG_UTIL_H
