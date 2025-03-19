#ifndef RESISTOR_COLOR_TRIO_H
#define RESISTOR_COLOR_TRIO_H

#include <stdint.h>
#include <stdlib.h>

typedef enum {
  BLACK,
  BROWN,
  RED,
  ORANGE,
  YELLOW,
  GREEN,
  BLUE,
  VIOLET,
  GREY,
  WHITE
} resistor_band_t;

typedef enum {
  OHMS = 1,
  KILOOHMS = 1000,
  MEGAOHMS = 1000000,
  GIGAOHMS = 1000000000
} resistor_unit_t;

typedef struct {
  uint16_t value;
  resistor_unit_t unit;
} resistor_t;

resistor_t color_code(resistor_band_t *);

#endif
