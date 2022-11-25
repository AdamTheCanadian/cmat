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

Vec3d Mat3d_GetCol(const Mat3d *mat,
                   int col) {
  assert(mat != NULL);
  assert(col < 3);
  assert(col >= 0);

  return (Vec3d) {
      .x = mat->mat[0 * 3 + col],
      .y = mat->mat[1 * 3 + col],
      .z = mat->mat[2 * 3 + col]
  };
}

Vec3d Mat3d_GetRow(const Mat3d *mat,
                   int row) {
  assert(mat != NULL);
  assert(row < 3);
  assert(row >= 0);

  return (Vec3d) {
      .x = mat->mat[row * 3 + 0],
      .y = mat->mat[row * 3 + 1],
      .z = mat->mat[row * 3 + 2]
  };
}

void Mat3d_SetRow(Mat3d *mat,
                  const Vec3d *rowVec,
                  int row) {
  assert(mat != NULL);
  assert(rowVec != NULL);
  assert(row < 3);
  assert(row >= 0);

  mat->mat[row * 3 + 0] = rowVec->x;
  mat->mat[row * 3 + 1] = rowVec->y;
  mat->mat[row * 3 + 2] = rowVec->z;
}

void Mat3d_SetCol(Mat3d *mat,
                  const Vec3d *colVec,
                  int col) {
  assert(mat != NULL);
  assert(colVec != NULL);
  assert(col < 3);
  assert(col >= 0);

  mat->mat[0 * 3 + col] = colVec->x;
  mat->mat[1 * 3 + col] = colVec->y;
  mat->mat[2 * 3 + col] = colVec->z;
}

void Mat3d_Scale(Mat3d *mat,
                 double scale) {
  assert(mat != NULL);
  for (int i = 0; i < MAT3D_SIZE; i++) {
    mat->mat[i] *= scale;
  }
}