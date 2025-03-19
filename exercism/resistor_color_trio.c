#include "resistor_color_trio.h"
#include <math.h>
#include <stdint.h>
#include <stdio.h>

resistor_t color_code(resistor_band_t *bands) {

  long unsigned int *v = malloc(3 * sizeof(long unsigned int));
  v[0] = bands[0];
  v[1] = bands[1];
  v[2] = bands[2];

  uint64_t value = ((v[0] * 10 + v[1]) * pow(10, v[2]));

  resistor_unit_t unit;
  if (value < 1000)
    unit = OHMS;
  else if (value < 1000000)
    unit = KILOOHMS;
  else if (value < 1000000000)
    unit = MEGAOHMS;
  else
    unit = GIGAOHMS;

  resistor_t result = {(value / unit), unit};
  return result;
}

int main(void) {
  resistor_band_t three_three[] = {ORANGE, ORANGE, BLACK};
  resistor_t result = color_code(three_three);
  printf("resistor value = %d\n", result.value);
  printf("resistor unit = %d\n", result.unit);

  resistor_band_t six_eight_zero[] = {BLUE, GREY, BROWN};
  result = color_code(six_eight_zero);
  printf("resistor value = %d\n", result.value);
  printf("resistor unit = %d\n", result.unit);

  resistor_band_t two_kilo[] = {RED, BLACK, RED};
  result = color_code(two_kilo);
  printf("resistor value = %d\n", result.value);
  printf("resistor unit = %d\n", result.unit);

  resistor_band_t fifty_one_kilo[] = {GREEN, BROWN, ORANGE};
  result = color_code(fifty_one_kilo);
  printf("resistor value = %d\n", result.value);
  printf("resistor unit = %d\n", result.unit);

  resistor_band_t four_seventy[] = {YELLOW, VIOLET, YELLOW};
  result = color_code(four_seventy);
  printf("resistor value = %d\n", result.value);
  printf("resistor unit = %d\n", result.unit);

  resistor_band_t sixty_seven[] = {BLUE, VIOLET, BLUE};
  result = color_code(sixty_seven);
  printf("resistor value = %d\n", result.value);
  printf("resistor unit = %d\n", result.unit);

  resistor_band_t zeros[] = {BLACK, BLACK, BLACK};
  result = color_code(zeros);
  printf("resistor value = %d\n", result.value);
  printf("resistor unit = %d\n", result.unit);

  resistor_band_t whites[] = {WHITE, WHITE, WHITE};
  result = color_code(whites);
  printf("resistor value = %d\n", result.value);
  printf("resistor unit = %d\n", result.unit);

  resistor_band_t invalid[] = {BLACK, GREY, BLACK};
  result = color_code(invalid);
  printf("resistor value = %d\n", result.value);
  printf("resistor unit = %d\n", result.unit);

  resistor_band_t extra_colors[] = {BLUE, GREEN, YELLOW, ORANGE};
  result = color_code(extra_colors);
  printf("resistor value = %d\n", result.value);
  printf("resistor unit = %d\n", result.unit);

  return 0;
}
