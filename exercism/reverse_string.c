#include "reverse_string.h"
#include <stdlib.h>
#include <string.h>

char *reverse(const char *value) {
  size_t str_size = strlen(value);
  size_t start = 0;

  char *reversed = (char *)malloc(str_size * sizeof(char));
  if (reversed == NULL) {
    return NULL;
  }

  for (int i = str_size - 1; i >= 0; i--) {
    reversed[start++] = value[i];
  }

  return reversed;
}
