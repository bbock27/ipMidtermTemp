#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "ppm_io.h"
#include "puzzle.h"

int main(int argc, char **argv) {
  if (argc < 1 || argc > 2) {
    fprintf(stderr, "Usage: ./puzzle [<command file>]\n");
    return 1;
  }

    char command = '\0';
    Puzzle *puzzle = NULL;
  while(scanf("%c", &command) != 0){
    if(command == 'c'){
        handleCcommand();
    }
    else if(command == 't'){
        handleTcommand();
    }
    else if(command == 'i'){
        handleIcommand();
    }
    else if(command == 'p'){
        handlePcommand(puzzle);
    }
    else if(command == 'w'){
        handleWcommand();
    }
    else if(command == 's'){
        handleScommand(puzzle);
    }
    else if(command == 'k'){
        handleKcommand(puzzle);
    }
    else if(command == 'v'){
        handleVcommand(puzzle);
    }
    else if(command == 'q'){
        handleQcommand();
    }
  }

}
