#include "triangle.h"
#include <stdio.h>

bool is_valid(triangle_t triangle) {
  return (triangle.a > 0) && (triangle.b > 0) && (triangle.c > 0) &&
         (triangle.a + triangle.b >= triangle.c) &&
         (triangle.b + triangle.c >= triangle.a) &&
         (triangle.a + triangle.c >= triangle.b);
}

bool is_equilateral(triangle_t triangle) {
  return is_valid(triangle) && (triangle.a == triangle.b) &&
         (triangle.b == triangle.c);
}

bool is_isosceles(triangle_t triangle) {
  return is_valid(triangle) &&
         ((triangle.a == triangle.b) || (triangle.b == triangle.c) ||
          (triangle.a == triangle.c));
}

bool is_scalene(triangle_t triangle) {
  return is_valid(triangle) && (triangle.a != triangle.b) &&
         (triangle.b != triangle.c) && (triangle.a != triangle.c);
}

int main(void) {
  triangle_t sides = {2, 2, 2};
  bool result = is_equilateral(sides);
  printf("is equilateral = %d\n", result);
}
