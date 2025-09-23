#include "kindergarten_garden.h"
#include <ctype.h>
#include <string.h>

void fill_plants(plants_t *plants, char *split, int start, int *idx) {
  for (int i = start; i < (start + 2); i++) {
    switch (split[i]) {
    case 'C':
      (*plants).plants[(*idx)++] = CLOVER;
      break;
    case 'G':
      (*plants).plants[(*idx)++] = GRASS;
      break;
    case 'R':
      (*plants).plants[(*idx)++] = RADISHES;
      break;
    case 'V':
      (*plants).plants[(*idx)++] = VIOLETS;
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
      fill_plants(&plants, split, 0, &cnt);
    } else if (strcmp(student, "Bob") == 0) {
      fill_plants(&plants, split, 2, &cnt);
    } else if (strcmp(student, "Charlie") == 0) {
      fill_plants(&plants, split, 4, &cnt);
    } else if (strcmp(student, "David") == 0) {
      fill_plants(&plants, split, 6, &cnt);
    } else if (strcmp(student, "Eve") == 0) {
      fill_plants(&plants, split, 8, &cnt);
    } else if (strcmp(student, "Fred") == 0) {
      fill_plants(&plants, split, 10, &cnt);
    } else if (strcmp(student, "Ginny") == 0) {
      fill_plants(&plants, split, 12, &cnt);
    } else if (strcmp(student, "Harriet") == 0) {
      fill_plants(&plants, split, 14, &cnt);
    } else if (strcmp(student, "Ileana") == 0) {
      fill_plants(&plants, split, 16, &cnt);
    } else if (strcmp(student, "Joseph") == 0) {
      fill_plants(&plants, split, 18, &cnt);
    } else if (strcmp(student, "Kincaid") == 0) {
      fill_plants(&plants, split, 20, &cnt);
    } else if (strcmp(student, "Larry") == 0) {
      fill_plants(&plants, split, 22, &cnt);
    }

    split = strtok(NULL, "\n");
  }

  return plants;
}
