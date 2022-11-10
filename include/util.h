#ifndef PIG_UTIL_H
#define PIG_UTIL_H

#include <stddef.h>
#include <stdint.h>

typedef struct {

	size_t size;
	size_t capacity;

} Capacity;



char *openFile(const char *path);


#endif  // PIG_UTIL_H
