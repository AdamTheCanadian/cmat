#include "cmat/rotations.h"
#include <math.h>

Mat3d Rotations_EulerToR(const Vec3d *eulerAngles) {
  double sin_x = sin(eulerAngles->x);
  double cos_x = cos(eulerAngles->x);
  double sin_y = sin(eulerAngles->y);
  double cos_y = cos(eulerAngles->y);
  double sin_z = sin(eulerAngles->z);
  double cos_z = cos(eulerAngles->z);

  return (Mat3d) {.mat = {
    cos_y * cos_z,                          cos_y * sin_z,                          -sin_y,
    -cos_x * sin_z + sin_x * sin_y * cos_z, cos_x * cos_z + sin_x * sin_y * sin_z,  sin_x * cos_y,
    sin_x * sin_z + cos_x * sin_y * cos_z,  -sin_x * cos_z + cos_x * sin_y * sin_z, cos_x * cos_y
  }};
}