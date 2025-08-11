#include "nucleotide_count.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *count(const char *dna_strand) {
  NucleotideCount nc[4] = {{'A', 0}, {'C', 0}, {'G', 0}, {'T', 0}};

  size_t str_size = strlen(dna_strand);

  char *result = malloc(50 * sizeof(char));
  if (result == NULL) {
    return NULL;
  }

  for (size_t i = 0; i < str_size; i++) {
    char nucleotide = dna_strand[i];
    switch (nucleotide) {
    case 'A':
      nc[0].count++;
      break;
    case 'C':
      nc[1].count++;
      break;
    case 'G':
      nc[2].count++;
      break;
    case 'T':
      nc[3].count++;
      break;
    default:
      strcpy(result, "");
      return result;
    }
  }

  sprintf(result, "A:%d C:%d G:%d T:%d", nc[0].count, nc[1].count, nc[2].count,
          nc[3].count);

  return result;
}
