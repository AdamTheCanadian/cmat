#include "ctest/unit_test.h"
#include "cmat/vec3f.h"

void test_Vec3f_set_to_zero() {
  Vec3f vec;
  vec.x = 1.234;
  vec.y = 5.678;
  vec.z = 9.012;
  Vec3f_SetZero(&vec);
  UNIT_TEST_EXPECT_EQ_ARRAY_F_TO_VALUE("", vec.vec, 0.0f, 3, 1.0e-5f);
}

void test_Vec3f_subtract_vec3f() {
  Vec3f vec1 = {.x = 10, .y = 11, .z = 12};
  Vec3f vec2 = {.x = 0, .y = 1, .z = 2};

  Vec3f result = Vec3f_SubtractVec3f(&vec1, &vec2);
  UNIT_TEST_EXPECT_EQ_ARRAY_F_TO_VALUE("", result.vec, 10.0f, 3, 1.0e-5f);
}

void test_Vec3f_length() {
  Vec3f vec = {.x = 81.4723686393179f, .y = 90.5791937075619f, 12.6986816293506f};
  UNIT_TEST_EXPECT_EQ_FLOAT("", Vec3f_Length(&vec), 122.489157477454f);
}

void test_Vec3f_normalize() {
  Vec3f vec = {.x = 81.4723686393179f, .y = 90.5791937075619f, 12.6986816293506f};
  Vec3f_Normalize(&vec);
  UNIT_TEST_EXPECT_EQ_FLOAT("", vec.x, 0.665139432070256f);
  UNIT_TEST_EXPECT_EQ_FLOAT("", vec.y, 0.739487441769974f);
  UNIT_TEST_EXPECT_EQ_FLOAT("", vec.z, 0.103671883216994f);
}

void test_Vec3f_cross() {
  Vec3f vec1 = {.x = 0.913375856139019f, .y = 0.632359246225410f, 0.0975404049994095f};
  Vec3f vec2 = {.x = 0.278498218867048f, .y = 0.546881519204984f, 0.957506835434298f};
  Vec3f vec3 = Vec3f_Cross(&vec1, &vec2);
  UNIT_TEST_EXPECT_EQ_FLOAT("", vec3.x, 0.552145255840963f);
  UNIT_TEST_EXPECT_EQ_FLOAT("", vec3.y, -0.847398796513859f);
  UNIT_TEST_EXPECT_EQ_FLOAT("", vec3.z, 0.323397452052574f);
}

void Vec3f_tests_run() {
  UNIT_TEST_SETUP("Vec3f");
  UNIT_TEST_RUN_TEST("Set to Zero", test_Vec3f_set_to_zero);
  UNIT_TEST_RUN_TEST("Subtract vec3f", test_Vec3f_subtract_vec3f);
  UNIT_TEST_RUN_TEST("Length", test_Vec3f_length);
  UNIT_TEST_RUN_TEST("Normalize", test_Vec3f_normalize);
  UNIT_TEST_RUN_TEST("Cross Product", test_Vec3f_cross);
  UNIT_TEST_FINISH("Vec3");
}