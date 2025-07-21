#include "allergies.h"
#include <stdio.h>

bool is_allergic_to(allergen_t allergen, int score) {
  if (allergen < ALLERGEN_EGGS || allergen > ALLERGEN_CATS) {
    return false;
  }

  return (score & allergen) != 0;
}

allergen_list_t get_allergens(int score) {
  while (score > ALLERGEN_COUNT) {
    score -= 256;
  }

  allergen_list_t result = {.count = 0, .allergens = {false}};

  while (score > 0) {
    if (is_allergic_to(ALLERGEN_CATS, score)) {
      score -= ALLERGEN_CATS;
      result.allergens[ALLERGEN_CATS] = true;
      result.count++;
    } else if (is_allergic_to(ALLERGEN_POLLEN, score)) {
      score -= ALLERGEN_POLLEN;
      result.allergens[ALLERGEN_POLLEN] = true;
      result.count++;
    } else if (is_allergic_to(ALLERGEN_CHOCOLATE, score)) {
      score -= ALLERGEN_CHOCOLATE;
      result.allergens[ALLERGEN_CHOCOLATE] = true;
      result.count++;
    } else if (is_allergic_to(ALLERGEN_TOMATOES, score)) {
      score -= ALLERGEN_TOMATOES;
      result.allergens[ALLERGEN_TOMATOES] = true;
      result.count++;
    } else if (is_allergic_to(ALLERGEN_STRAWBERRIES, score)) {
      score -= ALLERGEN_STRAWBERRIES;
      result.allergens[ALLERGEN_STRAWBERRIES] = true;
      result.count++;
    } else if (is_allergic_to(ALLERGEN_SHELLFISH, score)) {
      score -= ALLERGEN_SHELLFISH;
      result.allergens[ALLERGEN_SHELLFISH] = true;
      result.count++;
    } else if (is_allergic_to(ALLERGEN_PEANUTS, score)) {
      score -= ALLERGEN_PEANUTS;
      result.allergens[ALLERGEN_PEANUTS] = true;
      result.count++;
    } else if (is_allergic_to(ALLERGEN_EGGS, score)) {
      score -= ALLERGEN_EGGS;
      result.allergens[ALLERGEN_EGGS] = true;
      result.count++;
    }
  }

  return result;
}

int main(void) {
  allergen_list_t a = get_allergens(1);
  printf("Allergen count: %d\n", a.count);
  printf("Eggs: %s\n", a.allergens[ALLERGEN_EGGS] ? "Yes" : "No");

  bool is_allergic = is_allergic_to(ALLERGEN_EGGS, 0);
  printf("Is allergic to eggs: %s\n", is_allergic ? "Yes" : "No");

  return 0;
}
