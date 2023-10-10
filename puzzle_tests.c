#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "puzzle.h"

// also tests puzzle_destroy
/*
void test_puzzle_create(void) {

  Puzzle *p3 = createPuzzle(3);
  Puzzle *p5 = createPuzzle(5);

  assert(p3->size == 3);
  for (int i = 0; i < 9; ++i) {
    assert(p3->tiles[i] == 0);
  }

  assert(p5->size == 5);
  for (int i = 0; i < 25; ++i) {
    assert(p5->tiles[i] == 0);
  }

  puzzle_destroy(p3);
  puzzle_destroy(p5);
}

// also tests puzzle_get_tile
void test_puzzle_set_tile(void) {
  int init[4][4] = {
    { 5, 7, 1, 2 },
    { 13, 9, 3, 4 },
    { 0, 8, 6, 11 },
    { 14, 15, 10, 12 },
  };

  Puzzle *p4 = puzzle_create(4);
  for (int i = 0; i < 4; ++i)
    for (int j = 0; j < 4; ++j)
      puzzle_set_tile(p4, j, i, init[i][j]);

  for (int i = 0; i < 4; ++i)
    for (int j = 0; j < 4; ++j)
      assert(puzzle_get_tile(p4, j, i) == init[i][j]);

  puzzle_destroy(p4);
}
*/
// ...other test functions...

int main(void) {
//   test_puzzle_create();
//   test_puzzle_set_tile();
  // ...call other test functions...
    int init[4][4] = {
    { 5, 7, 1, 2 },
    { 13, 9, 3, 4 },
    { 0, 8, 6, 11 },
    { 14, 15, 10, 12 },
    };

    int testGrid2[] = {5, 7, 1, 2, 0, 9, 3, 4, 13, 8, 6, 11, 14, 15, 10, 12};
    int testGrid3[] = {2, 4, 3, 1, 0, 5, 7, 8, 6};
    int testGrid4[] = {5, 8, 2, 7, 1, 3, 4, 6, 0};
    int testGrid5[] = {12, 1, 2, 15, 11, 6, 5, 8, 7, 10, 9, 4, 0, 13, 14, 3};
    int testGrid6[] = {7, 8, 6, 1, 4, 2, 5, 3, 0};
    int init2[3][3] = {
    { 1, 2, 3},
    { 5, 6, 7},
    { 9, 4, 0}
    };


    int *testGrid = &init2[0][0];
    int puzzleSize = 3;
    Puzzle tempPuzzle = {puzzleSize, testGrid6, "test"};

    Puzzle *testPuzzle = malloc(sizeof(tempPuzzle));

    

    *testPuzzle = tempPuzzle;

    printPuzzle(*testPuzzle);


    
    solve(testPuzzle, 150);
    

    printPuzzle(*testPuzzle);
    printf("\nAll tests passed!\n");
    free(testPuzzle);
    return 0;
}
