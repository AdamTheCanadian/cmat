#include "cmat/angles.h"
#include <math.h>

void EulerToRotation(const EulerAngles *eulerAngles,
                     RotationMatrix *rotationMatrix) {
  double sin_x = sin(eulerAngles->x_radians);
  double cos_x = cos(eulerAngles->x_radians);
  double sin_y = sin(eulerAngles->y_radians);
  double cos_y = cos(eulerAngles->y_radians);
  double sin_z = sin(eulerAngles->z_radians);
  double cos_z = cos(eulerAngles->z_radians);

  *rotationMatrix = (Mat3d) {.mat = {
      cos_y * cos_z, cos_y * sin_z, -sin_y,
      -cos_x * sin_z + sin_x * sin_y * cos_z, cos_x * cos_z + sin_x * sin_y * sin_z, sin_x * cos_y,
      sin_x * sin_z + cos_x * sin_y * cos_z, -sin_x * cos_z + cos_x * sin_y * sin_z, cos_x * cos_y
  }};
}