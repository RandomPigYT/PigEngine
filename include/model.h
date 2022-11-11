#ifndef PIG_MODEL_H
#define PIG_MODEL_H

#include <cglm/types.h>
#include <stddef.h>
#include <stdint.h>

#include "render.h"

int loadModel(const char* path, size_t* len);

#endif  // PIG_MODEL_H
