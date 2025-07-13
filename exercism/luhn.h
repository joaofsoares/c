#ifndef LUHN_H
#define LUHN_H

#include <stdbool.h>

const char *trim(const char *str);

bool luhn(const char *num);

#endif
