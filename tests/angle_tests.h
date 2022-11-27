#ifndef CMAT_TESTS_ANGLE_TESTS_H_
#define CMAT_TESTS_ANGLE_TESTS_H_

#include "ctest/unit_test.h"
#include "cmat/angles.h"

void euler_to_rotation_tests() {
  EulerAngles euler_angles = {
      -0.366519142918809,
      1.36135681655558,
      5.20108117094310
  };

  RotationMatrix rotation_matrix;
  EulerToRotation(&euler_angles, &rotation_matrix);

  UNIT_TEST_EXPECT_EQ_DOUBLE("", rotation_matrix.mat[0], 0.0976086264096704);
  UNIT_TEST_EXPECT_EQ_DOUBLE("", rotation_matrix.mat[1], -0.183575126934770);
  UNIT_TEST_EXPECT_EQ_DOUBLE("", rotation_matrix.mat[2], -0.978147600733806);
  UNIT_TEST_EXPECT_EQ_DOUBLE("", rotation_matrix.mat[3], 0.659735554466557);
  UNIT_TEST_EXPECT_EQ_DOUBLE("", rotation_matrix.mat[4], 0.747795041459446);
  UNIT_TEST_EXPECT_EQ_DOUBLE("", rotation_matrix.mat[5], -0.0745088863248569);
  UNIT_TEST_EXPECT_EQ_DOUBLE("", rotation_matrix.mat[6], 0.745131903909048);
  UNIT_TEST_EXPECT_EQ_DOUBLE("", rotation_matrix.mat[7], -0.638046039670766);
  UNIT_TEST_EXPECT_EQ_DOUBLE("", rotation_matrix.mat[8], 0.194102284987398);
}

void run_angle_tests() {
  UNIT_TEST_SETUP("Angle Tests");
  UNIT_TEST_RUN_TEST("Euler to Rotation", euler_to_rotation_tests);
  UNIT_TEST_FINISH("Angle Tests");
}

#endif
