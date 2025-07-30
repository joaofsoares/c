#include "/opt/homebrew/Cellar/cunit/2.1-3/include/CUnit/Basic.h"
#include "/opt/homebrew/Cellar/cunit/2.1-3/include/CUnit/CUnit.h"
#include "complex_numbers.c"

#define PI acos(-1)
#define E exp(1)

void compare_complex(complex_t expected, complex_t actual) {

  double double_delta = 0.000000001;

  CU_ASSERT_DOUBLE_EQUAL(expected.real, actual.real, double_delta);

  CU_ASSERT_DOUBLE_EQUAL(expected.imag, actual.imag, double_delta);
}

void test_real_part_of_a_purely_real_number(void) {

  complex_t z = {.real = 1.0, .imag = 0.0};

  double expected = 1.0;

  double actual = c_real(z);

  CU_ASSERT_DOUBLE_EQUAL(expected, actual, 0.00001);
}

void test_real_part_of_a_purely_imaginary_number(void) {

  complex_t z = {.real = 0.0, .imag = 1.0};

  double expected = 0.0;

  double actual = c_real(z);

  CU_ASSERT_DOUBLE_EQUAL(expected, actual, 0.00001);
}

void test_real_part_of_a_number_with_real_and_imaginary_part(void) {

  complex_t z = {.real = 1.0, .imag = 2.0};

  double expected = 1.0;

  double actual = c_real(z);

  CU_ASSERT_DOUBLE_EQUAL(expected, actual, 0.00001);
}

void test_imaginary_part_of_a_purely_real_number(void) {

  complex_t z = {.real = 1.0, .imag = 0.0};

  double expected = 0.0;

  double actual = c_imag(z);

  CU_ASSERT_DOUBLE_EQUAL(expected, actual, 0.00001);
}

void test_imaginary_part_of_a_purely_imaginary_number(void) {

  complex_t z = {.real = 0.0, .imag = 1.0};

  double expected = 1.0;

  double actual = c_imag(z);

  CU_ASSERT_DOUBLE_EQUAL(expected, actual, 0.00001);
}

void test_imaginary_part_of_a_number_with_real_and_imaginary_part(void) {

  complex_t z = {.real = 1.0, .imag = 2.0};

  double expected = 2.0;

  double actual = c_imag(z);

  CU_ASSERT_DOUBLE_EQUAL(expected, actual, 0.00001);
}

void test_imaginary_unit(void) {

  complex_t z = {.real = 0.0, .imag = 1.0};

  complex_t expected = {.real = -1.0, .imag = 0.0};

  complex_t actual = c_mul(z, z);

  compare_complex(expected, actual);
}

void test_add_purely_real_numbers(void) {

  complex_t z1 = {.real = 1.0, .imag = 0.0};

  complex_t z2 = {.real = 2.0, .imag = 0.0};

  complex_t expected = {.real = 3.0, .imag = 0.0};

  complex_t actual = c_add(z1, z2);

  compare_complex(expected, actual);
}

void test_add_purely_imaginary_numbers(void) {

  complex_t z1 = {.real = 0.0, .imag = 1.0};

  complex_t z2 = {.real = 0.0, .imag = 2.0};

  complex_t expected = {.real = 0.0, .imag = 3.0};

  complex_t actual = c_add(z1, z2);

  compare_complex(expected, actual);
}

void test_add_numbers_with_real_and_imaginary_part(void) {

  complex_t z1 = {.real = 1.0, .imag = 2.0};

  complex_t z2 = {.real = 3.0, .imag = 4.0};

  complex_t expected = {.real = 4.0, .imag = 6.0};

  complex_t actual = c_add(z1, z2);

  compare_complex(expected, actual);
}

void test_subtract_purely_real_numbers(void) {

  complex_t z1 = {.real = 1.0, .imag = 0.0};

  complex_t z2 = {.real = 2.0, .imag = 0.0};

  complex_t expected = {.real = -1.0, .imag = 0.0};

  complex_t actual = c_sub(z1, z2);

  compare_complex(expected, actual);
}

