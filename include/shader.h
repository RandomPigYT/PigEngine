#ifndef PIG_SHADER_H
#define PIG_SHADER_H

#include <stdbool.h>
#include <stdint.h>

#include "glad/glad.h"

uint32_t initShader(const char *vertexPath, const char *fragmentPath);

void useShader(uint32_t id);

// uniform utility funcs

void setBool(uint32_t id, const char *uniformName, bool value);
void setInt(uint32_t id, const char *uniformName, int value);
void setFloat(uint32_t id, const char *uniformName, float value);

#endif  // PIG_SHADER_H
