#include "perfect_numbers.h"
#include <stdio.h>

kind classify_number(int n) {
  if (n <= 0)
    return ERROR;

  int sum = 0;
  for (int i = 1; i <= (n / 2); i++) {
    if (n % i == 0) {
      sum += i;
    }
  }

  if (sum == n)
    return PERFECT_NUMBER;
  else if (sum > n)
    return ABUNDANT_NUMBER;
  else
    return DEFICIENT_NUMBER;
}

int main(void) {
  kind k = classify_number(6);
  printf("kind=%d\n", k);

  k = classify_number(12);
  printf("kind=%d\n", k);

  k = classify_number(33550336);
  printf("kind=%d\n", k);

  return 0;
}
