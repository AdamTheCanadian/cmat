#ifndef CMAT_INCLUDE_CMAT_MAT4F_H_
#define CMAT_INCLUDE_CMAT_MAT4F_H_

#include <stdbool.h>
#include <stdint.h>

/**
 * @brief A 4x4 matrix of floats
 * Row major ordering is used
 */
typedef struct Matrix4x4Float{
  float mat[16];
} Mat4f;

/**
 * @brief Set all elements to 0
 */
void Mat4f_SetZero(Mat4f* mat);

/**
 * @brief Set matrix to identity
 */
void Mat4f_SetIdentity(Mat4f* mat);

/**
 * Multiply a mat4f with another mat4f
 * Compute mat1 * mat2;
 * Note remember mat1 * mat2 DOES NOT equal mat2 * mat1, so order matters
 * @return mat1 * mat2
 */
Mat4f Mat4f_MultiplyMat4f(const Mat4f* mat1,
                         const Mat4f* mat2);

/**
 * @brief Accessor given a row (i) and column (j) index
 * 
 * @return float matrix value at [i][j]
 */
static inline float Mat4f_At(const Mat4f* mat, 
                             int i,
                             int j) {
  return mat->mat[i * 4 + j];
}

/**
 * Set the value of a matrix at index (i, j)
 */
static inline void Mat4f_Set(Mat4f* mat,
                             int i,
                             int j,
                             float value) {
  mat->mat[i * 4 + j] = value;
}

#endif