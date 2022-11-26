#ifndef PIG_RENDER_H
#define PIG_RENDER_H

#define GLFW_INCLUDE_NONE

#include <GLFW/glfw3.h>
#include <cglm/cglm.h>
#include <cglm/types.h>
#include <stdint.h>

#include "glad/glad.h"

struct vertex_s {
  vec3 position;
  vec3 normal;
  vec3 textureCoords;
};

struct texture_s {};

struct mesh_s {
  struct vertex_s* vertices;
  struct texture_s* textures;
  uint32_t indices;

  uint32_t numVertices;
  uint32_t numIndices;
  uint32_t numTextures;

  vec3 pos;
  vec3 rotation;
  vec3 scale;

  mat4 transformMatrix;

  uint32_t vao, vbo, ebo;
};

struct model_s {
  struct mesh_s* meshes;
  uint32_t numMeshes;

  vec3 pos;
  vec3 rotation;
  vec3 scale;

  mat4 transformMatrix;
};

#endif  // PIG_RENDER_H
