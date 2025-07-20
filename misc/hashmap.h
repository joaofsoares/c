#ifndef _HASHMAP_H_
#define _HASHMAP_H_

#include <stdlib.h>

typedef struct {
  int key;
  int value;
} HashMapEntry;

typedef struct {
  HashMapEntry *entries;
  size_t size;
} HashMap;

HashMap *create_hashmap(size_t size);

void free_hashmap(HashMap *map);

void put(HashMap *map, int key, int value);

#endif
