#include <cglm/types.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <cglm/cglm.h>

#define FAST_OBJ_IMPLEMENTATION

#include "../../include/fast_obj.h"
#include "../../include/model.h"
#include "../../include/util.h"


void initModel(struct model_s* model, fastObjMesh* modelData){
	model->numMeshes = modelData->object_count + modelData->group_count;
	model->meshes = malloc(model->numMeshes * sizeof(struct mesh_s));
	
	
	for (int i = 0; i < 3; i++){

		model->pos[i] = 0;
		model->rotation[i] = 0;
		model->scale[i] = 1;
	}

	glm_mat4_identity(model->transformMatrix);
}


struct mesh_s generateMesh(fastObjMesh* modelData, fastObjGroup* group){
	struct mesh_s mesh;
	
	// TODO: Generate mesh from mesh data
	
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
	for (int i = 0; i < modelData->object_count; i++){

		model.meshes[meshIndex] = generateMesh(modelData, &modelData->objects[i]);
		meshIndex++;
	}
	
	// Load groups
	for (int i = 0; i < modelData->group_count; i++){

		model.meshes[meshIndex] = generateMesh(modelData, &modelData->groups[i]);
		meshIndex++;
	}
	

  fast_obj_destroy(modelData);

  return 0;
}
