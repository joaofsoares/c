#include <math.h>
#include <stdio.h>

#include "darts.h"

uint8_t score(coordinate_t coordinate) {

  float distance = sqrt(coordinate.x * coordinate.x +
			coordinate.y * coordinate.y);

  if (distance <= 1)
    return 10;
  else if (distance <= 5)
    return 5;
  else if (distance <= 10)
    return 1;
  else
    return 0;

}

int main(void) {
  coordinate_t coord = { -9.0, 9.0 };
  uint8_t result = score(coord);
  printf("result = %d\n", result);

  coord.x = 0.0;
  coord.y = 10.0;
  result = score(coord);
  printf("result = %d\n", result);

  coord.x = -5.0;
  coord.y = 0.0;
  result = score(coord);
  printf("result = %d\n", result);

  coord.x = 0.0;
  coord.y = -1.0;
  result = score(coord);
  printf("result = %d\n", result);

  coord.x = 0.0;
  coord.y = 0.0;
  result = score(coord);
  printf("result = %d\n", result);

  coord.x = -0.1;
  coord.y = -0.1;
  result = score(coord);
  printf("result = %d\n", result);

  coord.x = 0.7;
  coord.y = 0.7;
  result = score(coord);
  printf("result = %d\n", result);

  coord.x = 0.8;
  coord.y = -0.8;
  result = score(coord);
  printf("result = %d\n", result);

  return 0;
}
