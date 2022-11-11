#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TINYOBJ_LOADER_C_IMPLEMENTATION

#include "../include/model.h"
#include "../include/tinyobj_loader_c.h"
#include "../include/util.h"

void getFileData(void* ctx, const char* file, const int is_mtl,
                 const char* objFilename, char** data, size_t* len) {
  void** temp = ctx;

  if (!file) {
    fprintf(stderr, "null filepath\n");
    *data = NULL;
    *len = 0;

    return;
  }

  *data = openFile(file);

  if (!*data) {
    fprintf(stderr, "file does not exist: \"%s\"\n", file);
    *data = NULL;
    *len = 0;
    *temp = NULL;
    return;
  }

  *len = strlen(*data);

  // So that memory can be freed
  *temp = *data;
}

int loadModel(const char* path, size_t* len) {
  tinyobj_attrib_t attrib;
  tinyobj_shape_t* shapes = NULL;
  size_t numShapes;
  tinyobj_material_t* materials = NULL;
  size_t numMaterials;

  void* dataPtr;

  uint32_t flags = TINYOBJ_FLAG_TRIANGULATE;

  int32_t status =
      tinyobj_parse_obj(&attrib, &shapes, &numShapes, &materials, &numMaterials,
                        path, getFileData, &dataPtr, flags);

  if (status != TINYOBJ_SUCCESS) {
    if (dataPtr) free(dataPtr);

    return -1;
  }

  for (int i = 0; i < attrib.num_vertices; i += 3) {
    for (int j = 0; j < 3; j++) {
      printf("%f ", attrib.vertices[i + j]);
    }

    printf("\n");
  }

  // Free openFile
  if (dataPtr) free(dataPtr);

  return 0;
}
