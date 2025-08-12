#include "/opt/homebrew/Cellar/cunit/2.1-3/include/CUnit/Basic.h"
#include "/opt/homebrew/Cellar/cunit/2.1-3/include/CUnit/CUnit.h"
#include "clock.c"

void test_create(clock_t expected, int hour, int minute) {

  clock_t actual = clock_create(hour, minute);

  CU_ASSERT_STRING_EQUAL(expected.text, actual.text);
}

void test_add(clock_t expected, int hour, int minute, int minute_add) {

  clock_t actual = clock_create(hour, minute);

  actual = clock_add(actual, minute_add);

  CU_ASSERT_STRING_EQUAL(expected.text, actual.text);
}

void test_subtract(clock_t expected, int hour, int minute,
                   int minute_subtract) {

  clock_t actual = clock_create(hour, minute);

  actual = clock_subtract(actual, minute_subtract);

  CU_ASSERT_STRING_EQUAL(expected.text, actual.text);
}

void test_compare(bool expected, int a_hour, int a_minute, int b_hour,
                  int b_minute) {

  clock_t a = clock_create(a_hour, a_minute);

  clock_t b = clock_create(b_hour, b_minute);

  bool actual = clock_is_equal(a, b);

  if (expected) {

    CU_ASSERT_TRUE(actual);

  } else {

    CU_ASSERT_FALSE(actual);
  }
}

void test_on_the_hour(void) {

  int hour = 8, minute = 0;

  clock_t expected = {"08:00"};

  test_create(expected, hour, minute);
}

void test_past_the_hour(void) {

  int hour = 11, minute = 9;

  clock_t expected = {"11:09"};

  test_create(expected, hour, minute);
}

void test_midnight_is_zero_hours(void) {

  int hour = 24, minute = 0;

  clock_t expected = {"00:00"};

  test_create(expected, hour, minute);
}

void test_hour_rolls_over(void) {

  int hour = 25, minute = 0;

  clock_t expected = {"01:00"};

  test_create(expected, hour, minute);
}

void test_hour_rolls_over_continuously(void) {

  int hour = 100, minute = 0;

  clock_t expected = {"04:00"};

  test_create(expected, hour, minute);
}

void test_sixty_minutes_is_next_hour(void) {

  int hour = 1, minute = 60;

  clock_t expected = {"02:00"};

  test_create(expected, hour, minute);
}

void test_minutes_roll_over(void) {

  int hour = 0, minute = 160;

  clock_t expected = {"02:40"};

  test_create(expected, hour, minute);
}

void test_minutes_roll_over_continuously(void) {

  int hour = 0, minute = 1723;

  clock_t expected = {"04:43"};

  test_create(expected, hour, minute);
}

void test_hour_and_minutes_roll_over(void) {

  int hour = 25, minute = 160;

  clock_t expected = {"03:40"};

  test_create(expected, hour, minute);
}

void test_hour_and_minutes_roll_over_continuously(void) {

  int hour = 201, minute = 3001;

  clock_t expected = {"11:01"};

  test_create(expected, hour, minute);
}

void test_hour_and_minutes_roll_over_to_exactly_midnight(void) {

  int hour = 72, minute = 8640;

  clock_t expected = {"00:00"};

  test_create(expected, hour, minute);
}

void test_negative_hour(void) {

  int hour = -1, minute = 15;

  clock_t expected = {"23:15"};

  test_create(expected, hour, minute);
}

void test_negative_hour_rolls_over(void) {

  int hour = -25, minute = 0;

  clock_t expected = {"23:00"};

  test_create(expected, hour, minute);
}

void test_negative_hour_rolls_over_continuously(void) {

  int hour = -91, minute = 0;

  clock_t expected = {"05:00"};

  test_create(expected, hour, minute);
}

void test_negative_minutes(void) {

  int hour = 1, minute = -40;

  clock_t expected = {"00:20"};

  test_create(expected, hour, minute);
}

void test_negative_minutes_roll_over(void) {

  int hour = 1, minute = -160;

  clock_t expected = {"22:20"};

  test_create(expected, hour, minute);
}

void test_negative_minutes_roll_over_continuously(void) {

  int hour = 1, minute = -4820;

  clock_t expected = {"16:40"};

  test_create(expected, hour, minute);
}

void test_negative_sixty_minutes_is_previous_hour(void) {

  int hour = 2, minute = -60;

  clock_t expected = {"01:00"};

  test_create(expected, hour, minute);
}

void test_negative_hour_and_minutes_both_roll_over(void) {

  int hour = -25, minute = -160;

  clock_t expected = {"20:20"};

  test_create(expected, hour, minute);
}

