#ifndef CMAT_INCLUDE_CMAT_ROTATIONS_H_
#define CMAT_INCLUDE_CMAT_ROTATIONS_H_

#include "cmat/mat3d.h"
#include "cmat/vec3d.h"

/**
 * Convert a set of euler angles into a rotation matrix
 * \param eulerAngles in radians
 * \return
 */
Mat3d Rotations_EulerToR(const Vec3d *eulerAngles);

#endif
