#ifndef CMAT_INCLUDE_CMAT_MAT3F_H_
#define CMAT_INCLUDE_CMAT_MAT3F_H_

#include "cmat/vec3f.h"

typedef struct Matrix3x3Float{
  float mat[9];
} Mat3f;

void Mat3f_SetZero(Mat3f *mat);

void Mat3f_SetIdentity(Mat3f* mat);

Mat3f Mat3f_MultiplyMat3f(const Mat3f* mat1,
                          const Mat3f* mat2);

Vec3f Mat3f_MultiplyVec3f(const Mat3f* mat,
                          const Vec3f* vec);

static inline float Mat3f_At(const Mat3f* mat,
                             int i,
                             int j) {
  return mat->mat[i * 3 + j];
}

static inline void Mat3f_Set(Mat3f* mat,
                             int i,
                             int j,
                             float value) {
  mat->mat[i * 3 + j] = value;
}

/**
 * \return The column vector (col) from a matrix (mat)
 */
Vec3f Mat3f_GetCol(const Mat3f *mat,
                   int col);

/**
 * \return The row vector (row) from a matrix (mat)
 */
Vec3f Mat3f_GetRow(const Mat3f *mat,
                   int row);

/**
 * Set the (row) of matrix (mat) from the vector (rowVec)
 */
void Mat3f_SetRow(Mat3f *mat,
                  const Vec3f *rowVec,
                  int row);

/**
 * Set the (col) of matrix (mat) from the vector (colVec)
 */
void Mat3f_SetCol(Mat3f *mat,
                  const Vec3f *colVec,
                  int col);
#endif