void test_negative_hour_and_minutes_both_roll_over_continuously(void) {

  int hour = -121, minute = -5810;

  clock_t expected = {"22:10"};

  test_create(expected, hour, minute);
}

void test_add_minutes(void) {

  int hour = 10, minute = 0, minute_add = 3;

  clock_t expected = {"10:03"};

  test_add(expected, hour, minute, minute_add);
}

void test_add_no_minutes(void) {

  int hour = 6, minute = 41, minute_add = 0;

  clock_t expected = {"06:41"};

  test_add(expected, hour, minute, minute_add);
}

void test_add_to_next_hour(void) {

  int hour = 0, minute = 45, minute_add = 40;

  clock_t expected = {"01:25"};

  test_add(expected, hour, minute, minute_add);
}

void test_add_more_than_one_hour(void) {

  int hour = 10, minute = 0, minute_add = 61;

  clock_t expected = {"11:01"};

  test_add(expected, hour, minute, minute_add);
}

void test_add_more_than_two_hours_with_carry(void) {

  int hour = 0, minute = 45, minute_add = 160;

  clock_t expected = {"03:25"};

  test_add(expected, hour, minute, minute_add);
}

void test_add_across_midnight(void) {

  int hour = 23, minute = 59, minute_add = 2;

  clock_t expected = {"00:01"};

  test_add(expected, hour, minute, minute_add);
}

void test_add_more_than_one_day(void) {

  int hour = 5, minute = 32, minute_add = 1500;

  clock_t expected = {"06:32"};

  test_add(expected, hour, minute, minute_add);
}

void test_add_more_than_two_days(void) {

  int hour = 1, minute = 1, minute_add = 3500;

  clock_t expected = {"11:21"};

  test_add(expected, hour, minute, minute_add);
}

void test_subtract_minutes(void) {

  int hour = 10, minute = 3, minute_subtract = 3;

  clock_t expected = {"10:00"};

  test_subtract(expected, hour, minute, minute_subtract);
}

void test_subtract_to_previous_hour(void) {

  int hour = 10, minute = 3, minute_subtract = 30;

  clock_t expected = {"09:33"};

  test_subtract(expected, hour, minute, minute_subtract);
}

void test_subtract_more_than_an_hour(void) {

  int hour = 10, minute = 3, minute_subtract = 70;

  clock_t expected = {"08:53"};

  test_subtract(expected, hour, minute, minute_subtract);
}

void test_subtract_across_midnight(void) {

  int hour = 0, minute = 3, minute_subtract = 4;

  clock_t expected = {"23:59"};

  test_subtract(expected, hour, minute, minute_subtract);
}

void test_subtract_more_than_two_hours(void) {

  int hour = 0, minute = 0, minute_subtract = 160;

  clock_t expected = {"21:20"};

  test_subtract(expected, hour, minute, minute_subtract);
}

void test_subtract_more_than_two_hours_with_borrow(void) {

  int hour = 6, minute = 15, minute_subtract = 160;

  clock_t expected = {"03:35"};

  test_subtract(expected, hour, minute, minute_subtract);
}

void test_subtract_more_than_one_day(void) {

  int hour = 5, minute = 32, minute_subtract = 1500;

  clock_t expected = {"04:32"};

  test_subtract(expected, hour, minute, minute_subtract);
}

void test_subtract_more_than_two_days(void) {

  int hour = 2, minute = 20, minute_subtract = 3000;

  clock_t expected = {"00:20"};

  test_subtract(expected, hour, minute, minute_subtract);
}

void test_compare_clocks_with_same_time(void) {

  int a_hour = 15, a_minute = 37;

  int b_hour = 15, b_minute = 37;

  bool expected = true;

  test_compare(expected, a_hour, a_minute, b_hour, b_minute);
}

void test_compare_clocks_a_minute_apart(void) {

  int a_hour = 15, a_minute = 36;

  int b_hour = 15, b_minute = 37;

  bool expected = false;

  test_compare(expected, a_hour, a_minute, b_hour, b_minute);
}

void test_compare_clocks_an_hour_apart(void) {

  int a_hour = 14, a_minute = 37;

  int b_hour = 15, b_minute = 37;

  bool expected = false;

  test_compare(expected, a_hour, a_minute, b_hour, b_minute);
}

void test_compare_clocks_with_hour_overflow(void) {

  int a_hour = 10, a_minute = 37;

  int b_hour = 34, b_minute = 37;

  bool expected = true;

  test_compare(expected, a_hour, a_minute, b_hour, b_minute);
}

void test_compare_clocks_with_hour_overflow_by_several_days(void) {

  int a_hour = 3, a_minute = 11;

  int b_hour = 99, b_minute = 11;

  bool expected = true;

  test_compare(expected, a_hour, a_minute, b_hour, b_minute);
}

