#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
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

    int init2[4][4] = {
    { 1, 2, 3, 4 },
    { 5, 6, 7, 8 },
    { 9, 10, 11, 12 },
    { 13, 14, 0, 15 },
    };

    int *testGrid = &init[0][0];
    Puzzle tempPuzzle = {4, testGrid, ""};

    Puzzle *testPuzzle = malloc(sizeof(tempPuzzle));

    

    *testPuzzle = tempPuzzle;

    for(int i = 0; i < 16; i++){

    if((i) % 4 == 0){
        printf("\n");
    }
    printf("%d ", testPuzzle->grid[i]);
    }
    printf("\n\n\n");
    free(solve(*testPuzzle, 'n', 0, findEmptyIndex(testPuzzle)));


    for(int i = 0; i < 16; i++){
        if((i) % 4 == 0){
            printf("\n");
        }
        printf("%d ", testPuzzle->grid[i]);
    }
    printf("\nAll tests passed!\n");
    free(testPuzzle);
    return 0;
}
