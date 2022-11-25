#include "cmat/vec3d.h"
#include <assert.h>
#include <stdlib.h>

void Vec3d_SetZero(Vec3d *vec) {
  assert(vec != NULL);
  vec->x = 0;
  vec->y = 0;
  vec->z = 0;
}

void Vec3d_Scale(Vec3d *vec,
                 double scale) {
  assert(vec != NULL);
  vec->x *= scale;
  vec->y *= scale;
  vec->z *= scale;
}