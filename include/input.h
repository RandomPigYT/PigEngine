#ifndef PIG_INPUT_H
#define PIG_INPUT_H

#define GLFW_INCLUDE_NONE

#include <GLFW/glfw3.h>
#include <cglm/cglm.h>
#include <cglm/types.h>

#include "glad/glad.h"

extern vec2 mousePos;

void cursorPosCallback(GLFWwindow* window, double xpos, double ypos);
void keyCallback(GLFWwindow* window, int key, int scancode, int action,
                 int mods);
#endif  // PIG_INPUT_H
