#include "hamming.h"
#include <stdio.h>
#include <string.h>

int compute(const char *lhs, const char *rhs) {
  size_t lhs_size = strlen(lhs);
  size_t rhs_size = strlen(rhs);

  int cnt = 0;

  if (lhs_size == rhs_size) {
    for (size_t i = 0; i < lhs_size; i++)
      if (lhs[i] != rhs[i])
        cnt++;

    return cnt;
  }

  return -1;
}

int main(void) {
  int expected = 0;
  int result = compute("", "");
  printf("expect == result = %d\n", expected == result);

  expected = 0;
  result = compute("A", "A");
  printf("expect == result = %d\n", expected == result);

  expected = 1;
  result = compute("G", "T");
  printf("expect == result = %d\n", expected == result);

  expected = 0;
  result = compute("GGACTGAAATCTG", "GGACTGAAATCTG");
  printf("expect == result = %d\n", expected == result);

  expected = 9;
  result = compute("GGACGGATTCTG", "AGGACGGATTCT");
  printf("expect == result = %d\n", expected == result);

  expected = -1;
  result = compute("AATG", "AAA");
  printf("expect == result = %d\n", expected == result);
}
