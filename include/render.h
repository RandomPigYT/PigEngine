#ifndef PIG_RENDER_H
#define PIG_RENDER_H

#define GLFW_INCLUDE_NONE

#include <GLFW/glfw3.h>
#include <stddef.h>

#include "glad/glad.h"


typedef struct {
	
	float* buffer;
	uint64_t* attributes;
	uint64_t* indices;
	
	uint64_t numAttributes;
	uint64_t numIndices;

} Body;




#endif // PIG_RENDER_H
