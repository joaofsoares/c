#include "beer_song.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void recite(uint8_t start_bottles, uint8_t take_down, char **song) {
	int i = 0;
	int limit = take_down * 2;

	while (i < limit) {
		char str_num[2];
		sprintf(str_num, "%d", start_bottles);

		strcpy(song[i], (start_bottles == 0) ? "No more" : str_num);
		strcat(song[i], (start_bottles == 1) ? " bottle of beer on the wall, " : " bottles of beer on the wall, ");
		strcat(song[i], (start_bottles == 0) ? "no more" : str_num); 
		strcat(song[i], (start_bottles == 1) ? " bottle of beer." : " bottles of beer.");
		i += 1;

		switch (start_bottles) {
			case 0:
				strcpy(song[i], "Go to the store and buy some more, ");
				break;
			case 1:
				strcpy(song[i],"Take it down and pass it around, "); 
				break;
			default:
				strcpy(song[i],"Take one down and pass it around, "); 
		}

		char str_num_minus_one[2];
		sprintf(str_num_minus_one, "%d", (start_bottles - 1));
		if (start_bottles == 0) {
			strcat(song[i], "99 bottles of beer on the wall.");
		} else if (start_bottles == 1) {
			strcat(song[i], "no more bottles of beer on the wall.");
		} else if (strcmp(str_num_minus_one, "1") == 0) {
			strcat(song[i], str_num_minus_one); 
			strcat(song[i], " bottle of beer on the wall.");
		} else {
			strcat(song[i], str_num_minus_one); 
			strcat(song[i], " bottles of beer on the wall.");
		}
		i += 1;

		str_num[0] = '\0';
		str_num_minus_one[0] = '\0';
		start_bottles -= 1;
	}
}