void test_compare_clocks_with_negative_hour(void) {

  int a_hour = 22, a_minute = 40;

  int b_hour = -2, b_minute = 40;

  bool expected = true;

  test_compare(expected, a_hour, a_minute, b_hour, b_minute);
}

void test_compare_clocks_with_negative_hour_that_wraps(void) {

  int a_hour = 17, a_minute = 3;

  int b_hour = -31, b_minute = 3;

  bool expected = true;

  test_compare(expected, a_hour, a_minute, b_hour, b_minute);
}

void test_compare_clocks_with_negative_hour_that_wraps_multiple_times(void) {

  int a_hour = 13, a_minute = 49;

  int b_hour = -83, b_minute = 49;

  bool expected = true;

  test_compare(expected, a_hour, a_minute, b_hour, b_minute);
}

void test_compare_clocks_with_minute_overflow(void) {

  int a_hour = 0, a_minute = 1;

  int b_hour = 0, b_minute = 1441;

  bool expected = true;

  test_compare(expected, a_hour, a_minute, b_hour, b_minute);
}

void test_compare_clocks_with_minute_overflow_by_several_days(void) {

  int a_hour = 2, a_minute = 2;

  int b_hour = 2, b_minute = 4322;

  bool expected = true;

  test_compare(expected, a_hour, a_minute, b_hour, b_minute);
}

void test_compare_clocks_with_negative_minute(void) {

  int a_hour = 2, a_minute = 40;

  int b_hour = 3, b_minute = -20;

  bool expected = true;

  test_compare(expected, a_hour, a_minute, b_hour, b_minute);
}

void test_compare_clocks_with_negative_minute_that_wraps(void) {

  int a_hour = 4, a_minute = 10;

  int b_hour = 5, b_minute = -1490;

  bool expected = true;

  test_compare(expected, a_hour, a_minute, b_hour, b_minute);
}

void test_compare_clocks_with_negative_minute_that_wraps_multiple_times(void) {

  int a_hour = 6, a_minute = 15;

  int b_hour = 6, b_minute = -4305;

  bool expected = true;

  test_compare(expected, a_hour, a_minute, b_hour, b_minute);
}

void test_compare_clocks_with_negative_hours_and_minute(void) {

  int a_hour = 7, a_minute = 32;

  int b_hour = -12, b_minute = -268;

  bool expected = true;

  test_compare(expected, a_hour, a_minute, b_hour, b_minute);
}

void test_compare_clocks_with_negative_hours_and_minute_that_wrap(void) {

  int a_hour = 18, a_minute = 7;

  int b_hour = -54, b_minute = -11513;

  bool expected = true;

  test_compare(expected, a_hour, a_minute, b_hour, b_minute);
}

void test_compare_full_clock_and_zeroed_clock(void) {

  int a_hour = 24, a_minute = 0;

  int b_hour = 0, b_minute = 0;

  bool expected = true;

  test_compare(expected, a_hour, a_minute, b_hour, b_minute);
}

