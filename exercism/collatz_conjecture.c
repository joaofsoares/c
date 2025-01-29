#include <stdio.h>
#include "collatz_conjecture.h"

int steps(int start) {
  if (start <= 0) {
    return ERROR_VALUE;
  }

  int cnt = 0;

  while (start > 1) {
    if (start % 2 == 0)
      start = start / 2;
    else
      start = (start * 3) + 1;

    cnt++;
  }

  return cnt;
}

int main(void) {
  int result_from_12 = steps(12);
  printf("result from 12 = %d\n", result_from_12);

  int result_from_1 = steps(1);
  printf("result from 1 = %d\n", result_from_1);

  int result_from_16 = steps(16);
  printf("result from 16 = %d\n", result_from_16);

  int result_from_1000000 = steps(1000000);
  printf("result from 1000000 = %d\n", result_from_1000000);

  int error = steps(0);
  printf("error = %d\n", error);

  int error_negative = steps(-15);
  printf("error negative = %d\n", error_negative);

  return 0;
}
