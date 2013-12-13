#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "game.h"

int process_input(Map *game)
{
  printf("\n> ");

  char ch = getchar();
  getchar(); // eat ENTER

  int damage = rand() % 4;

  switch(ch) {
    case -1:
      printf("Giving up? You suck.\n");
      return 0;
      break;
    case 'n':
      game->_(move)(game, NORTH);
      break;
    case 's':
      game->_(move)(game, SOUTH);
      break;
    case 'e':
      game->_(move)(game, EAST);
      break;
    case 'w':
      game->_(move)(game, WEST);
      break;
    case 'a':
      
      game->_(attack)(game, damage);
      break;
    case 'l':
      printf("You can go:\n");
      if(game->location->north) printf("NORTH\n");
      if(game->location->south) printf("SOUTH\n");
      if(game->location->east) printf("EAST\n");
      if(game->location->west) printf("WEST\n");
      break;

    default:
      printf("What? %d\n", ch);
  }

  return 1;
}


int main(int argc, char *argv[])
{
  // simple way to setup the randomness
  srand(time(NULL));

  // make our map to work with
  Map *game = NEW(Map, "The Hall of the Minotaur.");

  printf("You enter the ");
  game->location->_(describe)(game->location);

  while(process_input(game)) {
  }

  return 0;
}
