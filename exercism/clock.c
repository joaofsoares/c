#include "clock.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

clock_t clock_create(int hour, int minute) {
  clock_t clock;
  int total_minutes = (hour * 60 + minute) % (24 * 60);

  if (total_minutes < 0) {
    total_minutes += (24 * 60);
  }

  int final_hour = total_minutes / 60;
  int final_minute = total_minutes % 60;

  snprintf(clock.text, MAX_STR_LEN, "%02d:%02d", final_hour, final_minute);

  return clock;
}

clock_t clock_add(clock_t clock, int minute_add) {
  int hour, minute;
  sscanf(clock.text, "%02d:%02d", &hour, &minute);

  int total_minutes = (hour * 60 + minute + minute_add) % (24 * 60);

  if (total_minutes < 0) {
    total_minutes += (24 * 60);
  }

  return clock_create(total_minutes / 60, total_minutes % 60);
}

clock_t clock_subtract(clock_t clock, int minute_subtract) {
  int hour, minute;
  sscanf(clock.text, "%02d:%02d", &hour, &minute);

  int total_minutes = (hour * 60 + minute - minute_subtract) % (24 * 60);

  if (total_minutes < 0) {
    total_minutes += (24 * 60);
  }

  return clock_create(total_minutes / 60, total_minutes % 60);
}

bool clock_is_equal(clock_t a, clock_t b) {
  return strcmp(a.text, b.text) == 0;
}
