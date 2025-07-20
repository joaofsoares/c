#include "hashmap.h"
#include <stdio.h>

HashMap *create_hashmap(size_t size) {
  HashMap *map = malloc(sizeof(HashMap));
  if (map == NULL) {
    return NULL;
  }

  map->entries = malloc(size * sizeof(HashMapEntry));
  if (map->entries == NULL) {
    free(map);
    return NULL;
  }

  map->size = size;
  for (size_t i = 0; i < size; i++) {
    map->entries[i].key = -1; // Initialize keys to -1 to indicate empty slots
  }

  return map;
}

void free_hashmap(HashMap *map) {
  if (map != NULL) {
    free(map->entries);
    free(map);
  }
}

void put(HashMap *map, int key, int value) {
  if (map == NULL || map->entries == NULL) {
    return;
  }

  size_t index = key % map->size;
  while (map->entries[index].key != -1) {
    if (map->entries[index].key == key) {
      map->entries[index].value = value; // Update existing key
      return;
    }
    index = (index + 1) % map->size; // Linear probing
  }

  map->entries[index].key = key;
  map->entries[index].value = value;
}

int main(void) {
  HashMap *map = create_hashmap(10);

  put(map, 0, 0);
  put(map, 1, 100);
  put(map, 2, 200);
  put(map, 3, 300);
  put(map, 4, 400);
  put(map, 5, 500);
  put(map, 6, 600);
  put(map, 7, 700);
  put(map, 8, 800);
  put(map, 9, 900);

  printf("Key: %d, Value: %d\n", map->entries[0].key, map->entries[0].value);
  printf("Key: %d, Value: %d\n", map->entries[1].key, map->entries[1].value);
  printf("Key: %d, Value: %d\n", map->entries[2].key, map->entries[2].value);
  printf("Key: %d, Value: %d\n", map->entries[3].key, map->entries[3].value);
  printf("Key: %d, Value: %d\n", map->entries[4].key, map->entries[4].value);
  printf("Key: %d, Value: %d\n", map->entries[5].key, map->entries[5].value);
  printf("Key: %d, Value: %d\n", map->entries[6].key, map->entries[6].value);
  printf("Key: %d, Value: %d\n", map->entries[7].key, map->entries[7].value);
  printf("Key: %d, Value: %d\n", map->entries[8].key, map->entries[8].value);
  printf("Key: %d, Value: %d\n", map->entries[9].key, map->entries[9].value);

  free_hashmap(map);
  return 0;
}
