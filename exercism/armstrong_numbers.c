#include "armstrong_numbers.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool is_armstrong_number(int candidate) {
  char str[20];
  sprintf(str, "%d", candidate);

  size_t str_size = strlen(str);
  int a = 0;
  for (size_t i = 0; i < str_size; i++) {
    a += pow(str[i] - '0', str_size);
  }

  return candidate == a;
}

int main(void) {

  bool a = is_armstrong_number(9);
  printf("a = %d\n", a);

  a = is_armstrong_number(10);
  printf("a = %d\n", a);

  a = is_armstrong_number(153);
  printf("a = %d\n", a);

  a = is_armstrong_number(154);
  printf("a = %d\n", a);

  return 0;
}
