#include "nth_prime.h"

bool is_prime(int n) {
  if (n <= 1) {
    return false;
  } else if (n == 2 || n == 3) {
    return true;
  } else {
    for (int i = 2; i < n; i++) {
      if (n % i == 0) {
        return false;
      }
    }
  }
  return true;
}

uint32_t nth(uint32_t n) {
  if (n == 0) {
    return 0;
  }

  int num = 2;

  while (n > 0) {
    if (is_prime(num)) {
      n--;
    }
    num++;
  }

  return num - 1;
}
