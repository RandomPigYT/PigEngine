#ifndef PIG_ENGINE_H
#define PIG_ENGINE_H

#define GLFW_INCLUDE_NONE
#define GL_GLEXT_PROTOTYPES

#include <GLFW/glfw3.h>
#include <cglm/cglm.h>

#include "glad/glad.h"
#include "render.h"

GLFWwindow *init(int w, int h, const char *title);

#endif  // PIG_ENGINE_H
