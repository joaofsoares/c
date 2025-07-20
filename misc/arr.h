#ifndef _ARR_H_
#define _ARR_H_

typedef struct {
  int *values;
  int size;
} DynamicArray;

void append(DynamicArray *da, int v);

DynamicArray *create_array();

#endif