void test_subtract_purely_imaginary_numbers(void) {

  complex_t z1 = {.real = 0.0, .imag = 1.0};

  complex_t z2 = {.real = 0.0, .imag = 2.0};

  complex_t expected = {.real = 0.0, .imag = -1.0};

  complex_t actual = c_sub(z1, z2);

  compare_complex(expected, actual);
}

void test_subtract_numbers_with_real_and_imaginary_part(void) {

  complex_t z1 = {.real = 1.0, .imag = 2.0};

  complex_t z2 = {.real = 3.0, .imag = 4.0};

  complex_t expected = {.real = -2.0, .imag = -2.0};

  complex_t actual = c_sub(z1, z2);

  compare_complex(expected, actual);
}

void test_multiply_purely_real_numbers(void) {

  complex_t z1 = {.real = 1.0, .imag = 0.0};

  complex_t z2 = {.real = 2.0, .imag = 0.0};

  complex_t expected = {.real = 2.0, .imag = 0.0};

  complex_t actual = c_mul(z1, z2);

  compare_complex(expected, actual);
}

void test_multiply_purely_imaginary_numbers(void) {

  complex_t z1 = {.real = 0.0, .imag = 1.0};

  complex_t z2 = {.real = 0.0, .imag = 2.0};

  complex_t expected = {.real = -2.0, .imag = 0.0};

  complex_t actual = c_mul(z1, z2);

  compare_complex(expected, actual);
}

void test_multiply_numbers_with_real_and_imaginary_part(void) {

  complex_t z1 = {.real = 1.0, .imag = 2.0};

  complex_t z2 = {.real = 3.0, .imag = 4.0};

  complex_t expected = {.real = -5.0, .imag = 10.0};

  complex_t actual = c_mul(z1, z2);

  compare_complex(expected, actual);
}

void test_divide_purely_real_numbers(void) {

  complex_t z1 = {.real = 1.0, .imag = 0.0};

  complex_t z2 = {.real = 2.0, .imag = 0.0};

  complex_t expected = {.real = 0.5, .imag = 0.0};

  complex_t actual = c_div(z1, z2);

  compare_complex(expected, actual);
}

void test_divide_purely_imaginary_numbers(void) {

  complex_t z1 = {.real = 0.0, .imag = 1.0};

  complex_t z2 = {.real = 0.0, .imag = 2.0};

  complex_t expected = {.real = 0.5, .imag = 0.0};

  complex_t actual = c_div(z1, z2);

  compare_complex(expected, actual);
}

void test_divide_numbers_with_real_and_imaginary_part(void) {

  complex_t z1 = {.real = 1.0, .imag = 2.0};

  complex_t z2 = {.real = 3.0, .imag = 4.0};

  complex_t expected = {.real = 0.44, .imag = 0.08};

  complex_t actual = c_div(z1, z2);

  compare_complex(expected, actual);
}

void test_absolute_value_of_a_positive_purely_real_number(void) {

  complex_t z = {.real = 5.0, .imag = 0.0};

  double expected = 5.0;

  double actual = c_abs(z);

  CU_ASSERT_DOUBLE_EQUAL(expected, actual, 0.00001);
}

void test_absolute_value_of_a_negative_purely_real_number(void) {
  complex_t z = {.real = -5.0, .imag = 0.0};

  double expected = 5.0;

  double actual = c_abs(z);

  CU_ASSERT_DOUBLE_EQUAL(expected, actual, 0.00001);
}

void test_absolute_value_of_a_purely_imaginary_number_with_positive_imaginary_part(
    void) {

  complex_t z = {.real = 0.0, .imag = 5.0};

  double expected = 5.0;

  double actual = c_abs(z);

  CU_ASSERT_DOUBLE_EQUAL(expected, actual, 0.00001);
}

