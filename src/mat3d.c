#include "cmat/mat3d.h"
#include <assert.h>
#include <stdlib.h>

static const int MAT3D_SIZE = 9;

void Mat3d_SetZero(Mat3d *mat) {
  assert(mat != NULL);
  for (int i = 0; i < MAT3D_SIZE; i++) {
    mat->mat[i] = 0;
  }
}