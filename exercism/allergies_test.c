#include "/opt/homebrew/Cellar/cunit/2.1-3/include/CUnit/Basic.h"
#include "/opt/homebrew/Cellar/cunit/2.1-3/include/CUnit/CUnit.h"
#include "allergies.c"

void test_not_allergic_to_anything_for_eggs(void) {
  CU_ASSERT_FALSE(is_allergic_to(ALLERGEN_EGGS, 0));
}

void test_allergic_only_to_eggs(void) {
  CU_ASSERT_TRUE(is_allergic_to(ALLERGEN_EGGS, 1));
}

void test_allergic_to_eggs_and_something_else(void) {
  CU_ASSERT_TRUE(is_allergic_to(ALLERGEN_EGGS, 3));
}

void test_allergic_to_something_but_not_eggs(void) {
  CU_ASSERT_FALSE(is_allergic_to(ALLERGEN_EGGS, 2));
}

void test_allergic_to_everything_for_eggs(void) {
  CU_ASSERT_TRUE(is_allergic_to(ALLERGEN_EGGS, 255));
}

void test_not_allergic_to_anything_for_peanuts(void) {
  CU_ASSERT_FALSE(is_allergic_to(ALLERGEN_PEANUTS, 0));
}

void test_allergic_only_to_peanuts(void) {
  CU_ASSERT_TRUE(is_allergic_to(ALLERGEN_PEANUTS, 2));
}

void test_allergic_to_peanuts_and_something_else(void) {
  CU_ASSERT_TRUE(is_allergic_to(ALLERGEN_EGGS, 7));
}

void test_allergic_to_something_but_not_peanuts(void) {
  CU_ASSERT_FALSE(is_allergic_to(ALLERGEN_PEANUTS, 5));
}

void test_allergic_to_everything_for_peanuts(void) {
  CU_ASSERT_TRUE(is_allergic_to(ALLERGEN_PEANUTS, 255));
}

void test_not_allergic_to_anything_for_shellfish(void) {
  CU_ASSERT_FALSE(is_allergic_to(ALLERGEN_SHELLFISH, 0));
}

void test_allergic_only_to_shellfish(void) {
  CU_ASSERT_TRUE(is_allergic_to(ALLERGEN_SHELLFISH, 4));
}

void test_allergic_to_shellfish_and_something_else(void) {
  CU_ASSERT_TRUE(is_allergic_to(ALLERGEN_SHELLFISH, 14));
}

void test_allergic_to_something_but_not_shellfish(void) {
  CU_ASSERT_FALSE(is_allergic_to(ALLERGEN_SHELLFISH, 10));
}

void test_allergic_to_everything_for_shellfish(void) {
  CU_ASSERT_TRUE(is_allergic_to(ALLERGEN_SHELLFISH, 255));
}

void test_not_allergic_to_anything_for_strawberries(void) {
  CU_ASSERT_FALSE(is_allergic_to(ALLERGEN_STRAWBERRIES, 0));
}

void test_allergic_only_to_strawberries(void) {
  CU_ASSERT_TRUE(is_allergic_to(ALLERGEN_STRAWBERRIES, 8));
}

void test_allergic_to_strawberries_and_something_else(void) {
  CU_ASSERT_TRUE(is_allergic_to(ALLERGEN_STRAWBERRIES, 28));
}

void test_allergic_to_something_but_not_strawberries(void) {
  CU_ASSERT_FALSE(is_allergic_to(ALLERGEN_STRAWBERRIES, 20));
}

void test_allergic_to_everything_for_strawberries(void) {
  CU_ASSERT_TRUE(is_allergic_to(ALLERGEN_STRAWBERRIES, 255));
}

void test_not_allergic_to_anything_for_tomatoes(void) {
  CU_ASSERT_FALSE(is_allergic_to(ALLERGEN_TOMATOES, 0));
}

void test_allergic_only_to_tomatoes(void) {
  CU_ASSERT_TRUE(is_allergic_to(ALLERGEN_TOMATOES, 16));
}

void test_allergic_to_tomatoes_and_something_else(void) {
  CU_ASSERT_TRUE(is_allergic_to(ALLERGEN_TOMATOES, 56));
}

void test_allergic_to_something_but_not_tomatoes(void) {
  CU_ASSERT_FALSE(is_allergic_to(ALLERGEN_TOMATOES, 40));
}

