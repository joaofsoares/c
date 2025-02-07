#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "resistor_color_duo.h"

uint16_t color_code(resistor_band_t *resistor) {

  long unsigned int *t = malloc(2 * sizeof(long unsigned int));
  t[0] = resistor[0];
  t[1] = resistor[1];

  char str[3];
  sprintf(str, "%lu%lu", t[0], t[1]);

  return atoi(str);
}
