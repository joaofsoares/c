#include "luhn.h"
#include <ctype.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char *trim(const char *str) {
  if (str == NULL) {
    return NULL;
  }

  while (*str && isspace((unsigned char)*str)) {
    str++;
  }

  const char *end = str + strlen(str) - 1;
  while (end > str && isspace((unsigned char)*end)) {
    end--;
  }

  size_t len = end - str + 1;
  char *trimmed_str = malloc(len + 1);
  if (trimmed_str == NULL) {
    return NULL;
  }

  strncpy(trimmed_str, str, len);
  trimmed_str[len] = '\0';

  return trimmed_str;
}

bool luhn(const char *num) {

  const char *trimmed_str = trim(num);

  if (strlen(trimmed_str) < 2) {
    return false;
  }

  bool is_second = false;

  int sum = 0;

  for (int i = strlen(trimmed_str) - 1; i >= 0; i--) {
    if (isspace(trimmed_str[i]))
      continue;
    else if (isalpha(trimmed_str[i]) || !isdigit(trimmed_str[i])) {
      return false;
    } else if (isdigit(trimmed_str[i])) {
      int digit = trimmed_str[i] - '0';

      if (is_second) {
        digit *= 2;
        if (digit > 9) {
          digit -= 9;
        }
      }

      sum += digit;

      is_second = !is_second;
    }
  }

  return sum % 10 == 0;
}

int main(void) {
  bool result = luhn("1");
  printf("result = %d\n", result);

  result = luhn("0");
  printf("result = %d\n", result);

  result = luhn("059");
  printf("result = %d\n", result);

  result = luhn("59");
  printf("result = %d\n", result);

  result = luhn("055 444 285");
  printf("result = %d\n", result);

  result = luhn("055 444 286");
  printf("result = %d\n", result);

  result = luhn("8273 1232 7352 0569");
  printf("result = %d\n", result);

  result = luhn("1 2345 6789 1234 5678 9012");
  printf("result = %d\n", result);

  result = luhn("1 2345 6789 1234 5678 9013");
  printf("result = %d\n", result);

  result = luhn("095 245 88");
  printf("result = %d\n", result);

  result = luhn("234 567 891 234");
  printf("result = %d\n", result);

  result = luhn("059a");
  printf("result = %d\n", result);

  result = luhn("055-444-285");
  printf("result = %d\n", result);

  result = luhn("055£ 444$ 285");
  printf("result = %d\n", result);

  result = luhn(" 0");
  printf("result = %d\n", result);

  result = luhn("0000 0");
  printf("result = %d\n", result);

  result = luhn("091");
  printf("result = %d\n", result);

  result = luhn("9999999999 9999999999 9999999999 9999999999");
  printf("result = %d\n", result);

  result = luhn("109");
  printf("result = %d\n", result);

  result = luhn("055b 444 285");
  printf("result = %d\n", result);

  result = luhn(":9");
  printf("result = %d\n", result);

  result = luhn("59%59");
  printf("result = %d\n", result);

  return 0;
}
