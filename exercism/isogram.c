#include "isogram.h"
#include <ctype.h>
#include <stdio.h>
#include <string.h>

bool is_isogram(const char phrase[]) {
  if (phrase == NULL) {
    return false;
  }

  int len = strlen(phrase);

  bool seen[26] = {false};

  for (int i = 0; i < len; i++) {
    char c = tolower(phrase[i]);

    if (c >= 'a' && c <= 'z') {
      if (seen[c - 'a']) {
        return false;
      }
      seen[c - 'a'] = true;
    }
  }

  return true;
}

int main(void) {
  bool result = is_isogram("");
  printf("isogram = %d\n", result);

  result = is_isogram(NULL);
  printf("isogram = %d\n", result);
}
