#include "cmat/mat3f.h"
#include <assert.h>
#include <stdlib.h>

static const int MAT3F_SIZE = 9;

void Mat3f_SetZero(Mat3f *mat) {
  assert(mat != NULL);
  for (int i = 0; i < MAT3F_SIZE; i++) {
    mat->mat[i] = 0.0f;
  }
}

void Mat3f_SetIdentity(Mat3f* mat) {
  assert(mat != NULL);
  Mat3f_SetZero(mat);
  mat->mat[0] = 1.0f;
  mat->mat[4] = 1.0f;
  mat->mat[8] = 1.0f;
}

Mat3f Mat3f_MultiplyMat3f(const Mat3f* mat1,
                          const Mat3f* mat2) {
  assert(mat1 != NULL);
  assert(mat2 != NULL);
  Mat3f return_mat;
  Mat3f_SetZero(&return_mat);
  for (int i = 0; i < 3; i++) {
    for (int k = 0; k < 3; k++) {
      for (int j = 0; j < 3; j++) {
        return_mat.mat[i * 3 + j] += mat1->mat[i * 3 + k] * mat2->mat[k * 3 + j];
      }
    }
  }
  return return_mat;
}

Vec3f Mat3f_MultiplyVec3f(const Mat3f* mat,
                          const Vec3f* vec) {
  assert(mat != NULL);
  assert(vec != NULL);
  Vec3f return_vec;
  return_vec.x = mat->mat[0] * vec->vec[0] + mat->mat[1] * vec->vec[1] + mat->mat[2] * vec->vec[2];
  return_vec.y = mat->mat[3] * vec->vec[0] + mat->mat[4] * vec->vec[1] + mat->mat[5] * vec->vec[2];
  return_vec.z = mat->mat[6] * vec->vec[0] + mat->mat[7] * vec->vec[1] + mat->mat[8] * vec->vec[2];

  return return_vec;
}

Vec3f Mat3f_GetCol(const Mat3f *mat,
                   int col) {
  assert(mat != NULL);
  assert(col < 3);
  assert(col >= 0);

  return (Vec3f) {
    .x = mat->mat[0 * 3 + col],
    .y = mat->mat[1 * 3 + col],
    .z = mat->mat[2 * 3 + col]
  };
}

Vec3f Mat3f_GetRow(const Mat3f *mat,
                   int row) {
  assert(mat != NULL);
  assert(row < 3);
  assert(row >= 0);

  return (Vec3f) {
      .x = mat->mat[row * 3 + 0],
      .y = mat->mat[row * 3 + 1],
      .z = mat->mat[row * 3 + 2]
  };
}