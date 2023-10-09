#ifndef PUZZLE_H
#define PUZZLE_H

#include "ppm_io.h" // for Image data type

typedef struct {
  // ...fields go here...
  int size;
  int *grid;
  char *image;



} Puzzle;

// TODO: function declarations


Puzzle *createPuzzle(int size);

//returns index of the current empty space in the puzzle
//returns -1 if no empty space found
int findEmptyIndex(Puzzle *puzzle);
int moveRight(Puzzle *puzzle, int emptyIndex);
int moveLeft(Puzzle *puzzle, int emptyIndex);
int moveUp(Puzzle *puzzle, int emptyIndex);
int moveDown(Puzzle *puzzle, int emptyIndex);
void swap(Puzzle *puzzle, int index1, int index2);

int isLegalMove(Puzzle *puzzle, char direction, int emptyIndex);

char *solve(Puzzle puzzle, char direction, int moveNum, int emptyIndex);


//returns 0 if not solved and 1 if solved
int isSolved(Puzzle *puzzle);
#endif // PUZZLE_H
