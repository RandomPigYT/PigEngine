#include <cglm/cglm.h>
#include <cglm/types.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define FAST_OBJ_IMPLEMENTATION

#include "../../include/fast_obj.h"
#include "../../include/model.h"
#include "../../include/util.h"

void initModel(struct model_s* model, fastObjMesh* modelData) {
  model->numMeshes = modelData->object_count + modelData->group_count;
  model->meshes = malloc(model->numMeshes * sizeof(struct mesh_s));

	assert(model->meshes && "Failed to allocate memory to model->meshes");
	printf("Hello\n");

  for (int i = 0; i < 3; i++) {
    model->pos[i] = 0;
    model->rotation[i] = 0;
    model->scale[i] = 1;
  }

  glm_mat4_identity(model->transformMatrix);
}


int64_t vertexExists(struct vertex_s* vertex, struct vertex_s* vertices, size_t len){
	
	for (int i = 0; i < len; i++){
		bool result = true;
		
		// Checks if all the vertex attributes are equal
		for (int j = 0; j < 3; j++){
			result = result && (vertex->position[j] && vertices[i].position[j]);
			result = result && (vertex->normal[j] && vertices[i].normal[j]);
			result = result && (vertex->textureCoords[j] && vertices[i].textureCoords[j]);
		}
	
		if(result)
			return i;	// Returns the index
	}

		

	return -1;
}


struct mesh_s generateMesh(fastObjMesh* modelData, fastObjGroup* group) {
  struct mesh_s mesh;
	
	struct vertex_s* vertices = malloc(modelData->position_count * sizeof(struct vertex_s));
	size_t vertexCount = 0;

	uint32_t* indices = malloc(modelData->face_count * 3 * sizeof(uint32_t));
	size_t indexCount = 0;

	assert(vertices && "Failed to allocate memory to vertices");

	printf("%d\n", group->index_offset);
	
	for (int i = 0; i < group->face_count; i++) {
		struct vertex_s temp;
		
  	for (int j = 0; j < 3; j++) {

  		temp.position[j] = modelData->positions[modelData->indices[(3 * i) + group->index_offset + j].p];
  		temp.normal[j] = modelData->normals[modelData->indices[(3 * i) + group->index_offset + j].n];
  		temp.textureCoords[j] = modelData->texcoords[modelData->indices[(3 * i) + group->index_offset + j].t];
  	}
		
		int64_t index = vertexExists(&temp, vertices, vertexCount);
		
		// Only add new vertex if vertex doesn't already exist
		if(index == -1){
			vertices[vertexCount] = temp;
			indices[indexCount] = vertexCount;
			
			vertexCount++;
			indexCount++;
		}

		else {
			indices[indexCount] = index;

			indexCount++;
		}
	}
	
	mesh.vertices = vertices;
	mesh.indices = indices;

	mesh.numVertices = vertexCount;
	mesh.numIndices = vertexCount;

	// TODO: Init mesh

  return mesh;
}

int loadModel(const char* path, size_t* len) {
  fastObjMesh* modelData = fast_obj_read(path);

  if (!modelData) {
    fprintf(stderr, "Failed to load model %s\n", path);
    return -1;
  }

  struct model_s model;
  initModel(&model, modelData);

  int meshIndex = 0;

  // Load objects
  for (int i = 0; i < modelData->object_count; i++) {
    model.meshes[meshIndex] = generateMesh(modelData, &modelData->objects[i]);
    meshIndex++;
  }

  // Load groups
  for (int i = 0; i < modelData->group_count; i++) {
    model.meshes[meshIndex] = generateMesh(modelData, &modelData->groups[i]);
    meshIndex++;
  }

  fast_obj_destroy(modelData);

  return 0;
}
