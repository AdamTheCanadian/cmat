#ifndef CMAT_TESTS_MAT3F_TESTS_H_
#define CMAT_TESTS_MAT3F_TESTS_H_

#include "ctest/unit_test.h"
#include "cmat/mat3f.h"

void test_get_row() {
  Mat3f mat = {
      1, 2, 3,
      4, 5, 6,
      7, 8, 9
  };

  Vec3f vec = Mat3f_GetRow(&mat, 0);
  UNIT_TEST_EXPECT_EQ_FLOAT("", vec.x, 1.0f);
  UNIT_TEST_EXPECT_EQ_FLOAT("", vec.y, 2.0f);
  UNIT_TEST_EXPECT_EQ_FLOAT("", vec.z, 3.0f);

  vec = Mat3f_GetRow(&mat, 1);
  UNIT_TEST_EXPECT_EQ_FLOAT("", vec.x, 4.0f);
  UNIT_TEST_EXPECT_EQ_FLOAT("", vec.y, 5.0f);
  UNIT_TEST_EXPECT_EQ_FLOAT("", vec.z, 6.0f);

  vec = Mat3f_GetRow(&mat, 2);
  UNIT_TEST_EXPECT_EQ_FLOAT("", vec.x, 7.0f);
  UNIT_TEST_EXPECT_EQ_FLOAT("", vec.y, 8.0f);
  UNIT_TEST_EXPECT_EQ_FLOAT("", vec.z, 9.0f);
}

void test_get_col() {
  Mat3f mat = {
      1, 2, 3,
      4, 5, 6,
      7, 8, 9
  };

  Vec3f vec = Mat3f_GetCol(&mat, 0);
  UNIT_TEST_EXPECT_EQ_FLOAT("", vec.x, 1.0f);
  UNIT_TEST_EXPECT_EQ_FLOAT("", vec.y, 4.0f);
  UNIT_TEST_EXPECT_EQ_FLOAT("", vec.z, 7.0f);

  vec = Mat3f_GetCol(&mat, 1);
  UNIT_TEST_EXPECT_EQ_FLOAT("", vec.x, 2.0f);
  UNIT_TEST_EXPECT_EQ_FLOAT("", vec.y, 5.0f);
  UNIT_TEST_EXPECT_EQ_FLOAT("", vec.z, 8.0f);

  vec = Mat3f_GetCol(&mat, 2);
  UNIT_TEST_EXPECT_EQ_FLOAT("", vec.x, 3.0f);
  UNIT_TEST_EXPECT_EQ_FLOAT("", vec.y, 6.0f);
  UNIT_TEST_EXPECT_EQ_FLOAT("", vec.z, 9.0f);
}

void test_set_col() {
  Mat3f mat = {
      1, 2, 3,
      4, 5, 6,
      7, 8, 9
  };

  Vec3f vec = (Vec3f){
    .x = 100,
    .y = 100,
    .z = 100
  };

  Mat3f_SetCol(&mat, &vec, 1);
  UNIT_TEST_EXPECT_EQ_FLOAT("", mat.mat[1], vec.x);
  UNIT_TEST_EXPECT_EQ_FLOAT("", mat.mat[4], vec.y);
  UNIT_TEST_EXPECT_EQ_FLOAT("", mat.mat[7], vec.z);
}

void test_set_row() {
  Mat3f mat = {
      1, 2, 3,
      4, 5, 6,
      7, 8, 9
  };

  Vec3f vec = (Vec3f){
      .x = 100,
      .y = 100,
      .z = 100
  };

  Mat3f_SetRow(&mat, &vec, 1);
  UNIT_TEST_EXPECT_EQ_FLOAT("", mat.mat[3], vec.x);
  UNIT_TEST_EXPECT_EQ_FLOAT("", mat.mat[4], vec.y);
  UNIT_TEST_EXPECT_EQ_FLOAT("", mat.mat[5], vec.z);
}


void Mat3f_tests_run() {
  UNIT_TEST_SETUP("Mat3f");
  UNIT_TEST_RUN_TEST("Get Row", test_get_row);
  UNIT_TEST_RUN_TEST("Get Col", test_get_col);
  UNIT_TEST_RUN_TEST("Set Row", test_set_row);
  UNIT_TEST_RUN_TEST("Set Col", test_set_col);
  UNIT_TEST_FINISH("Mat3f");
}

#endif