void test_allergic_to_everything_for_tomatoes(void) {
  CU_ASSERT_TRUE(is_allergic_to(ALLERGEN_TOMATOES, 255));
}

void test_not_allergic_to_anything_for_chocolate(void) {
  CU_ASSERT_FALSE(is_allergic_to(ALLERGEN_CHOCOLATE, 0));
}

void test_allergic_only_to_chocolate(void) {
  CU_ASSERT_TRUE(is_allergic_to(ALLERGEN_CHOCOLATE, 32));
}

void test_allergic_to_chocolate_and_something_else(void) {
  CU_ASSERT_TRUE(is_allergic_to(ALLERGEN_CHOCOLATE, 112));
}

void test_allergic_to_something_but_not_chocolate(void) {
  CU_ASSERT_FALSE(is_allergic_to(ALLERGEN_CHOCOLATE, 80));
}

void test_allergic_to_everything_for_chocolate(void) {
  CU_ASSERT_TRUE(is_allergic_to(ALLERGEN_CHOCOLATE, 255));
}

void test_not_allergic_to_anything_for_pollen(void) {
  CU_ASSERT_FALSE(is_allergic_to(ALLERGEN_POLLEN, 0));
}

void test_allergic_only_to_pollen(void) {
  CU_ASSERT_TRUE(is_allergic_to(ALLERGEN_POLLEN, 64));
}

void test_allergic_to_pollen_and_something_else(void) {
  CU_ASSERT_TRUE(is_allergic_to(ALLERGEN_POLLEN, 224));
}

void test_allergic_to_something_but_not_pollen(void) {
  CU_ASSERT_FALSE(is_allergic_to(ALLERGEN_POLLEN, 160));
}

void test_allergic_to_everything_for_pollen(void) {
  CU_ASSERT_TRUE(is_allergic_to(ALLERGEN_POLLEN, 255));
}

void test_not_allergic_to_anything_for_cats(void) {
  CU_ASSERT_FALSE(is_allergic_to(ALLERGEN_CATS, 0));
}

void test_allergic_only_to_cats(void) {
  CU_ASSERT_TRUE(is_allergic_to(ALLERGEN_CATS, 128));
}

void test_allergic_to_cats_and_something_else(void) {
  CU_ASSERT_TRUE(is_allergic_to(ALLERGEN_CATS, 192));
}

void test_allergic_to_something_but_not_cats(void) {
  CU_ASSERT_FALSE(is_allergic_to(ALLERGEN_CATS, 64));
}

void test_allergic_to_everything_for_cats(void) {
  CU_ASSERT_TRUE(is_allergic_to(ALLERGEN_CATS, 255));
}

void test_no_allergies(void) {
  allergen_list_t list = get_allergens(0);
  CU_ASSERT_EQUAL(0, list.count);
}

void test_just_eggs(void) {
  allergen_list_t list = get_allergens(1);
  CU_ASSERT_EQUAL(1, list.count);
  CU_ASSERT_TRUE(list.allergens[ALLERGEN_EGGS]);
}

void test_just_peanuts(void) {
  allergen_list_t list = get_allergens(2);
  CU_ASSERT_EQUAL(1, list.count);
  CU_ASSERT_TRUE(list.allergens[ALLERGEN_PEANUTS]);
}

void test_just_strawberries(void) {
  allergen_list_t list = get_allergens(8);
  CU_ASSERT_EQUAL(1, list.count);
  CU_ASSERT_TRUE(list.allergens[ALLERGEN_STRAWBERRIES]);
}

void test_eggs_and_peanuts(void) {
  allergen_list_t list = get_allergens(3);
  CU_ASSERT_EQUAL(2, list.count);
  CU_ASSERT_TRUE(list.allergens[ALLERGEN_EGGS]);
  CU_ASSERT_TRUE(list.allergens[ALLERGEN_PEANUTS]);
}

void test_more_than_eggs_but_not_peanuts(void) {
  allergen_list_t list = get_allergens(5);
  CU_ASSERT_EQUAL(2, list.count);
  CU_ASSERT_TRUE(list.allergens[ALLERGEN_EGGS]);
  CU_ASSERT_TRUE(list.allergens[ALLERGEN_SHELLFISH]);
}

