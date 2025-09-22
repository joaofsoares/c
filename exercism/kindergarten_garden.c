#include "kindergarten_garden.h"
#include <ctype.h>
#include <stdio.h>
#include <string.h>

void fill_plants(plants_t *plants, int *cnt, char *split, int start, int end) {
  for (size_t i = start; i < end; i++) {
    switch (split[i]) {
    case 'C':
      (*plants).plants[(*cnt)++] = CLOVER;
      break;
    case 'G':
      (*plants).plants[(*cnt)++] = GRASS;
      break;
    case 'R':
      (*plants).plants[(*cnt)++] = RADISHES;
      break;
    case 'V':
      (*plants).plants[(*cnt)++] = VIOLETS;
      break;
    }
  }
}

plants_t plants(const char *diagram, const char *student) {
  size_t diagram_size = strlen(diagram);

  char diagram_tmp[diagram_size];
  strcpy(diagram_tmp, diagram);

  char *split = strtok(diagram_tmp, "\n");

  plants_t plants;
  int cnt = 0;

  while (split) {

    if (strcmp(student, "Alice") == 0) {
      fill_plants(&plants, &cnt, split, 0, 2);
    } else if (strcmp(student, "Bob") == 0) {
      fill_plants(&plants, &cnt, split, 2, 4);
    } else if (strcmp(student, "Charlie") == 0) {
      fill_plants(&plants, &cnt, split, 4, 6);
    } else if (strcmp(student, "David") == 0) {
      fill_plants(&plants, &cnt, split, 6, 8);
    } else if (strcmp(student, "Eve") == 0) {
      fill_plants(&plants, &cnt, split, 8, 10);
    } else if (strcmp(student, "Fred") == 0) {
      fill_plants(&plants, &cnt, split, 10, 12);
    } else if (strcmp(student, "Ginny") == 0) {
      fill_plants(&plants, &cnt, split, 12, 14);
    } else if (strcmp(student, "Harriet") == 0) {
      fill_plants(&plants, &cnt, split, 14, 16);
    } else if (strcmp(student, "Ileana") == 0) {
      fill_plants(&plants, &cnt, split, 16, 18);
    } else if (strcmp(student, "Joseph") == 0) {
      fill_plants(&plants, &cnt, split, 18, 20);
    } else if (strcmp(student, "Kincaid") == 0) {
      fill_plants(&plants, &cnt, split, 20, 22);
    } else if (strcmp(student, "Larry") == 0) {
      fill_plants(&plants, &cnt, split, 22, 24);
    }

    split = strtok(NULL, "\n");
  }

  return plants;
}
