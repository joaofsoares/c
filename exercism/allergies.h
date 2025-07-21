#ifndef _ALLERGIES_H_
#define _ALLERGIES_H_

#include <stdbool.h>

typedef enum {
  ALLERGEN_EGGS = 1,
  ALLERGEN_PEANUTS = 2,
  ALLERGEN_SHELLFISH = 4,
  ALLERGEN_STRAWBERRIES = 8,
  ALLERGEN_TOMATOES = 16,
  ALLERGEN_CHOCOLATE = 32,
  ALLERGEN_POLLEN = 64,
  ALLERGEN_CATS = 128,
  ALLERGEN_COUNT = 255,
} allergen_t;

typedef struct {
  int count;
  bool allergens[ALLERGEN_COUNT];
} allergen_list_t;

bool is_allergic_to(allergen_t allergen, int score);

allergen_list_t get_allergens(int score);

#endif