int main(void) {

  CU_initialize_registry();
  CU_pSuite suite = CU_add_suite("Clock Tests", 0, 0);

  CU_add_test(suite, "test_on_the_hour", test_on_the_hour);

  CU_add_test(suite, "test_past_the_hour", test_past_the_hour);

  CU_add_test(suite, "test_midnight_is_zero_hours",
              test_midnight_is_zero_hours);

  CU_add_test(suite, "test_hour_rolls_over", test_hour_rolls_over);

  CU_add_test(suite, "test_hour_rolls_over_continuously",
              test_hour_rolls_over_continuously);

  CU_add_test(suite, "test_sixty_minutes_is_next_hour",
              test_sixty_minutes_is_next_hour);

  CU_add_test(suite, "test_minutes_roll_over", test_minutes_roll_over);

  CU_add_test(suite, "test_minutes_roll_over_continuously",
              test_minutes_roll_over_continuously);

  CU_add_test(suite, "test_hour_and_minutes_roll_over",
              test_hour_and_minutes_roll_over);

  CU_add_test(suite, "test_hour_and_minutes_roll_over_continuously",
              test_hour_and_minutes_roll_over_continuously);

  CU_add_test(suite, "test_hour_and_minutes_roll_over_to_exactly_midnight",
              test_hour_and_minutes_roll_over_to_exactly_midnight);

  CU_add_test(suite, "test_negative_hour", test_negative_hour);

  CU_add_test(suite, "test_negative_hour_rolls_over",
              test_negative_hour_rolls_over);

  CU_add_test(suite, "test_negative_hour_rolls_over_continuously",
              test_negative_hour_rolls_over_continuously);

  CU_add_test(suite, "test_negative_minutes", test_negative_minutes);

  CU_add_test(suite, "test_negative_minutes_roll_over",
              test_negative_minutes_roll_over);

  CU_add_test(suite, "test_negative_minutes_roll_over_continuously",
              test_negative_minutes_roll_over_continuously);

  CU_add_test(suite, "test_negative_sixty_minutes_is_previous_hour",
              test_negative_sixty_minutes_is_previous_hour);

  CU_add_test(suite, "test_negative_hour_and_minutes_both_roll_over",
              test_negative_hour_and_minutes_both_roll_over);

  CU_add_test(suite,
              "test_negative_hour_and_minutes_both_roll_over_continuously",
              test_negative_hour_and_minutes_both_roll_over_continuously);

  CU_add_test(suite, "test_add_minutes", test_add_minutes);

  CU_add_test(suite, "test_add_no_minutes", test_add_no_minutes);

  CU_add_test(suite, "test_add_to_next_hour", test_add_to_next_hour);

  CU_add_test(suite, "test_add_more_than_one_hour",
              test_add_more_than_one_hour);

  CU_add_test(suite, "test_add_more_than_two_hours_with_carry",
              test_add_more_than_two_hours_with_carry);

  CU_add_test(suite, "test_add_across_midnight", test_add_across_midnight);

  CU_add_test(suite, "test_add_more_than_one_day", test_add_more_than_one_day);

  CU_add_test(suite, "test_add_more_than_two_days",
              test_add_more_than_two_days);

  CU_add_test(suite, "test_subtract_minutes", test_subtract_minutes);

  CU_add_test(suite, "test_subtract_to_previous_hour",
              test_subtract_to_previous_hour);

  CU_add_test(suite, "test_subtract_more_than_an_hour",
              test_subtract_more_than_an_hour);

  CU_add_test(suite, "test_subtract_across_midnight",
              test_subtract_across_midnight);

  CU_add_test(suite, "test_subtract_more_than_two_hours",
              test_subtract_more_than_two_hours);

  CU_add_test(suite, "test_subtract_more_than_two_hours_with_borrow",
              test_subtract_more_than_two_hours_with_borrow);

  CU_add_test(suite, "test_subtract_more_than_one_day",
              test_subtract_more_than_one_day);

  CU_add_test(suite, "test_subtract_more_than_two_days",
              test_subtract_more_than_two_days);

  CU_add_test(suite, "test_compare_clocks_with_same_time",
              test_compare_clocks_with_same_time);

  CU_add_test(suite, "test_compare_clocks_a_minute_apart",
              test_compare_clocks_a_minute_apart);

  CU_add_test(suite, "test_compare_clocks_an_hour_apart",
              test_compare_clocks_an_hour_apart);

  CU_add_test(suite, "test_compare_clocks_with_hour_overflow",
              test_compare_clocks_with_hour_overflow);

  CU_add_test(suite, "test_compare_clocks_with_hour_overflow_by_several_days",
              test_compare_clocks_with_hour_overflow_by_several_days);

  CU_add_test(suite, "test_compare_clocks_with_negative_hour",
              test_compare_clocks_with_negative_hour);

  CU_add_test(suite, "test_compare_clocks_with_negative_hour_that_wraps",
              test_compare_clocks_with_negative_hour_that_wraps);

  CU_add_test(
      suite, "test_compare_clocks_with_negative_hour_that_wraps_multiple_times",
      test_compare_clocks_with_negative_hour_that_wraps_multiple_times);

  CU_add_test(suite, "test_compare_clocks_with_minute_overflow",
              test_compare_clocks_with_minute_overflow);

  CU_add_test(suite, "test_compare_clocks_with_minute_overflow_by_several_days",
              test_compare_clocks_with_minute_overflow_by_several_days);

  CU_add_test(suite, "test_compare_clocks_with_negative_minute",
              test_compare_clocks_with_negative_minute);

  CU_add_test(suite, "test_compare_clocks_with_negative_minute_that_wraps",
              test_compare_clocks_with_negative_minute_that_wraps);

  CU_add_test(
      suite,
      "test_compare_clocks_with_negative_minute_that_wraps_multiple_times",
      test_compare_clocks_with_negative_minute_that_wraps_multiple_times);

  CU_add_test(suite, "test_compare_clocks_with_negative_hours_and_minute",
              test_compare_clocks_with_negative_hours_and_minute);

  CU_add_test(suite,
              "test_compare_clocks_with_negative_hours_and_minute_that_wrap",
              test_compare_clocks_with_negative_hours_and_minute_that_wrap);

  CU_add_test(suite, "test_compare_full_clock_and_zeroed_clock",
              test_compare_full_clock_and_zeroed_clock);

  CU_basic_run_tests();
  CU_cleanup_registry();

  return 0;
}
