#include "queen_attack.h"
#include <stdlib.h>
#include <stdio.h>

attack_status_t can_attack(position_t queen_1, position_t queen_2) {
  if ((queen_1.row == queen_2.row && queen_1.column == queen_2.column) ||
      queen_1.row > 7 ||
      queen_2.row > 7 ||
      queen_1.column > 7 ||
      queen_2.column > 7)
    return INVALID_POSITION;

  uint8_t delta_row = abs(queen_1.row - queen_2.row);
  uint8_t delta_col = abs(queen_1.column - queen_2.column);

  if (queen_1.row == queen_2.row ||
      queen_1.column == queen_2.column ||
      delta_row == delta_col)
    return CAN_ATTACK;


  return CAN_NOT_ATTACK;
}

int main(void) {
   position_t white_queen;
   position_t black_queen;

   white_queen.column = 2;
   white_queen.row = 5;
   black_queen.column = white_queen.column;
   black_queen.row = white_queen.row;

   attack_status_t result = can_attack(white_queen, black_queen);
   printf("result=%d\n", result);

   white_queen.column = 4;
   white_queen.row = 2;
   black_queen.column = 6;
   black_queen.row = 6;

   result = can_attack(white_queen, black_queen);
   printf("result=%d\n", result);

   white_queen.column = 5;
   white_queen.row = 4;
   black_queen.column = 5;
   black_queen.row = 2;

   result = can_attack(white_queen, black_queen);
   printf("result=%d\n", result);

   white_queen.column = 1;
   white_queen.row = 4;
   black_queen.column = 5;
   black_queen.row = 2;

   result = can_attack(white_queen, black_queen);
   printf("result=%d\n", result);

  return 0;
}
