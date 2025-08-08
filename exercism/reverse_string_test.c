#include "../Unity/src/unity.h"
#include "reverse_string.c"
#include <stdlib.h>

void setUp(void) {}

void tearDown(void) {}

void test_reverse(char *phrase, char *expected) {
  char *actual = reverse(phrase);

  TEST_ASSERT_EQUAL_STRING(expected, actual);

  free(actual);
}

void test_an_empty_string(void) { test_reverse("", ""); }

void test_a_word(void) { test_reverse("robot", "tobor"); }

void test_a_capitalized_word(void) { test_reverse("Ramen", "nemaR"); }

void test_a_sentence_with_punctuation(void) {

  test_reverse("I'm hungry!", "!yrgnuh m'I");
}

void test_a_palindrome(void) { test_reverse("racecar", "racecar"); }

void test_an_even_sized_word(void) { test_reverse("drawer", "reward"); }

int main(void) {
  UNITY_BEGIN();

  RUN_TEST(test_an_empty_string);
  RUN_TEST(test_a_word);
  RUN_TEST(test_a_capitalized_word);
  RUN_TEST(test_a_sentence_with_punctuation);
  RUN_TEST(test_a_palindrome);
  RUN_TEST(test_an_even_sized_word);

  return UNITY_END();
}
