#include "arr.h"
#include <stdio.h>
#include <stdlib.h>

void append(DynamicArray *da, int v) {
  if (da->size == 0)
    da->values = (int *)malloc(sizeof(int));

  da->size++;

  da->values = realloc(da->values, da->size * sizeof(int));

  da->values[da->size - 1] = v;
}

DynamicArray *create_array() {
  return (DynamicArray *)malloc(sizeof(DynamicArray));
}

void free_array(DynamicArray *da) {
  if (da != NULL) {
    free(da->values);
    da->values = NULL;
    da->size = 0;
    free(da);
  }
}

int main(void) {
  printf("main function\n");

  DynamicArray *da = create_array();

  append(da, 10);
  append(da, 20);
  append(da, 30);

  for (size_t i = 0; i < da->size; i++) {
    printf("value inside dynamic array = %d\n", da->values[i]);
  }

  free_array(da);

  return 0;
}
