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

#endif
