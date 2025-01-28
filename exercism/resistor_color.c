#include <stdio.h>
#include <stdlib.h>
#include "resistor_color.h"

int color_code(resistor_band_t resistor){
  switch (resistor) {
  case BLACK: return 0;
  case BROWN: return 1;
  case RED: return 2;
  case ORANGE: return 3;
  case YELLOW: return 4;
  case GREEN: return 5;
  case BLUE: return 6;
  case VIOLET: return 7;
  case GREY: return 8;
  case WHITE: return 9;
  }
  return 0;
}

resistor_band_t* colors() {
  resistor_band_t* arr = (resistor_band_t*) malloc(10 * sizeof(resistor_band_t)) ;
  arr[0] = BLACK;
  arr[1] = BROWN;
  arr[2] = RED;
  arr[3] = ORANGE;
  arr[4] = YELLOW;
  arr[5] = GREEN;
  arr[6] = BLUE;
  arr[7] = VIOLET;
  arr[8] = GREY;
  arr[9] = WHITE;
  return arr;
}

int main(void) {

  int black = color_code(BLACK);
  printf("black=%d\n", black);

  int brown = color_code(BROWN);
  printf("brown=%d\n", brown);

  int red = color_code(RED);
  printf("red=%d\n", red);

  int orange = color_code(ORANGE);
  printf("orange=%d\n", orange);

  int yellow = color_code(YELLOW);
  printf("yellow=%d\n", yellow);

  int green = color_code(GREEN);
  printf("green=%d\n", green);

  int blue = color_code(BLUE);
  printf("blue=%d\n", blue);

  int violet = color_code(VIOLET);
  printf("violet=%d\n", violet);

  int grey = color_code(GREY);
  printf("grey=%d\n", grey);

  int white = color_code(WHITE);
  printf("white=%d\n", white);

  return 0;
}
