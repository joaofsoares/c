#include "grains.h"

uint64_t square(uint8_t index) {
  if (index > 0 && index < 65) {
    uint64_t grains = 1;
    for (int i = 1; i < index; i++) {
      grains *= 2;
     }
    return grains;
  }

  return 0;
}

uint64_t total(void) {
  unsigned int i;
  uint64_t sum = 0;
  for (i = 1; i <= 64; i++) {
    sum += 1ULL << i;
  }
  return sum;
}
