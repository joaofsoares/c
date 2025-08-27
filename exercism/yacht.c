#include "yacht.h"
#include <stdbool.h>
#include <stdlib.h>

number_t *create_number_type() {
  number_t *nums = (number_t *)malloc(sizeof(number_t) * 6);
  for (int i = 0; i < 6; i++) {
    nums[i] = (number_t){(i + 1), 0};
  }
  return nums;
}

int calc_number(dice_t dice, int n) {
  int cnt = 0;
  for (int i = 0; i < 5; i++) {
    if (dice.faces[i] == n) {
      cnt++;
    }
  }
  return cnt * n;
}

int calc_yacht(dice_t dice) {
  for (int i = 1; i < 5; i++) {
    if (dice.faces[i] != dice.faces[0]) {
      return 0;
    }
  }
  return 50;
}

int calc_full_house(dice_t dice) {
  number_t *n = create_number_type();

  for (int i = 0; i < 5; i++) {
    n[dice.faces[i] - 1].cnt++;
  }

  int result = 0;
  bool has_two = false;
  bool has_three = false;

  for (int i = 0; i < 6; i++) {
    if (n[i].cnt == 2) {
      has_two = true;
      result += n[i].n * n[i].cnt;
    }
    if (n[i].cnt == 3) {
      has_three = true;
      result += n[i].n * n[i].cnt;
    }
  }

  free(n);
  return (has_two && has_three) ? result : 0;
}

int calc_four_kind(dice_t dice) {
  number_t *n = create_number_type();

  for (int i = 0; i < 5; i++) {
    n[dice.faces[i] - 1].cnt++;
  }

  int result = 0;
  for (int i = 0; i < 6; i++) {
    if (n[i].cnt >= 4) {
      result += n[i].n * 4;
    }
  }

  free(n);
  return result;
}

int calc_little_straight(dice_t dice) {
  number_t *n = create_number_type();

  for (int i = 0; i < 5; i++) {
    n[dice.faces[i] - 1].cnt++;
  }

  int result = 0;
  if (n[0].cnt == 1 && n[1].cnt == 1 && n[2].cnt == 1 && n[3].cnt == 1 &&
      n[4].cnt == 1) {
    result = 30;
  }

  free(n);
  return result;
}

int calc_big_straight(dice_t dice) {
  number_t *n = create_number_type();

  for (int i = 0; i < 5; i++) {
    n[dice.faces[i] - 1].cnt++;
  }

  int result = 0;
  if (n[1].cnt == 1 && n[2].cnt == 1 && n[3].cnt == 1 && n[4].cnt == 1 &&
      n[5].cnt == 1) {
    result = 30;
  }

  free(n);
  return result;
}

int calc_choice(dice_t dice) {
  int result = 0;
  for (int i = 0; i < 5; i++) {
    result += dice.faces[i];
  }
  return result;
}

int score(dice_t dice, category_t category) {
  switch (category) {
  case YACHT:
    return calc_yacht(dice);
    break;
  case FULL_HOUSE:
    return calc_full_house(dice);
    break;
  case FOUR_OF_A_KIND:
    return calc_four_kind(dice);
    break;
  case LITTLE_STRAIGHT:
    return calc_little_straight(dice);
    break;
  case BIG_STRAIGHT:
    return calc_big_straight(dice);
    break;
  case CHOICE:
    return calc_choice(dice);
    break;
  case ONES:
    return calc_number(dice, 1);
    break;
  case TWOS:
    return calc_number(dice, 2);
    break;
  case THREES:
    return calc_number(dice, 3);
    break;
  case FOURS:
    return calc_number(dice, 4);
    break;
  case FIVES:
    return calc_number(dice, 5);
    break;
  case SIXES:
    return calc_number(dice, 6);
    break;
  default:
    return 0;
  }
}