void test_lots_of_stuff(void) {
  allergen_list_t list = get_allergens(248);
  CU_ASSERT_EQUAL(5, list.count);
  CU_ASSERT_TRUE(list.allergens[ALLERGEN_STRAWBERRIES]);
  CU_ASSERT_TRUE(list.allergens[ALLERGEN_TOMATOES]);
  CU_ASSERT_TRUE(list.allergens[ALLERGEN_CHOCOLATE]);
  CU_ASSERT_TRUE(list.allergens[ALLERGEN_POLLEN]);
  CU_ASSERT_TRUE(list.allergens[ALLERGEN_CATS]);
}

void test_everything(void) {
  allergen_list_t list = get_allergens(255);
  CU_ASSERT_EQUAL(8, list.count);
  CU_ASSERT_TRUE(list.allergens[ALLERGEN_EGGS]);
  CU_ASSERT_TRUE(list.allergens[ALLERGEN_PEANUTS]);
  CU_ASSERT_TRUE(list.allergens[ALLERGEN_SHELLFISH]);
  CU_ASSERT_TRUE(list.allergens[ALLERGEN_STRAWBERRIES]);
  CU_ASSERT_TRUE(list.allergens[ALLERGEN_TOMATOES]);
  CU_ASSERT_TRUE(list.allergens[ALLERGEN_CHOCOLATE]);
  CU_ASSERT_TRUE(list.allergens[ALLERGEN_POLLEN]);
  CU_ASSERT_TRUE(list.allergens[ALLERGEN_CATS]);
}

void test_no_allergen_score_parts(void) {
  allergen_list_t list = get_allergens(509);
  CU_ASSERT_EQUAL(7, list.count);
  CU_ASSERT_TRUE(list.allergens[ALLERGEN_EGGS]);
  CU_ASSERT_TRUE(list.allergens[ALLERGEN_SHELLFISH]);
  CU_ASSERT_TRUE(list.allergens[ALLERGEN_STRAWBERRIES]);
  CU_ASSERT_TRUE(list.allergens[ALLERGEN_TOMATOES]);
  CU_ASSERT_TRUE(list.allergens[ALLERGEN_CHOCOLATE]);
  CU_ASSERT_TRUE(list.allergens[ALLERGEN_POLLEN]);
  CU_ASSERT_TRUE(list.allergens[ALLERGEN_CATS]);
}

void test_no_allergen_score_parts_without_highest_valid_score(void) {
  allergen_list_t list = get_allergens(257);
  CU_ASSERT_EQUAL(1, list.count);
  CU_ASSERT_TRUE(list.allergens[ALLERGEN_EGGS]);
}

