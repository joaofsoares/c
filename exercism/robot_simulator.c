#include "robot_simulator.h"
#include <stdio.h>
#include <string.h>

robot_status_t robot_create(robot_direction_t direction, int x, int y) {
  return (robot_status_t){.direction = direction, .position = {.x = x, .y = y}};
}

void robot_move(robot_status_t *robot, const char *commands) {
  size_t command_size = strlen(commands);

  for (size_t i = 0; i < command_size; i++) {
    switch (commands[i]) {
    case 'R':
      robot->direction = (robot->direction + 1) % DIRECTION_MAX;
      break;
    case 'L':
      robot->direction = (robot->direction - 1 + DIRECTION_MAX) % DIRECTION_MAX;
      break;
    case 'A':
      switch (robot->direction) {
      case DIRECTION_NORTH:
        robot->position.y++;
        break;
      case DIRECTION_EAST:
        robot->position.x++;
        break;
      case DIRECTION_SOUTH:
        robot->position.y--;
        break;
      case DIRECTION_WEST:
        robot->position.x--;
        break;
      default:
        break;
      }
      break;
    default:
      break;
    }
  }
}

int main(void) {
  robot_status_t a = robot_create(DIRECTION_NORTH, 0, 0);
  printf("direction = %d\n", a.direction);
  return 0;
}
