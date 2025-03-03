#include "dnd_character.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int ability(void) {
  int sum = 0;
  int min;

  for (int j = 0; j < 4; j++) {
    int n = rand() % (6 - 1 + 1) + 1;
    if (j == 0) {
      min = n;
    } else if (n < min) {
      min = n;
    }
    sum += n;
  }

  return sum - min;
}

int modifier(int score) { return floor((double)(score - 10) / 2); }

dnd_character_t make_dnd_character(void) {

  dnd_character_t character;

  character.strength = ability();
  character.dexterity = ability();
  character.constitution = ability();
  character.intelligence = ability();
  character.wisdom = ability();
  character.charisma = ability();

  character.hitpoints = 10 + modifier(character.constitution);

  return character;
}

int main(void) {
  int result = modifier(3);
  printf("result=%d\n", result);
  return 0;
}
