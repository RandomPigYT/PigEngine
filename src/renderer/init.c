#include <stdio.h>
#include <stdlib.h>

#include "../../include/PigEngine.h"

GLFWwindow *init(int w, int h, const char *title) {
  glfwInit();

  // Set version and profile

  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 5);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

  // Initialize the window

  GLFWwindow *window = glfwCreateWindow(w, h, title, NULL, NULL);

  if (window == NULL) {
    fprintf(stderr, "Failed to create window\n");
    glfwTerminate();

    exit(EXIT_FAILURE);
  }

  glfwMakeContextCurrent(window);

  // Initialize glad

  if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
    fprintf(stderr, "Failed to initialize glad\n");
    glfwTerminate();

    exit(EXIT_FAILURE);
  }

  glViewport(0, 0, w, h);
	
	
	glfwSwapInterval(1);

  return window;
}
