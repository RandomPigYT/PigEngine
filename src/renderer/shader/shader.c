#include "../../../include/shader.h"

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "../../../include/PigEngine.h"
#include "../../../include/util.h"

uint32_t initShader(const char *vertexPath, const char *fragmentPath) {
  // Read in the code

  char *vertexCode = openFile(vertexPath);
  char *fragmentCode = openFile(fragmentPath);

  if (vertexCode == NULL) {
    fprintf(stderr, "Failed to read vertex shader file");
    exit(EXIT_FAILURE);
  }

  if (fragmentCode == NULL) {
    fprintf(stderr, "Failed to read fragment shader file");
    exit(EXIT_FAILURE);
  }

  // Compile shaders

  uint32_t vertex, fragment;
  int success;
  char infolog[512];

  // Vertex shader

  vertex = glCreateShader(GL_VERTEX_SHADER);
  glShaderSource(vertex, 1, (const char *const *)&vertexCode, NULL);
  glCompileShader(vertex);

  // Error checking

  glGetShaderiv(vertex, GL_COMPILE_STATUS, &success);
  if (!success) {
    glGetShaderInfoLog(vertex, 512, NULL, infolog);
    fprintf(stderr, "vertex shader compilation failed\n%s\n", infolog);

    exit(EXIT_FAILURE);
  }

  // Fragment shader

  fragment = glCreateShader(GL_FRAGMENT_SHADER);
  glShaderSource(fragment, 1, (const char *const *)&fragmentCode, NULL);
  glCompileShader(fragment);

  // Error checking

  glGetShaderiv(fragment, GL_COMPILE_STATUS, &success);
  if (!success) {
    glGetShaderInfoLog(fragment, 512, NULL, infolog);
    fprintf(stderr, "fragment shader compilation failed\n%s\n", infolog);

    exit(EXIT_FAILURE);
  }

  // Shader program

  uint32_t id;

  id = glCreateProgram();
  glAttachShader(id, vertex);
  glAttachShader(id, fragment);

  glLinkProgram(id);

  // Error checking

  glGetProgramiv(id, GL_LINK_STATUS, &success);
  if (!success) {
    glGetProgramInfoLog(id, 512, NULL, infolog);
    fprintf(stderr, "Shader program linking failed\n%s\n", infolog);

    exit(EXIT_FAILURE);
  }

  glDeleteShader(vertex);
  glDeleteShader(fragment);

  free(vertexCode);
  free(fragmentCode);

  return id;
}

void useShader(uint32_t id) { glUseProgram(id); }

void setBool(uint32_t id, const char *uniformName, bool value) {
  glUniform1i(glGetUniformLocation(id, uniformName), (int)value);
}

void setInt(uint32_t id, const char *uniformName, int value) {
  glUniform1i(glGetUniformLocation(id, uniformName), value);
}

void setFloat(uint32_t id, const char *uniformName, float value) {
  glUniform1f(glGetUniformLocation(id, uniformName), value);
}
