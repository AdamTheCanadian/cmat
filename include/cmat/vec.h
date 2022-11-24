#ifndef CMAT_INCLUDE_CMAT_VEC_H_
#define CMAT_INCLUDE_CMAT_VEC_H_

/**
 * File to provide vector functionality.
 * For example conversion between vector types. Did not want to put conversions of Vec3f to Vec3d
 * in one those. Will introduce circular dependencies. Vec3f needs Vec3d to convert, and likewise Vec3d
 * needs Vec3f to do the reverse conversion
 */

#include "cmat/vec3d.h"
#include "cmat/vec3f.h"

Vec3f Vec3d_ToVec3f(const Vec3d *vec);

Vec3d Vec3f_ToVec3d(const Vec3f *vec);

#endif
