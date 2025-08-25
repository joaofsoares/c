#include "all_your_base.h"
#include <string.h>

size_t rebase(int8_t *digits, int16_t input_base, int16_t output_base,
              size_t input_length) {

  if (input_base < 2 || output_base < 2 || input_length == 0)
    return 0;

  for (size_t i = 0; i < input_length; i++)

    if (digits[i] < 0 || digits[i] >= input_base)
      return 0;

  size_t number = 0;

  for (size_t i = input_length, r = 1; i > 0; i--, r *= (size_t)input_base)

    number += (size_t)digits[i - 1] * r;

  size_t length = 0;

  do {

    length++;

    memmove(&digits[1], digits, length - 1 * sizeof(int8_t));

    digits[0] = (int8_t)(number % (size_t)output_base);

    number /= (size_t)output_base;

  } while (number > 0);

  return length;
}
