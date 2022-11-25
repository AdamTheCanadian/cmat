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
Vec3d Mat3d_GetCol(const Mat3d *mat,
                   int col);

/**
 * \return The row vector (row) from a matrix (mat)
 */
Vec3d Mat3d_GetRow(const Mat3d *mat,
                   int row);

/**
 * Set the (row) of matrix (mat) from the vector (rowVec)
 */
void Mat3d_SetRow(Mat3d *mat,
                  const Vec3d *rowVec,
                  int row);

/**
 * Set the (col) of matrix (mat) from the vector (colVec)
 */
void Mat3d_SetCol(Mat3d *mat,
                  const Vec3d *colVec,
                  int col);

/**
 * Compute mat * scale, modifies mat in place
 */
void Mat3d_Scale(Mat3d *mat,
                 double scale);
#endif
