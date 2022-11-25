#ifndef CMAT_INCLUDE_CMAT_VEC3D_H_
#define CMAT_INCLUDE_CMAT_VEC3D_H_

typedef struct Vector3Double{
  union {
    struct {
      double x;
      double y;
      double z;
    };
    double vec[3];
  };
} Vec3d;

void Vec3d_SetZero(Vec3d *vec);

/**
 * Compute vec * scale, modifies vec in place
 */
void Vec3d_Scale(Vec3d *vec,
                 double scale);

#endif
