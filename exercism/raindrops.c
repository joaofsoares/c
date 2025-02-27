#include "raindrops.h"
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

void convert(char result[], int drops) {

  result[0] = '\0';

  if (drops % 3 == 0)
    strcpy(result, "Pling");

  bool div_5 = drops % 5 == 0;

  if (div_5 && strlen(result) == 0)
    strcpy(result, "Plang");
  else if (div_5)
    strcat(result, "Plang");

  bool div_7 = drops % 7 == 0;

  if (div_7 && strlen(result) == 0)
    strcpy(result, "Plong");
  else if (div_7)
    strcat(result, "Plong");

  if (strlen(result) == 0)
    sprintf(result, "%d", drops);
}

int main(void) {
  char buffer[16];
  convert(buffer, 1);
  printf("result=%s\n", buffer);

  buffer[0] = '\0';
  convert(buffer, 28);
  printf("result=%s\n", buffer);

  buffer[0] = '\0';
  convert(buffer, 30);
  printf("result=%s\n", buffer);

  return 0;
}
