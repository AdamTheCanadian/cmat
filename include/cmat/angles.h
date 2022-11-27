#ifndef CMAT_INCLUDE_CMAT_ANGLES_H_
#define CMAT_INCLUDE_CMAT_ANGLES_H_

#include "cmat/mat3d.h"

typedef struct {
  union {
    struct {
      double x;
      double y;
      double z;
      double w;
    };
    double quat[4];
  };
} Quaternion;

typedef struct {
  union {
    struct {
      double x_radians;
      double y_radians;
      double z_radians;
    };
    double angles[3];
  };
} EulerAngles;

typedef Mat3d RotationMatrix;

void EulerToRotation(const EulerAngles *eulerAngles,
                     RotationMatrix *rotationMatrix);

#endif
