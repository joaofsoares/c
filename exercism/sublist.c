#include "sublist.h"

bool has_sublist(int *arr1, int *arr2, int idx, int size) {
  int j = idx;
  for (int i = {0}; i < size; i++) {
    if (arr1[i] != arr2[j])
      return false;

    j++;
  }

  return true;
}

comparison_result_t check_lists(int *list_to_compare, int *base_list,
                                size_t list_to_compare_element_count,
                                size_t base_list_element_count) {
  if (list_to_compare_element_count == 0 &&
      list_to_compare_element_count == base_list_element_count) {
    return EQUAL;
  } else if (list_to_compare_element_count == 0 &&
             base_list_element_count != 0) {
    return SUBLIST;
  } else if (list_to_compare_element_count != 0 &&
             base_list_element_count == 0) {
    return SUPERLIST;
  } else if (list_to_compare_element_count == base_list_element_count) {
    for (size_t i = 0; i < list_to_compare_element_count; i++) {
      if (list_to_compare[i] != base_list[i]) {
        return UNEQUAL;
      }
    }
    return EQUAL;
  } else if (list_to_compare_element_count < base_list_element_count) {
    for (size_t i = {0}; i < base_list_element_count; i++) {
      if (base_list[i] == list_to_compare[0] &&
          (i + (list_to_compare_element_count - 1)) < base_list_element_count) {

        bool is_sublist = has_sublist(list_to_compare, base_list, i,
                                      list_to_compare_element_count);

        if (is_sublist)
          return SUBLIST;
      }
    }
  } else if (list_to_compare_element_count > base_list_element_count) {
    for (size_t i = {0}; i < list_to_compare_element_count; i++) {
      if (list_to_compare[i] == base_list[0] &&
          (i + base_list_element_count - 1) < list_to_compare_element_count) {

        bool is_superlist =
            has_sublist(base_list, list_to_compare, i, base_list_element_count);

        if (is_superlist)
          return SUPERLIST;
      }
    }
  }

  return UNEQUAL;
}
