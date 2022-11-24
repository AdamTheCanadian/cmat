#ifndef CMAT_INCLUDE_CMAT_MAT3D_H_
#define CMAT_INCLUDE_CMAT_MAT3D_H_

#include "cmat/vec3d.h"

typedef struct Matrix3x3Double {
  double mat[9];
} Mat3d;

void Mat3d_SetZero(Mat3d *mat);


/**
 * \return The column vector (col) from a matrix (mat)
 */
Vec3d Vec3d_GetCol(const Vec3d *mat,
                   int col);

/**
 * \return The row vector (row) from a matrix (mat)
 */
Vec3d Vec3d_GetRow(const Vec3d *mat,
                   int row);

/**
 * Set the (row) of matrix (mat) from the vector (rowVec)
 */
void Vec3d_SetRow(Vec3d *mat,
                  const Vec3d *rowVec,
                  int row);

/**
 * Set the (col) of matrix (mat) from the vector (colVec)
 */
void Vec3d_SetCol(Vec3d *mat,
                  const Vec3d *colVec,
                  int col);
#endif
