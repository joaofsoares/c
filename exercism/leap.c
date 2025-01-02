#include "leap.h"
#include <stdbool.h>
#include <stdio.h>

bool leap_year(int year) {
  return ((year % 400 == 0) || ((year % 100 != 0) && (year % 4 == 0)));
}
