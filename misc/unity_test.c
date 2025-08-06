// gcc test_with_unity.c ../Unity/src/unity.c -o test_with_unity

#include "../Unity/src/unity.h"

void setUp(void) {}

void tearDown(void) {}

int add(int a, int b) { return a + b; }

void test_add(void) { TEST_ASSERT_EQUAL_INT(2, add(1, 1)); }

int main(void) {
  UNITY_BEGIN();
  RUN_TEST(test_add);
  return UNITY_END();
}
