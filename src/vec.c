#include "cmat/vec.h"

Vec3f Vec3d_ToVec3f(const Vec3d *vec) {
  return (Vec3f){
    .x = (float)vec->x,
    .y = (float)vec->y,
    .z = (float)vec->z
  };
}

Vec3d Vec3f_ToVec3d(const Vec3f *vec) {
  return (Vec3d){
      .x = vec->x,
      .y = vec->y,
      .z = vec->z
  };
}