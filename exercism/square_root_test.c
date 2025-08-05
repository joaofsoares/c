#include "/opt/homebrew/Cellar/cunit/2.1-3/include/CUnit/Basic.h"
#include "/opt/homebrew/Cellar/cunit/2.1-3/include/CUnit/CUnit.h"
#include "square_root.c"

void test_root_of_1(void) { CU_ASSERT_EQUAL(1, square_root(1)); }

void test_root_of_4(void) { CU_ASSERT_EQUAL(2, square_root(4)); }

void test_root_of_25(void) { CU_ASSERT_EQUAL(5, square_root(25)); }

void test_root_of_81(void) { CU_ASSERT_EQUAL(9, square_root(81)); }

void test_root_of_196(void) { CU_ASSERT_EQUAL(14, square_root(196)); }

void test_root_of_65025(void) { CU_ASSERT_EQUAL(255, square_root(65025)); }

int main(void) {

  CU_initialize_registry();
  CU_pSuite suite = CU_add_suite("Square Root", 0, 0);

  CU_add_test(suite, "test_root_of_1", test_root_of_1);
  CU_add_test(suite, "test_root_of_4", test_root_of_4);
  CU_add_test(suite, "test_root_of_25", test_root_of_25);
  CU_add_test(suite, "test_root_of_81", test_root_of_81);
  CU_add_test(suite, "test_root_of_196", test_root_of_196);
  CU_add_test(suite, "test_root_of_65025", test_root_of_65025);

  CU_basic_run_tests();
  CU_cleanup_registry();

  return 0;
}
