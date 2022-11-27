#ifndef CMAT_INCLUDE_CMAT_ANGLES_H_
#define CMAT_INCLUDE_CMAT_ANGLES_H_

#include "cmat/mat3d.h"

static const double DEGREE_TO_RADIAN = 0.0174532925199433;
static const double RADIAN_TO_DEGREE = 57.2957795130823;

static inline double DegToRad(double deg) {
  return deg * DEGREE_TO_RADIAN;
}

static inline double RadToDeg(double rad) {
  return rad * RADIAN_TO_DEGREE;
}

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
