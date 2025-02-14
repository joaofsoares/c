#include "binary.h"
#include <string.h>
#include <stdio.h>
#include <math.h>

int convert(const char *input) {
  size_t input_size = strlen(input);
  int result = 0;
  int cnt = input_size - 1;

  for (size_t i = 0; i < input_size; i++) {
    if (input[i] != '0' && input[i] != '1')
      return INVALID;

    result += (input[i] - '0') * (pow(2, cnt));
    cnt--;
  }

  return result;
}

int main(void) {
  int result = convert("10");
  printf("result=%d\n", result);

  result = convert("01201");
  printf("result=%d\n", result);

  result = convert("000011111");
  printf("result=%d\n", result);

  return 0;
}
