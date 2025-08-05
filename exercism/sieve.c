#include "sieve.h"
#include <stdbool.h>
#include <stdlib.h>

uint32_t sieve(uint32_t limit, uint32_t *primes, size_t max_primes) {

  if (limit < 2 || max_primes == 0) {
    return 0;
  }

  bool bools[limit + 1];

  for (size_t i = 0; i <= limit + 1; i++) {
    bools[i] = true;
  }

  uint32_t count = 2;
  while (count < limit) {
    if (bools[count]) {
      uint32_t tmp = count * count;
      while (tmp <= limit) {
        bools[tmp] = false;
        tmp += count;
      }
    }
    count++;
  }

  count = 2;
  size_t idx = 0;
  while (count <= limit) {
    if (bools[count]) {
      primes[idx] = count;
      idx++;
    }
    count++;
  }

  idx = (idx > max_primes) ? max_primes : idx;

  return idx;
}
