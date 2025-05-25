#ifndef BINARY_SEARCH_H
#define BINARY_SEARCH_H

#include <stddef.h>

const int *binary_search_recurr(int value, const int *arr, size_t low,
                                size_t high);

const int *binary_search(int value, const int *arr, size_t length);

#endif
