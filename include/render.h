#ifndef PIG_RENDER_H
#define PIG_RENDER_H

#define GLFW_INCLUDE_NONE

#include <GLFW/glfw3.h>
#include <cglm/cglm.h>
#include <cglm/types.h>
#include <stdint.h>

#include "glad/glad.h"

struct vertex {
  vec3 position;
  vec3 normal;
  vec3 textureCoords;
};

struct texture {};

struct mesh {
  struct vertex* vertices;
  struct texture* textures;
  uint32_t indices;

  uint32_t numVertices;
  uint32_t numIndices;
  uint32_t numTextures;

  uint32_t vao, vbo, ebo;
};

struct model {
  struct mesh* meshes;
  uint32_t numMeshes;
};

#endif  // PIG_RENDER_H
