#include "/opt/homebrew/Cellar/cunit/2.1-3/include/CUnit/Basic.h"
#include "/opt/homebrew/Cellar/cunit/2.1-3/include/CUnit/CUnit.h"
#include "sum_of_multiples.c"

#define NUM_OF_ELEMENTS(a) (sizeof(a) / sizeof(a[0]))

void test_no_multiples_within_limit(void) {

  const unsigned int multiples[] = {3, 5};

  CU_ASSERT_EQUAL(0, sum(multiples, NUM_OF_ELEMENTS(multiples), 1));
}

void test_one_factor_has_multiples_within_limit(void) {

  const unsigned int multiples[] = {3, 5};

  CU_ASSERT_EQUAL(3, sum(multiples, NUM_OF_ELEMENTS(multiples), 4));
}

void test_more_than_one_multiple_within_limit(void) {

  const unsigned int multiples[] = {3};

  CU_ASSERT_EQUAL(9, sum(multiples, NUM_OF_ELEMENTS(multiples), 7));
}

void test_more_than_one_factor_with_multiples_within_limit(void) {

  const unsigned int multiples[] = {3, 5};

  CU_ASSERT_EQUAL(23, sum(multiples, NUM_OF_ELEMENTS(multiples), 10));
}

void test_each_multiple_is_only_counted_once(void) {

  const unsigned int multiples[] = {3, 5};

  CU_ASSERT_EQUAL(2318, sum(multiples, NUM_OF_ELEMENTS(multiples), 100));
}

void test_a_much_larger_limit(void) {

  const unsigned int multiples[] = {3, 5};

  CU_ASSERT_EQUAL(233168, sum(multiples, NUM_OF_ELEMENTS(multiples), 1000));
}

void test_three_factors(void) {

  const unsigned int multiples[] = {7, 13, 17};

  CU_ASSERT_EQUAL(51, sum(multiples, NUM_OF_ELEMENTS(multiples), 20));
}

void test_factors_not_relatively_prime(void) {

  const unsigned int multiples[] = {4, 6};

  CU_ASSERT_EQUAL(30, sum(multiples, NUM_OF_ELEMENTS(multiples), 15));
}

void test_some_pairs_of_factors_relatively_prime_and_some_not(void) {

  const unsigned int multiples[] = {5, 6, 8};

  CU_ASSERT_EQUAL(4419, sum(multiples, NUM_OF_ELEMENTS(multiples), 150));
}

void test_one_factor_is_a_multiple_of_another(void) {

  const unsigned int multiples[] = {5, 25};

  CU_ASSERT_EQUAL(275, sum(multiples, NUM_OF_ELEMENTS(multiples), 51));
}

void test_much_larger_factors(void) {

  const unsigned int multiples[] = {43, 47};

  CU_ASSERT_EQUAL(2203160, sum(multiples, NUM_OF_ELEMENTS(multiples), 10000));
}

void test_all_numbers_are_multiples_of_1(void) {

  const unsigned int multiples[] = {1};

  CU_ASSERT_EQUAL(4950, sum(multiples, NUM_OF_ELEMENTS(multiples), 100));
}

void test_no_factors_means_an_empty_sum(void) {

  const unsigned int multiples[] = {0};

  CU_ASSERT_EQUAL(0, sum(multiples, NUM_OF_ELEMENTS(multiples), 1000));
}

void test_the_only_multiple_of_zero_is_zero(void) {

  const unsigned int multiples[] = {0};

  CU_ASSERT_EQUAL(0, sum(multiples, NUM_OF_ELEMENTS(multiples), 1));
}

void test_the_factor_0_does_not_affect_the_sum_of_multiples_of_other_factors(
    void) {

  const unsigned int multiples[] = {3, 0};

  CU_ASSERT_EQUAL(3, sum(multiples, NUM_OF_ELEMENTS(multiples), 4));
}

void test_solutions_using_include_exclude_must_extend_to_cardinality_greater_than_3(
    void) {

  const unsigned int multiples[] = {2, 3, 5, 7, 11};

  CU_ASSERT_EQUAL(39614537, sum(multiples, NUM_OF_ELEMENTS(multiples), 10000));
}

int main(void) {

  CU_initialize_registry();
  CU_pSuite suite = CU_add_suite("Allergies", 0, 0);

  CU_add_test(suite, "test_no_multiples_within_limit",
              test_no_multiples_within_limit);

  CU_add_test(suite, "test_one_factor_has_multiples_within_limit",
              test_one_factor_has_multiples_within_limit);

  CU_add_test(suite, "test_more_than_one_multiple_within_limit",
              test_more_than_one_multiple_within_limit);

  CU_add_test(suite, "test_more_than_one_factor_with_multiples_within_limit",
              test_more_than_one_factor_with_multiples_within_limit);

  CU_add_test(suite, "test_each_multiple_is_only_counted_once",
              test_each_multiple_is_only_counted_once);

  CU_add_test(suite, "test_a_much_larger_limit", test_a_much_larger_limit);

  CU_add_test(suite, "test_three_factors", test_three_factors);

  CU_add_test(suite, "test_factors_not_relatively_prime",
              test_factors_not_relatively_prime);

  CU_add_test(suite, "test_some_pairs_of_factors_relatively_prime_and_some_not",
              test_some_pairs_of_factors_relatively_prime_and_some_not);

  CU_add_test(suite, "test_one_factor_is_a_multiple_of_another",
              test_one_factor_is_a_multiple_of_another);

  CU_add_test(suite, "test_much_larger_factors", test_much_larger_factors);

  CU_add_test(suite, "test_all_numbers_are_multiples_of_1",
              test_all_numbers_are_multiples_of_1);

  CU_add_test(suite, "test_no_factors_means_an_empty_sum",
              test_no_factors_means_an_empty_sum);

  CU_add_test(suite, "test_the_only_multiple_of_zero_is_zero",
              test_the_only_multiple_of_zero_is_zero);

  CU_add_test(
      suite,
      "test_the_factor_0_does_not_affect_the_sum_of_multiples_of_other_factors",
      test_the_factor_0_does_not_affect_the_sum_of_multiples_of_other_factors);

  CU_add_test(
      suite,
      "test_solutions_using_include_exclude_must_extend_to_cardinality_greater_"
      "than_3",
      test_solutions_using_include_exclude_must_extend_to_cardinality_greater_than_3);

  CU_basic_run_tests();
  CU_cleanup_registry();

  return 0;
}
