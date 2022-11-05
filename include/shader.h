#ifndef PIG_SHADER_H
#define PIG_SHADER_H

#include <stdbool.h>
#include <stdint.h>

#include "glad/glad.h"

uint32_t initShader(const char *vertexPath, const char *fragmentPath);

void useShader();

// uniform utility funcs

void setBool(const char *uniformName, bool value);
void setInt(const char *uniformName, int value);
void setFloat(const char *uniformName, float value);

#endif  // PIG_SHADER_H
