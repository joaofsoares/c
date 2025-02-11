#include "space_age.h"
#include <stdio.h>

const float EARTH_SECONDS_PER_YEAR = 31557600.0;

float age(planet_t planet, int64_t seconds) {

  float planet_seconds = seconds / EARTH_SECONDS_PER_YEAR;

  switch (planet) {
  case MERCURY:
    return (planet_seconds / 0.2408467);
  case VENUS:
    return (planet_seconds / 0.61519726);
  case EARTH:
    return (planet_seconds / 1.0);
  case MARS:
    return (planet_seconds / 1.8808158);
  case JUPITER:
    return (planet_seconds / 11.862615);
  case SATURN:
    return (planet_seconds / 29.447498);
  case URANUS:
    return (planet_seconds / 84.016846);
  case NEPTUNE:
    return (planet_seconds / 164.79132);
  default:
    return -1;
  }
}

int main(void) {
  float result = age(EARTH, 1000000000);
  printf("result=%.2f\n", result);
  return 0;
}
