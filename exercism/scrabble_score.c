#include "scrabble_score.h"
#include <ctype.h>
#include <string.h>

unsigned int score(const char *word) {
  int word_size = strlen(word);
  unsigned int total = 0;

  for (int i = 0; i < word_size; i++) {
    switch (tolower(word[i])) {
    case 'a':
    case 'e':
    case 'i':
    case 'o':
    case 'u':
    case 'l':
    case 'n':
    case 'r':
    case 's':
    case 't':
      total += 1;
      break;
    case 'd':
    case 'g':
      total += 2;
      break;
    case 'b':
    case 'c':
    case 'm':
    case 'p':
      total += 3;
      break;
    case 'f':
    case 'h':
    case 'v':
    case 'w':
    case 'y':
      total += 4;
      break;
    case 'k':
      total += 5;
      break;
    case 'j':
    case 'x':
      total += 8;
      break;
    case 'q':
    case 'z':
      total += 10;
      break;
    default:
      continue;
    }
  }

  return total;
}
