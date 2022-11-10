#ifndef PIG_RENDER_H
#define PIG_RENDER_H

#define GLFW_INCLUDE_NONE

#include <GLFW/glfw3.h>
#include <cglm/cglm.h>
#include <cglm/types.h>
#include <stddef.h>
#include <stdint.h>

#include "glad/glad.h"
#include "util.h"

typedef struct {

  vec3 pos;
  vec3 normals;
  vec3 texCoords;

} Vertex;

typedef struct {

  uint32_t id;
  char* type;

} Texture;

typedef struct {

  vec3 ambient;
  vec3 diffuse;
  vec3 specular;
  float shininess;

} Material;

typedef struct {

  Vertex* vertices;
  uint32_t* indices;
  // Texture* textures;
	
	size_t numVertices;
	size_t numIndices;
	// size_t numTextures;
	
	vec3 pos;
	vec3 rotation;
	float scale;

  Material material;
  uint32_t shader;

	uint32_t vao, vbo, ebo;

} Mesh;


typedef struct {

	Mesh* meshes;
	Capacity meshCapacity;
	
	vec3 pos;
	vec3 rotation;
	vec3 centre;
	float scale;

}	Object;


typedef struct {

	vec3 pos;
	vec3 colour;

}	Light;

typedef struct {

	vec3 pos;
	vec3 target;

	vec3 Direction;
	vec3 up;
	vec3 right;


}	Camera;

typedef struct {

	uint32_t id;

	Object* objects;
	Capacity objectCapacity;

	Light* lights;
	Capacity lightCapacity;

	Camera camera;


}	Scene;


extern uint32_t* shaders;
extern Capacity shaderCapacity;

extern Scene* scenes;
extern Capacity sceneCapacity;


uint32_t createScene();
void createMesh(Mesh mesh, Scene scene);
void createLight(vec3 pos, vec3 colour, Scene scene);
uint32_t renderScene(uint32_t id);



#endif  // PIG_RENDER_H
