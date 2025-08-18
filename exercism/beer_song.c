#include "beer_song.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void recite(uint8_t start_bottles, uint8_t take_down, char **song) {
  int bottles = start_bottles;

  for (int i = 0; i < ((3 * take_down) - 1);) {
    char num[3];
    sprintf(num, "%hu", bottles);

    // first line
    strcat(song[i], (bottles == 0) ? "No more" : num);
    strcat(song[i], (bottles == 1) ? " bottle of beer on the wall, "
                                   : " bottles of beer on the wall, ");
    strcat(song[i], (bottles == 0) ? "no more" : num);
    strcat(song[i++],
           (bottles == 1) ? " bottle of beer." : " bottles of beer.");

    // second line
    bottles -= 1;

    if (bottles < 0) {
      strcat(song[i], "Go to the store and buy some more, ");
      bottles = 99;
    } else {
      strcat(song[i], (bottles == 0) ? "Take it down and pass it around, "
                                     : "Take one down and pass it around, ");
    }

    if (bottles > 0) {
      sprintf(num, "%hu", bottles);
      strcat(song[i], num);
    } else {
      strcat(song[i], "no more");
    }

    strcat(song[i++], (bottles == 1) ? " bottle of beer on the wall."
                                     : " bottles of beer on the wall.");

    if (i < ((3 * take_down) - 1)) {
      strcat(song[i++], "");
    }
  }
}
