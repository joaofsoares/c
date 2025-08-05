#include "square_root.h"

uint32_t square_root(uint32_t n) {
  uint32_t start = 1;
  uint32_t end = n / 2;
  uint32_t result = n;

  while (start <= end) {
    uint32_t mid = (start + end) / 2;
    uint32_t square = mid * mid;

    if (square == n) {
      return mid;
    }

    if (square < n) {
      start = mid + 1;
      result = mid;
    } else {
      end = mid - 1;
    }
  }

  return result;
}
