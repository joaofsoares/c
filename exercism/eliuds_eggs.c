#include "eliuds_eggs.h"
#include <stdio.h>

int egg_count(int n) {
  if (n == 0)
    return 0;

  int cnt = 0;

  while (n > 0) {

    if ((n % 2) == 1)
      cnt++;

    n /= 2;
  }

  return cnt;
}

int main(void) {
  int result = egg_count(0);
  printf("result=%d\n", result);

  result = egg_count(16);
  printf("result=%d\n", result);

  result = egg_count(89);
  printf("result=%d\n", result);

  result = egg_count(2000000000);
  printf("result=%d\n", result);

  return 0;
}
