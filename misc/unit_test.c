// command to compile
// gcc -o unity_test unity_test.c -I/opt/homebrew/Cellar/cunit/2.1-3/include
// -L/opt/homebrew/Cellar/cunit/2.1-3/lib -lcunit

#include "/opt/homebrew/Cellar/cunit/2.1-3/include/CUnit/Basic.h"
#include "/opt/homebrew/Cellar/cunit/2.1-3/include/CUnit/CUnit.h"

int add(int a, int b) { return a + b; }

void test_add() {
  CU_ASSERT_EQUAL(add(2, 3), 5);
  CU_ASSERT_EQUAL(add(-1, 1), 0);
  CU_ASSERT_EQUAL(add(0, 0), 0);
  CU_ASSERT_EQUAL(add(-2, -3), -5);
}

int main() {
  CU_initialize_registry();
  CU_pSuite suite = CU_add_suite("AddTestSuite", 0, 0);
  CU_add_test(suite, "test of add()", test_add);
  CU_basic_run_tests();
  CU_cleanup_registry();

  return 0;
}
