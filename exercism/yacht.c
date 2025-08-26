#include "yatch.h"

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

int calc_full_house(dice_t dice) { return 0; }

int calc_four_kind(dice_t dice) { return 0; }

int calc_little_straight(dice_t dice) { return 0; }

int calc_big_straight(dice_t dice) { return 0; }

int calc_choice(dice_t dice) { return 0; }

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
