#ifndef NUCLEOTIDE_COUNT_H
#define NUCLEOTIDE_COUNT_H

typedef struct {
  char letter;
  int count;
} NucleotideCount;

char *count(const char *dna_strand);

#endif
