#include "../deps/unity/unity.h"
#include "./common.c"
#include "./strings.c"
#include <math.h>

void setUp(void) {
  // set stuff up here
}

void tearDown(void) {
  // clean stuff up here
}

void test_QTZ_LengthAsString(void) {
  for (size_t i = 0; i < 10; i++) {
    TEST_ASSERT_EQUAL_size_t(1, QTZ_LengthAsString(i));
  }
  for (size_t i = 10; i < 100; i++) {
    TEST_ASSERT_EQUAL_size_t(2, QTZ_LengthAsString(i));
  }

  for (size_t i = 3; i < 10; i++) {
    size_t start = (size_t)pow(10, i);
    start += 1721;
    TEST_ASSERT_EQUAL_size_t(i + 1, QTZ_LengthAsString(start));
  }
}

// not needed when using generate_test_runner.rb
int main(void) {
  UNITY_BEGIN();
  RUN_TEST(test_QTZ_LengthAsString);
  return UNITY_END();
}
