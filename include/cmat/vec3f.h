#ifndef CMAT_INCLUDE_CMAT_VEC3F_H_
#define CMAT_INCLUDE_CMAT_VEC3F_H_

#include <stdbool.h>

typedef struct Vector3Float{
  union {
    struct {
      float x;
      float y;
      float z;
    };
    float vec[3];
  };
} Vec3f;

/**
 * Set all elements to 0
 */
void Vec3f_SetZero(Vec3f* vec);

/**
 * Subtract two vectors (vv), vec1 - vec2
 * @return vec1 - vec2
 */
Vec3f Vec3f_SubtractVec3f(const Vec3f* vec1,
                          const Vec3f* vec2);

/**
 * Calculate and return the length/norm/magnitude of the vector
 */
float Vec3f_Length(const Vec3f* vec);

/**
 * Normalize a vector to be unit length
 */
void Vec3f_Normalize(Vec3f* vec);

/**
 * Compute the cross product of two vectors
 *
 * return cross == vec1 x vec2
 */
Vec3f Vec3f_Cross(const Vec3f* vec1,
                  const Vec3f* vec2);

/**
 * Compute the dot product of two vectors
 */
float Vec3f_DotProduct(const Vec3f* vec1,
                       const Vec3f* vec2);

/**
 * Return vec1 == vec2
 */
bool Vec3f_IsEqual(const Vec3f* vec1,
                   const Vec3f* vec2);

/**
 * Copy the elements of vec1 into vec2 so vec1 == vec2
 */
void Vec3f_Copy(const Vec3f* vec1,
                Vec3f* vec2);

#endif