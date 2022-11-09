#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "../include/PigEngine.h"
#include "../include/shader.h"

void framebuffer_size_callback(GLFWwindow *window, int width, int height) {
  glViewport(0, 0, width, height);
}

int main(void) {
  GLFWwindow *window = init(800, 600, "test");

  glViewport(0, 0, 800, 600);
  glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

  char buf[256];

  initShader("./shaders/vertex.vert", "./shaders/fragment.frag");

  printf("%s\n", buf);
  while (!glfwWindowShouldClose(window)) {
    glfwSwapBuffers(window);

    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    glfwPollEvents();
  }

  return 0;
}
