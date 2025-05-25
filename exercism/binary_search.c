#include "binary_search.h"
#include <stdio.h>

const int *binary_search_recurr(int value, const int *arr, size_t low,
                                size_t high) {

  while (high >= low) {
    int mid = low + (high - low) / 2;

    if (arr[mid] == value) {
      return &arr[mid];
    }

    if (value < arr[mid]) {
      if (mid == 0) {
        return NULL;
      }

      return binary_search_recurr(value, arr, low, mid - 1);
    }

    return binary_search_recurr(value, arr, mid + 1, high);
  }

  return NULL;
}

const int *binary_search(int value, const int *arr, size_t length) {
  if (length == 0 || arr == NULL) {
    return NULL;
  }

  return binary_search_recurr(value, arr, 0, length - 1);
}

int main(void) {
  int arr[] = {4, 5, 6, 7};
  size_t length = sizeof(arr) / sizeof(arr[0]);

  const int *result = binary_search(2, arr, length);

  if (result == NULL) {
    printf("value is null\n");
  } else {
    printf("result = %d\n", *result);
  }
}