void test_absolute_value_of_a_purely_imaginary_number_with_negative_imaginary_part(
    void) {

  complex_t z = {.real = 0.0, .imag = -5.0};

  double expected = 5.0;

  double actual = c_abs(z);

  CU_ASSERT_DOUBLE_EQUAL(expected, actual, 0.00001);
}

void test_absolute_value_of_a_number_with_real_and_imaginary_part(void) {

  complex_t z = {.real = 3.0, .imag = 4.0};

  double expected = 5.0;

  double actual = c_abs(z);

  CU_ASSERT_DOUBLE_EQUAL(expected, actual, 0.00001);
}

void test_complex_conjugate_of_a_purely_real_number(void) {

  complex_t z = {.real = 5.0, .imag = 0.0};

  complex_t expected = {.real = 5.0, .imag = 0.0};

  complex_t actual = c_conjugate(z);

  compare_complex(expected, actual);
}

void test_complex_conjugate_of_a_purely_imaginary_number(void) {

  complex_t z = {.real = 0.0, .imag = 5.0};

  complex_t expected = {.real = 0.0, .imag = -5.0};

  complex_t actual = c_conjugate(z);

  compare_complex(expected, actual);
}

void test_complex_conjugate_of_a_number_with_real_and_imaginary_part(void) {

  complex_t z = {.real = 1.0, .imag = 1.0};

  complex_t expected = {.real = 1.0, .imag = -1.0};

  complex_t actual = c_conjugate(z);

  compare_complex(expected, actual);
}

void test_eulers_identity(void) {

  complex_t z = {.real = 0.0, .imag = PI};

  complex_t expected = {.real = -1.0, .imag = 0.0};

  complex_t actual = c_exp(z);

  CU_ASSERT_DOUBLE_EQUAL(expected.real, actual.real, 1e-10);

  CU_ASSERT_DOUBLE_EQUAL(expected.imag, actual.imag, 1e-10);
}

void test_exponential_of_zero(void) {

  complex_t zero = {.real = 0.0, .imag = 0.0};

  complex_t expected = {.real = 1.0, .imag = 0.0};

  complex_t actual = c_exp(zero);

  compare_complex(expected, actual);
}

void test_exponential_of_a_purely_real_number(void) {

  complex_t z = {.real = 1.0, .imag = 0.0};

  complex_t expected = {.real = E, .imag = 0.0};

  complex_t actual = c_exp(z);

  compare_complex(expected, actual);
}

void test_exponential_of_a_number_with_real_and_imaginary_part(void) {

  // In math.h the log() function computes log to the base e, which

  // is the natural logarithm, often written in mathematics as ln

  complex_t z = {.real = log(2.0), .imag = PI};

  complex_t expected = {.real = -2.0, .imag = 0};

  complex_t actual = c_exp(z);

  compare_complex(expected, actual);
}

void test_exponential_resulting_in_number_with_real_and_imaginary_part(void) {

  complex_t z = {.real = log(2.0) / 2.0, .imag = PI / 4.0};

  complex_t expected = {.real = 1.0, .imag = 1.0};

  complex_t actual = c_exp(z);

  compare_complex(expected, actual);
}

void test_add_real_number_to_complex_number(void) {

  complex_t z1 = {.real = 1.0, .imag = 2.0};

  complex_t z2 = {.real = 5.0, .imag = 0.0};

  complex_t expected = {.real = 6.0, .imag = 2.0};

  complex_t actual = c_add(z1, z2);

  compare_complex(expected, actual);
}

void test_add_complex_number_to_real_number(void) {

  complex_t z1 = {.real = 5.0, .imag = 0.0};

  complex_t z2 = {.real = 1.0, .imag = 2.0};

  complex_t expected = {.real = 6.0, .imag = 2.0};

  complex_t actual = c_add(z1, z2);

  compare_complex(expected, actual);
}

