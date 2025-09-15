#ifndef YACHT_H
#define YACHT_H

typedef enum {
  ONES,
  TWOS,
  THREES,
  FOURS,
  FIVES,
  SIXES,
  FULL_HOUSE,
  FOUR_OF_A_KIND,
  LITTLE_STRAIGHT,
  BIG_STRAIGHT,
  CHOICE,
  YACHT
} category_t;

typedef struct {
  int faces[5];
} dice_t;

typedef struct {
  int n;
  int cnt;
} number_t;

number_t *create_number_type();

int calc_number(dice_t, int);

int calc_yacht(dice_t);

int calc_full_house(dice_t);

int calc_four_kind(dice_t);

int calc_straight(dice_t, int);

int calc_choice(dice_t);

int score(dice_t, category_t);

#endif
