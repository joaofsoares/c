#include "two_fer.h"
#include <stdio.h>
#include <string.h>

void two_fer(char *buffer, const char *name) {
  if (name == NULL)
    strcpy(buffer, "One for you, one for me.");
  else {
    strcpy(buffer, "One for ");
    strcat(buffer, name);
    strcat(buffer, ", one for me.");
  }
}

int main(void) {
  char buffer[100];
  two_fer(buffer, NULL);
  printf("result=%s\n", buffer);

  buffer[0] = '\0';
  two_fer(buffer, "Alice");
  printf("result=%s\n", buffer);

  return 0;
}