int main(void) {

  CU_initialize_registry();
  CU_pSuite suite = CU_add_suite("Allergies", 0, 0);
  CU_add_test(suite, "test_not_allergic_to_anything_for_eggs",
              test_not_allergic_to_anything_for_eggs);
  CU_add_test(suite, "test_allergic_only_to_eggs", test_allergic_only_to_eggs);
  CU_add_test(suite, "test_allergic_to_eggs_and_something_else",
              test_allergic_to_eggs_and_something_else);
  CU_add_test(suite, "test_allergic_to_something_but_not_eggs",
              test_allergic_to_something_but_not_eggs);
  CU_add_test(suite, "test_allergic_to_everything_for_eggs",
              test_allergic_to_everything_for_eggs);
  CU_add_test(suite, "test_not_allergic_to_anything_for_peanuts",
              test_not_allergic_to_anything_for_peanuts);
  CU_add_test(suite, "test_allergic_only_to_peanuts",
              test_allergic_only_to_peanuts);
  CU_add_test(suite, "test_allergic_to_peanuts_and_something_else",
              test_allergic_to_peanuts_and_something_else);
  CU_add_test(suite, "test_allergic_to_something_but_not_peanuts",
              test_allergic_to_something_but_not_peanuts);
  CU_add_test(suite, "test_allergic_to_everything_for_peanuts",
              test_allergic_to_everything_for_peanuts);
  CU_add_test(suite, "test_not_allergic_to_anything_for_shellfish",
              test_not_allergic_to_anything_for_shellfish);
  CU_add_test(suite, "test_allergic_only_to_shellfish",
              test_allergic_only_to_shellfish);
  CU_add_test(suite, "test_allergic_to_shellfish_and_something_else",
              test_allergic_to_shellfish_and_something_else);
  CU_add_test(suite, "test_allergic_to_something_but_not_shellfish",
              test_allergic_to_something_but_not_shellfish);
  CU_add_test(suite, "test_allergic_to_everything_for_shellfish",
              test_allergic_to_everything_for_shellfish);
  CU_add_test(suite, "test_not_allergic_to_anything_for_strawberries",
              test_not_allergic_to_anything_for_strawberries);
  CU_add_test(suite, "test_allergic_only_to_strawberries",
              test_allergic_only_to_strawberries);
  CU_add_test(suite, "test_allergic_to_strawberries_and_something_else",
              test_allergic_to_strawberries_and_something_else);
  CU_add_test(suite, "test_allergic_to_something_but_not_strawberries",
              test_allergic_to_something_but_not_strawberries);
  CU_add_test(suite, "test_allergic_to_everything_for_strawberries",
              test_allergic_to_everything_for_strawberries);
  CU_add_test(suite, "test_not_allergic_to_anything_for_tomatoes",
              test_not_allergic_to_anything_for_tomatoes);
  CU_add_test(suite, "test_allergic_only_to_tomatoes",
              test_allergic_only_to_tomatoes);
  CU_add_test(suite, "test_allergic_to_tomatoes_and_something_else",
              test_allergic_to_tomatoes_and_something_else);
  CU_add_test(suite, "test_allergic_to_something_but_not_tomatoes",
              test_allergic_to_something_but_not_tomatoes);
  CU_add_test(suite, "test_allergic_to_everything_for_tomatoes",
              test_allergic_to_everything_for_tomatoes);
  CU_add_test(suite, "test_not_allergic_to_anything_for_chocolate",
              test_not_allergic_to_anything_for_chocolate);
  CU_add_test(suite, "test_allergic_only_to_chocolate",
              test_allergic_only_to_chocolate);
  CU_add_test(suite, "test_allergic_to_chocolate_and_something_else",
              test_allergic_to_chocolate_and_something_else);
  CU_add_test(suite, "test_allergic_to_something_but_not_chocolate",
              test_allergic_to_something_but_not_chocolate);
  CU_add_test(suite, "test_allergic_to_everything_for_chocolate",
              test_allergic_to_everything_for_chocolate);
  CU_add_test(suite, "test_not_allergic_to_anything_for_pollen",
              test_not_allergic_to_anything_for_pollen);
  CU_add_test(suite, "test_allergic_only_to_pollen",
              test_allergic_only_to_pollen);
  CU_add_test(suite, "test_allergic_to_pollen_and_something_else",
              test_allergic_to_pollen_and_something_else);
  CU_add_test(suite, "test_allergic_to_something_but_not_pollen",
              test_allergic_to_something_but_not_pollen);
  CU_add_test(suite, "test_allergic_to_everything_for_pollen",
              test_allergic_to_everything_for_pollen);
  CU_add_test(suite, "test_not_allergic_to_anything_for_cats",
              test_not_allergic_to_anything_for_cats);
  CU_add_test(suite, "test_allergic_only_to_cats", test_allergic_only_to_cats);
  CU_add_test(suite, "test_allergic_to_cats_and_something_else",
              test_allergic_to_cats_and_something_else);
  CU_add_test(suite, "test_allergic_to_something_but_not_cats",
              test_allergic_to_something_but_not_cats);
  CU_add_test(suite, "test_allergic_to_everything_for_cats",
              test_allergic_to_everything_for_cats);
  CU_add_test(suite, "test_no_allergies", test_no_allergies);
  CU_add_test(suite, "test_just_eggs", test_just_eggs);
  CU_add_test(suite, "test_just_peanuts", test_just_peanuts);
  CU_add_test(suite, "test_just_strawberries", test_just_strawberries);
  CU_add_test(suite, "test_eggs_and_peanuts", test_eggs_and_peanuts);
  CU_add_test(suite, "test_more_than_eggs_but_not_peanuts",
              test_more_than_eggs_but_not_peanuts);
  CU_add_test(suite, "test_lots_of_stuff", test_lots_of_stuff);
  CU_add_test(suite, "test_everything", test_everything);
  CU_add_test(suite, "test_no_allergen_score_parts",
              test_no_allergen_score_parts);
  CU_add_test(suite, "test_no_allergen_score_parts_without_highest_valid_score",
              test_no_allergen_score_parts_without_highest_valid_score);
  CU_basic_run_tests();
  CU_cleanup_registry();

  return 0;
}
