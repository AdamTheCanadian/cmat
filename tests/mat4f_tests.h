#include "ctest/unit_test.h"
#include "cmat/mat4f.h"

void test_set_to_zero() {
  Mat4f mat;
  /* Set some values to not zero. Dont need the whole matrix, just a couple values.
     This is done just in case somehow mat4f is initialized to all zeros */
  mat.mat[0] = 100;
  mat.mat[15] = 100;
  Mat4f_SetZero(&mat);
  UNIT_TEST_EXPECT_EQ_ARRAY_F_TO_VALUE("", mat.mat, 0.0f, 16, 1.0e-5f);
}

void test_set_to_identity() {
  Mat4f mat;
  /* Set some values to not zero. Dont need the whole matrix, just a couple values.
     This is done just in case somehow mat4f is initialized to all zeros */
  mat.mat[0] = 100;
  mat.mat[15] = 100;
  Mat4f_SetIdentity(&mat);

  float true_mat[] = {
    1.0f, 0.0f, 0.0f, 0.0f,
    0.0f, 1.0f, 0.0f, 0.0f,
    0.0f, 0.0f, 1.0f, 0.0f,
    0.0f, 0.0f, 0.0f, 1.0f
  };
  UNIT_TEST_EXPECT_EQ_ARRAY_F("", mat.mat, true_mat, 16, 1.0e-5f);
}

void test_at() {
  Mat4f mat;
  Mat4f_SetIdentity(&mat);
  UNIT_TEST_EXPECT_EQ_FLOAT("", Mat4f_At(&mat, 0, 0), 1.0f);
  UNIT_TEST_EXPECT_EQ_FLOAT("", Mat4f_At(&mat, 1, 1), 1.0f);
  UNIT_TEST_EXPECT_EQ_FLOAT("", Mat4f_At(&mat, 2, 2), 1.0f);
  UNIT_TEST_EXPECT_EQ_FLOAT("", Mat4f_At(&mat, 3, 3), 1.0f);
  UNIT_TEST_EXPECT_EQ_FLOAT("", Mat4f_At(&mat, 0, 3), 0.0f);
  UNIT_TEST_EXPECT_EQ_FLOAT("", Mat4f_At(&mat, 3, 0), 0.0f);
}

void test_multiply_mat4f() {
  Mat4f mat = (Mat4f){.mat = 
  {
    1, 2, 3, 4,
    5, 6, 7, 8,
    9, 10, 11, 12,
    13, 14, 15, 16
  }};

  Mat4f result = Mat4f_MultiplyMat4f(&mat, &mat);

  float true_result[] = {
    90, 100, 110, 120,
    202, 228, 254, 280,
    314, 356, 398, 440,
    426, 484, 542, 600,
  };
  UNIT_TEST_EXPECT_EQ_ARRAY_F("", result.mat, true_result, 16, 1.0e-5f);
}

void Mat4f_tests_run() {
  UNIT_TEST_SETUP("Mat4f");
  UNIT_TEST_RUN_TEST("Set to zero", test_set_to_zero);
  UNIT_TEST_RUN_TEST("Set to identity", test_set_to_identity);
  UNIT_TEST_RUN_TEST("At", test_at);
  UNIT_TEST_RUN_TEST("MultiplyMat4f", test_multiply_mat4f);
  UNIT_TEST_FINISH("Mat4f");
}