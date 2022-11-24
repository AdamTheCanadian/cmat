#include "cmat/vec3f.h"
#include <math.h>

/* Threshold epislon value for comparing two floats together */
static const float EPSILON_FLOAT = 1.0e-5f;

void Vec3f_SetZero(Vec3f* vec) {
  vec->vec[0] = 0.0f;
  vec->vec[1] = 0.0f;
  vec->vec[2] = 0.0f;
}

Vec3f Vec3f_SubtractVec3f(const Vec3f* vec1,
                          const Vec3f* vec2) {
  return (Vec3f) {
    .x = vec1->x - vec2->x,
    .y = vec1->y - vec2->y,
    .z = vec1->z - vec2->z
  };
}

float Vec3f_Length(const Vec3f* vec) {
  return sqrtf(vec->x * vec->x + vec->y * vec->y + vec->z * vec->z);
}

void Vec3f_Normalize(Vec3f* vec) {
  float length = Vec3f_Length(vec);
  /* Length is 0 (or near 0), so dont do anything */
  if (length < EPSILON_FLOAT) {
    return;
  }
  vec->vec[0] /= length;
  vec->vec[1] /= length;
  vec->vec[2] /= length;
}

Vec3f Vec3f_Cross(const Vec3f* vec1,
                  const Vec3f* vec2) {
  Vec3f cross;
  cross.vec[0] = vec1->vec[1] * vec2->vec[2] - vec1->vec[2] * vec2->vec[1];
  cross.vec[1] = vec1->vec[2] * vec2->vec[0] - vec1->vec[0] * vec2->vec[2];
  cross.vec[2] = vec1->vec[0] * vec2->vec[1] - vec1->vec[1] * vec2->vec[0];
  return cross;
}


float Vec3f_DotProduct(const Vec3f* vec1,
                       const Vec3f* vec2) {
  return vec1->x * vec2->x + vec1->y * vec2->y + vec1->z * vec2->z;
}

bool Vec3f_IsEqual(const Vec3f* vec1,
                   const Vec3f* vec2) {
  const float diff_x = fabsf(vec1->x - vec2->x);
  const float diff_y = fabsf(vec1->y - vec2->y);
  const float diff_z = fabsf(vec1->z - vec2->z);
  return diff_x < EPSILON_FLOAT && diff_y < EPSILON_FLOAT && diff_z < EPSILON_FLOAT;
}

void Vec3f_Copy(const Vec3f* vec1,
                Vec3f* vec2) {
  vec2->x = vec1->x;
  vec2->y = vec1->y;
  vec2->z = vec1->z;
}