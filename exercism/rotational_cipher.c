#include "rotational_cipher.h"
#include <stdlib.h>
#include <string.h>

char *rotate(const char *text, int shift_key) {
  if (text == NULL || shift_key < 0 || shift_key > 26) {
    return NULL;
  }

  const size_t text_size = strlen(text);

  char *text_ptr = (char *)malloc(text_size * sizeof(char));
  if (text_ptr == NULL) {
    return NULL;
  }

  if (shift_key == 0 || shift_key == 26) {
    strcpy(text_ptr, text);
    return text_ptr;
  }

  for (size_t i = 0; i < text_size; i++) {
    const char current_char = text[i];

    if (current_char >= 'a' && current_char <= 'z') {
      text_ptr[i] = ((current_char - 'a' + shift_key) % 26) + 'a';
    } else if (current_char >= 'A' && current_char <= 'Z') {
      text_ptr[i] = ((current_char - 'A' + shift_key) % 26) + 'A';
    } else {
      text_ptr[i] = current_char;
    }
  }

  return text_ptr;
}