void test_subtract_real_number_from_complex_number(void) {

  complex_t z1 = {.real = 5.0, .imag = 7.0};

  complex_t z2 = {.real = 4.0, .imag = 0.0};

  complex_t expected = {.real = 1.0, .imag = 7.0};

  complex_t actual = c_sub(z1, z2);

  compare_complex(expected, actual);
}

void test_subtract_complex_number_from_real_number(void) {

  complex_t z1 = {.real = 4.0, .imag = 0.0};

  complex_t z2 = {.real = 5.0, .imag = 7.0};

  complex_t expected = {.real = -1.0, .imag = -7.0};

  complex_t actual = c_sub(z1, z2);

  compare_complex(expected, actual);
}

void test_multiply_complex_number_by_real_number(void) {

  complex_t z1 = {.real = 2.0, .imag = 5.0};

  complex_t z2 = {.real = 5.0, .imag = 0.0};

  complex_t expected = {.real = 10.0, .imag = 25.0};

  complex_t actual = c_mul(z1, z2);

  compare_complex(expected, actual);
}

void test_multiply_real_number_by_complex_number(void) {

  complex_t z1 = {.real = 5.0, .imag = 0.0};

  complex_t z2 = {.real = 2.0, .imag = 5.0};

  complex_t expected = {.real = 10.0, .imag = 25.0};

  complex_t actual = c_mul(z1, z2);

  compare_complex(expected, actual);
}

void test_divide_complex_number_by_real_number(void) {

  complex_t z1 = {.real = 10.0, .imag = 100.0};

  complex_t z2 = {.real = 10.0, .imag = 0.0};

  complex_t expected = {.real = 1.0, .imag = 10.0};

  complex_t actual = c_div(z1, z2);

  compare_complex(expected, actual);
}

void test_divide_real_number_by_complex_number(void) {

  complex_t z1 = {.real = 5.0, .imag = 0.0};

  complex_t z2 = {.real = 1.0, .imag = 1.0};

  complex_t expected = {.real = 2.5, .imag = -2.5};

  complex_t actual = c_div(z1, z2);

  compare_complex(expected, actual);
}

