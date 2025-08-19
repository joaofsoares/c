#include "prime_factors.h"

size_t find_factors(uint64_t n, uint64_t factors[MAXFACTORS]) {
  size_t cnt = 0;

  if (n == 0 && cnt < MAXFACTORS) {
    factors[cnt++] = 1;
  }

  size_t divisor = 2;

  while (n > 1) {
    while (n % divisor == 0) {
      n /= divisor;
      factors[cnt++] = divisor;
    }

    divisor += (divisor == 2) ? 1 : 2;

    if (divisor * divisor > n && n > 1) {
      factors[cnt++] = n;
      break;
    }
  }

  return cnt;
}
