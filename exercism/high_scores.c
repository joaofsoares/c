#include <stdio.h>
#include <stdlib.h>

int32_t latest(const int32_t *scores, size_t scores_len) {
  int32_t min = scores[0];
  for (size_t i = 1; i < scores_len; i++) {
    if (scores[i] != 0)
      min = (scores[i] < min) ? scores[i] : min;
  }
  return min;
}

int32_t personal_best(const int32_t *scores, size_t scores_len) {
  int32_t max = scores[0];
  for (size_t i = 1; i < scores_len; i++) {
    if (scores[i] != 0)
      max = (scores[i] > max) ? scores[i] : max;
  }
  return max;
}

size_t personal_top_three(const int32_t *scores, size_t scores_len,
                          int32_t *output) {
  int32_t fst = 0;
  int32_t snd = 0;
  int32_t thd = 0;

  for (size_t i = 0; i < scores_len; i++) {
    int32_t elem = scores[i];
    if (elem > fst) {
      thd = snd;
      snd = fst;
      fst = elem;
    } else if (elem > snd) {
      thd = snd;
      snd = elem;
    } else if (elem > thd) {
      thd = elem;
    }
  }

  output[0] = fst;
  output[1] = snd;
  output[2] = thd;

  if (thd != 0)
    return 3;
  else if (snd != 0)
    return 2;
  else if (fst != 0)
    return 1;
  else
    return 0;
}

int main(void) {
  const int min_scores[] = {100, 0, 90, 30};
  int minimum = latest(min_scores, 4);
  printf("min=%d\n", minimum);

  const int max_scores[] = {40, 100, 70};
  int maximum = personal_best(max_scores, 3);
  printf("max=%d\n", maximum);

  const int scores[] = {10, 30, 90, 30, 100, 20, 10, 0, 30, 40, 40, 70, 70};
  int *output = (int *)malloc(3 * sizeof(int));
  size_t result = personal_top_three(scores, 14, output);
  printf("result=%zu\n", result);

  const int duo_scores[] = {30, 70};
  int *new_output = (int *)malloc(3 * sizeof(int));
  result = personal_top_three(scores, 2, output);
  printf("result=%zu\n", result);

  return 0;
}
