#include "rna_transcription.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

char *to_rna(const char *dna) {
  const size_t dna_size = strlen(dna);

  char *response = (char*) malloc(sizeof(char) * dna_size);

  for (size_t i = 0; i < dna_size; i++) {
    switch (dna[i]) {
    case 'G':
      response[i] = 'C';
      break;
    case 'C':
      response[i] = 'G';
      break;
    case 'T':
      response[i] = 'A';
      break;
    case 'A':
      response[i] = 'U';
      break;
    default:
      response[i] = dna[i];
    }
  }

  return response;
}

int main(void) {
  char *result = to_rna("");
  printf("result=%s\n", result);

  result = to_rna("C");
  printf("result=%s\n", result);

  result = to_rna("G");
  printf("result=%s\n", result);

  result = to_rna("T");
  printf("result=%s\n", result);

  result = to_rna("A");
  printf("result=%s\n", result);

  result = to_rna("ACGTGGTCTTAA");
  printf("result=%s\n", result);

  free(result);

  return 0;
}