int main(void) {
  CU_initialize_registry();
  CU_pSuite suite = CU_add_suite("Complex Numbers", 0, 0);

  CU_add_test(suite, "test_real_part_of_a_purely_real_number",
              test_real_part_of_a_purely_real_number);
  CU_add_test(suite, "test_real_part_of_a_purely_imaginary_number",
              test_real_part_of_a_purely_imaginary_number);
  CU_add_test(suite, "test_real_part_of_a_number_with_real_and_imaginary_part",
              test_real_part_of_a_number_with_real_and_imaginary_part);
  CU_add_test(suite, "test_imaginary_part_of_a_purely_real_number",
              test_imaginary_part_of_a_purely_real_number);
  CU_add_test(suite, "test_imaginary_part_of_a_purely_imaginary_number",
              test_imaginary_part_of_a_purely_imaginary_number);
  CU_add_test(suite,
              "test_imaginary_part_of_a_number_with_real_and_imaginary_part",
              test_imaginary_part_of_a_number_with_real_and_imaginary_part);
  CU_add_test(suite, "test_imaginary_unit", test_imaginary_unit);
  CU_add_test(suite, "test_add_purely_real_numbers",
              test_add_purely_real_numbers);
  CU_add_test(suite, "test_add_purely_imaginary_numbers",
              test_add_purely_imaginary_numbers);
  CU_add_test(suite, "test_add_numbers_with_real_and_imaginary_part",
              test_add_numbers_with_real_and_imaginary_part);
  CU_add_test(suite, "test_subtract_purely_real_numbers",
              test_subtract_purely_real_numbers);

  CU_add_test(suite, "test_subtract_purely_imaginary_numbers",
              test_subtract_purely_imaginary_numbers);

  CU_add_test(suite, "test_subtract_numbers_with_real_and_imaginary_part",
              test_subtract_numbers_with_real_and_imaginary_part);

  CU_add_test(suite, "test_multiply_purely_real_numbers",
              test_multiply_purely_real_numbers);

  CU_add_test(suite, "test_multiply_purely_imaginary_numbers",
              test_multiply_purely_imaginary_numbers);

  CU_add_test(suite, "test_multiply_numbers_with_real_and_imaginary_part",
              test_multiply_numbers_with_real_and_imaginary_part);

  CU_add_test(suite, "test_divide_purely_real_numbers",
              test_divide_purely_real_numbers);

  CU_add_test(suite, "test_divide_purely_imaginary_numbers",
              test_divide_purely_imaginary_numbers);

  CU_add_test(suite, "test_divide_numbers_with_real_and_imaginary_part",
              test_divide_numbers_with_real_and_imaginary_part);

  CU_add_test(suite, "test_absolute_value_of_a_positive_purely_real_number",
              test_absolute_value_of_a_positive_purely_real_number);

  CU_add_test(suite, "test_absolute_value_of_a_negative_purely_real_number",
              test_absolute_value_of_a_negative_purely_real_number);

  CU_add_test(
      suite,
      "test_absolute_value_of_a_purely_imaginary_number_with_positive_"
      "imaginary_part",
      test_absolute_value_of_a_purely_imaginary_number_with_positive_imaginary_part);

  CU_add_test(
      suite,
      "test_absolute_value_of_a_purely_imaginary_number_with_negative_"
      "imaginary_part",
      test_absolute_value_of_a_purely_imaginary_number_with_negative_imaginary_part);

  CU_add_test(suite,
              "test_absolute_value_of_a_number_with_real_and_imaginary_part",
              test_absolute_value_of_a_number_with_real_and_imaginary_part);

  CU_add_test(suite, "test_complex_conjugate_of_a_purely_real_number",
              test_complex_conjugate_of_a_purely_real_number);

  CU_add_test(suite, "test_complex_conjugate_of_a_purely_imaginary_number",
              test_complex_conjugate_of_a_purely_imaginary_number);

  CU_add_test(suite,
              "test_complex_conjugate_of_a_number_with_real_and_imaginary_part",
              test_complex_conjugate_of_a_number_with_real_and_imaginary_part);

  CU_add_test(suite, "test_eulers_identity", test_eulers_identity);

  CU_add_test(suite, "test_exponential_of_zero", test_exponential_of_zero);

  CU_add_test(suite, "test_exponential_of_a_purely_real_number",
              test_exponential_of_a_purely_real_number);

  CU_add_test(suite,
              "test_exponential_of_a_number_with_real_and_imaginary_part",
              test_exponential_of_a_number_with_real_and_imaginary_part);

  CU_add_test(
      suite,
      "test_exponential_resulting_in_number_with_real_and_imaginary_part",
      test_exponential_resulting_in_number_with_real_and_imaginary_part);

  CU_add_test(suite, "test_add_real_number_to_complex_number",
              test_add_real_number_to_complex_number);

  CU_add_test(suite, "test_add_complex_number_to_real_number",
              test_add_complex_number_to_real_number);

  CU_add_test(suite, "test_subtract_real_number_from_complex_number",
              test_subtract_real_number_from_complex_number);

  CU_add_test(suite, "test_subtract_complex_number_from_real_number",
              test_subtract_complex_number_from_real_number);

  CU_add_test(suite, "test_multiply_complex_number_by_real_number",
              test_multiply_complex_number_by_real_number);

  CU_add_test(suite, "test_multiply_real_number_by_complex_number",
              test_multiply_real_number_by_complex_number);

  CU_add_test(suite, "test_divide_complex_number_by_real_number",
              test_divide_complex_number_by_real_number);

  CU_add_test(suite, "test_divide_real_number_by_complex_number",
              test_divide_real_number_by_complex_number);

  CU_basic_run_tests();
  CU_cleanup_registry();
  return 0;
}
