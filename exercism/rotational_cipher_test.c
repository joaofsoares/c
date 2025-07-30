#include "/opt/homebrew/Cellar/cunit/2.1-3/include/CUnit/Basic.h"
#include "/opt/homebrew/Cellar/cunit/2.1-3/include/CUnit/CUnit.h"
#include "rotational_cipher.c"
#include <stdlib.h>

void test_rotate(const char *expected, const char *text, int shift_key) {

  char *rotated = rotate(text, shift_key);

  CU_ASSERT_STRING_EQUAL(rotated, expected);

  free(rotated);
}

void test_rotate_a_by_0_same_output_as_input(void) { test_rotate("a", "a", 0); }

void test_rotate_a_by_1(void) { test_rotate("b", "a", 1); }

void test_rotate_a_by_26_same_output_as_input(void) {
  test_rotate("a", "a", 26);
}

void test_rotate_m_by_13(void) { test_rotate("z", "m", 13); }

void test_rotate_n_by_13_with_wrap_around_alphabet(void) {
  test_rotate("a", "n", 13);
}

void test_rotate_capital_letters(void) { test_rotate("TRL", "OMG", 5); }

void test_rotate_spaces(void) { test_rotate("T R L", "O M G", 5); }

void test_rotate_numbers(void) {
  test_rotate("Xiwxmrk 1 2 3 xiwxmrk", "Testing 1 2 3 testing", 4);
}

void test_rotate_punctuation(void) {
  test_rotate("Gzo'n zvo, Bmviyhv!", "Let's eat, Grandma!", 21);
}

void test_rotate_all_letters(void) {
  test_rotate("Gur dhvpx oebja sbk whzcf bire gur ynml qbt.",
              "The quick brown fox jumps over the lazy dog.", 13);
}

int main(void) {

  CU_initialize_registry();
  CU_pSuite suite = CU_add_suite("Rotational Cipher", 0, 0);

  CU_add_test(suite, "test_rotate_a_by_0_same_output_as_input",
              test_rotate_a_by_0_same_output_as_input);

  CU_add_test(suite, "test_rotate_a_by_1", test_rotate_a_by_1);

  CU_add_test(suite, "test_rotate_a_by_26_same_output_as_input",
              test_rotate_a_by_26_same_output_as_input);

  CU_add_test(suite, "test_rotate_m_by_13", test_rotate_m_by_13);

  CU_add_test(suite, "test_rotate_n_by_13_with_wrap_around_alphabet",
              test_rotate_n_by_13_with_wrap_around_alphabet);

  CU_add_test(suite, "test_rotate_capital_letters",
              test_rotate_capital_letters);

  CU_add_test(suite, "test_rotate_spaces", test_rotate_spaces);

  CU_add_test(suite, "test_rotate_numbers", test_rotate_numbers);

  CU_add_test(suite, "test_rotate_punctuation", test_rotate_punctuation);

  CU_add_test(suite, "test_rotate_all_letters", test_rotate_all_letters);

  CU_basic_run_tests();
  CU_cleanup_registry();

  return 0;
}
