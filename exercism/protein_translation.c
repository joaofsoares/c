#include "protein_translation.h"
#include <string.h>

protein_t protein(const char *const rna) {
  size_t rna_size = strlen(rna);

  protein_t protein;
  protein.valid = false;
  protein.count = 0;

  if (rna_size == 0) {
    protein.valid = true;
    return protein;
  }

  size_t cnt = 0;
  for (int i = 0; i < rna_size; i += 3) {
    if ((i + 3) > rna_size) {
      protein.valid = false;
      protein.count = 0;
      protein.amino_acids[0] = '\0';
      return protein;
    }

    char tmp[3];
    sprintf(tmp, "%c%c%c", rna[i], rna[i+1], rna[i+2]);

    if (strcmp(tmp, "AUG") == 0) {
      protein.count++;
      protein.amino_acids[cnt] = Methionine;
      cnt++;
    } else if (strcmp(tmp, "UUU") == 0 || strcmp(tmp, "UUC") == 0) {
      protein.count++;
      protein.amino_acids[cnt] = Phenylalanine;
      cnt++;
    } else if (strcmp(tmp, "UUA") == 0 || strcmp(tmp, "UUG") == 0) {
      protein.count++;
      protein.amino_acids[cnt] = Leucine;
      cnt++;
    } else if (strcmp(tmp, "UCU") == 0 || strcmp(tmp, "UCC") == 0
               || strcmp(tmp, "UCA") == 0 || strcmp(tmp, "UCG") == 0) {
      protein.count++;
      protein.amino_acids[cnt] = Serine;
      cnt++;
    } else if (strcmp(tmp, "UAU") == 0 || strcmp(tmp, "UAC") == 0) {
      protein.count++;
      protein.amino_acids[cnt] = Tyrosine;
      cnt++;
    } else if (strcmp(tmp, "UGU") == 0 || strcmp(tmp, "UGC") == 0) {
      protein.count++;
      protein.amino_acids[cnt] = Cysteine;
      cnt++;
    } else if (strcmp(tmp, "UGG") == 0) {
      protein.count++;
      protein.amino_acids[cnt] = Tryptophan;
      cnt++;
    } else if (strcmp(tmp, "UAA") == 0 || strcmp(tmp, "UAG") == 0
               || strcmp(tmp, "UGA") == 0) {
      protein.valid = true;
      break;
    }
    else {
      continue;
    }
  }

  if (protein.count > 0)
    protein.valid = true;

  return protein;
}
