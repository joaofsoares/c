#include "pangram.h"
#include <string.h>

bool is_pangram(const char *sentence) {

  if (sentence == NULL || strlen(sentence) == 0)
    return false;

  bool check[26] = {false};

  for (size_t i = 0; i < strlen(sentence); i++) {
    if ('A' <= sentence[i] && sentence[i] <= 'Z')
      check[sentence[i] - 'A'] = true;
    else if ('a' <= sentence[i] && sentence[i] <= 'z')
      check[sentence[i] - 'a'] = true;
  }

  for (size_t i = 0; i < 26; i++) {
    if (check[i] == false)
      return false;
  }

  return true;
}

int main(void) { return 0; }
