#include "anagram.h"
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

int comp(const void *a, const void *b) { return (*(char *)a - *(char *)b); }

char *lower_str(char *word) {
  size_t word_size = strlen(word);
  for (size_t i = 0; i < word_size; i++) {
    word[i] = tolower(word[i]);
  }
  return word;
}

bool is_same_word(const char *str1, const char *str2) {
  if (strlen(str1) != strlen(str2))
    return false;

  for (size_t i = 0; i < strlen(str2); i++) {
    if (tolower(str1[i]) != tolower(str2[i]))
      return false;
  }

  return true;
}

void find_anagrams(const char *subject, struct candidates *candidates) {

  char *new_str = malloc(strlen(subject) + 1);
  strcpy(new_str, subject);
  qsort(lower_str(lower_str(new_str)), strlen(new_str), sizeof(char), comp);

  for (size_t i = 0; i < candidates->count; i++) {
    struct candidate cand = candidates->candidate[i];

    char *tmp_word = malloc(strlen(cand.word) + 1);
    strcpy(tmp_word, cand.word);
    qsort(lower_str(tmp_word), strlen(tmp_word), sizeof(char), comp);

    if (!is_same_word(subject, cand.word) && strcmp(new_str, tmp_word) == 0) {
      candidates->candidate[i].is_anagram = IS_ANAGRAM;
    } else {
      candidates->candidate[i].is_anagram = NOT_ANAGRAM;
    }

    free(tmp_word);
  }

  free(new_str);
}
