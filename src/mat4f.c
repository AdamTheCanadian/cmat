#include "cmat/mat4f.h"
#include <assert.h>
#include <stdlib.h>
#include <math.h>

/* Matrix layout for row major ordering
 * Just a helper comment to remember the indices of a 4x4 matrix
 *
 *  0  1  2  3
 *  4  5  6  7
 *  8  9 10 11
 * 12 13 14 15
 */

static const int MAT4F_SIZE = 16;

void Mat4f_SetZero(Mat4f* mat) {
  assert(mat != NULL);
  for (int i = 0; i < MAT4F_SIZE; i++) {
    mat->mat[i] = 0.0f;
  }
}

void Mat4f_SetIdentity(Mat4f* mat) {
  assert(mat != NULL);
  Mat4f_SetZero(mat);
  mat->mat[0] = 1.0f;
  mat->mat[5] = 1.0f;
  mat->mat[10] = 1.0f;
  mat->mat[15] = 1.0f;
}

Mat4f Mat4f_MultiplyMat4f(const Mat4f* mat1,
                          const Mat4f* mat2) {
  assert(mat1 != NULL);
  assert(mat2 != NULL);
  Mat4f return_mat;
  Mat4f_SetZero(&return_mat);
  for (int i = 0; i < 4; i++) {
    for (int k = 0; k < 4; k++) {
      for (int j = 0; j < 4; j++) {
        return_mat.mat[i * 4 + j] += mat1->mat[i * 4 + k] * mat2->mat[k * 4 + j];
      }
    }
  }
  return return_mat;
}
