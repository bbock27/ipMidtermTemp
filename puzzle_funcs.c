#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "puzzle.h"

// TODO: implement functions

Puzzle *createPuzzle(int size){
    // int temp[] = {1, 0, 4, 3};
    Puzzle *p = malloc(sizeof(Puzzle));
    p->grid = calloc(size*size, sizeof(int));
    p->size = size;
    // Puzzle p = {size, temp, "image"};
    return p;
}

void setPuzzleImage(Puzzle *puzzle, char *imageFile){
    puzzle->image = calloc(strlen(imageFile)+1, sizeof(char));
}

void setPuzzleGrid(Puzzle *puzzle, int *grid){
    puzzle->grid = malloc( (puzzle->size * puzzle->size)*sizeof(int));
    for(int i = 0; i < (puzzle->size * puzzle->size); i++){
        puzzle->grid[i] = grid[i];
    }
}

void changePuzzleImage(Puzzle *puzzle, char *imageFile){
    free(puzzle->image);
    puzzle->image = malloc((strlen(imageFile)+1) * sizeof(char));
    strcpy(puzzle->image, imageFile);
}
void changePuzzleGrid(Puzzle *puzzle, int *newGrid){
    for(int i = 0; i < (puzzle->size * puzzle->size); i++){
        puzzle->grid[i] = newGrid[i];
    }
}



void printPuzzle(Puzzle puzzle){
    for(int i = 0; i < (puzzle.size * puzzle.size); i++){

        if((i) % puzzle.size == 0){
            printf("\n");
        }
        printf("%d ", puzzle.grid[i]);
    }
    printf("\n");
}


int solve(Puzzle *puzzle, int maxMoves){
    int zeroIndex = findEmptyIndex(puzzle);
    if(zeroIndex == -1){
        printf("no empty tile found\n");
        return 1;
    }
    char *path = findSolvePath(*puzzle, 'n', 0, zeroIndex, maxMoves);
    if(path == NULL){
        printf("no valid path in the amount of moves given.");
        return 2;
    }
    followPath(puzzle, path);
    free(path);
    return 0;
}

int findEmptyIndex(Puzzle *puzzle){
    for(int i = 0; i < (puzzle->size * puzzle->size); i++){
        if(puzzle->grid[i] == 0){
            return i;
        }
    }
    return -1;
}

void deletePuzzle(Puzzle *puzzle){
    free(puzzle->grid);
    free(puzzle->image);
    free(puzzle);
}



int isLegalMove(Puzzle *puzzle, char direction, int emptyIndex){
    if(direction == 'l'){
        if((emptyIndex+1) % (puzzle->size) == 0){
            return 0; //false
        }
        return 1; // true
    }
    else if(direction == 'r'){
        if((emptyIndex) % (puzzle->size) == 0){
            return 0; //false
        }
        return 1; // true
    }
    else if(direction == 'd'){
        if(emptyIndex < puzzle->size){
            return 0; //false
        }
        return 1; // true
    }

    else if(direction == 'u'){
        if((emptyIndex) + (puzzle->size) >= (puzzle->size * puzzle->size)){
            return 0; //false
        }
        return 1; // true
    }
    else{
        return 0; // invlaid direction
    }
}

//slides tile left -- results in the open space moving to the right
int moveLeft(Puzzle *puzzle, int emptyIndex){
    
    puzzle->grid[emptyIndex] = puzzle->grid[emptyIndex+1];
    puzzle->grid[emptyIndex+1] = 0;

    return emptyIndex+1;
    
}

//slides tile right -- results in the open space moving to the left
int moveRight(Puzzle *puzzle, int emptyIndex){
    puzzle->grid[emptyIndex] = puzzle->grid[emptyIndex-1];
    puzzle->grid[emptyIndex-1] = 0;
    return emptyIndex-1;
}

//slides tile down -- results in the open space moving up
int moveDown(Puzzle *puzzle, int emptyIndex){
    puzzle->grid[emptyIndex] = puzzle->grid[emptyIndex-puzzle->size];
    puzzle->grid[emptyIndex-puzzle->size] = 0;
    return emptyIndex-puzzle->size;
}

//slides tile up -- results in the open space moving down
int moveUp(Puzzle *puzzle, int emptyIndex){
    puzzle->grid[emptyIndex] = puzzle->grid[emptyIndex+puzzle->size];
    puzzle->grid[emptyIndex+puzzle->size] = 0;
    return emptyIndex+puzzle->size;
}

int isSolved(Puzzle *puzzle){
    // for(int i = 1; i < puzzle->size; i++){
    //     if(puzzle->grid[i] == 0){
    //         if(i == (puzzle->size-1)){
    //             return 1;
    //         }

    //         if(puzzle->grid[i+1] < puzzle->grid[i-1]){
    //             return 0;
    //         }
    //         i++;
    //     }
    //     if(puzzle->grid[i] < puzzle->grid[i-1]){
    //         return 0;
    //     }
    // }
    // return 1;

    for(int i = 0; i < (puzzle->size * puzzle->size); i++){
        if(puzzle->grid[i]-1 != (i)){
            if(puzzle->grid[i] == 0){
                continue;
            }
            else{
                return 0;
            }
            
        }
    }
    return 1;
}


Puzzle *copyPuzzle(int *grid, int size, char *image){
    Puzzle *newPuzzle = malloc(sizeof(Puzzle));
    newPuzzle->size = size;
    newPuzzle->grid = malloc( (size * size)*sizeof(int));
    
    for(int i = 0; i < (newPuzzle->size * newPuzzle->size); i++){
        newPuzzle->grid[i] = grid[i];
    }

    newPuzzle->image = malloc(sizeof(char)*(strlen(image)+1));
    strcpy(newPuzzle->image, image);
    return newPuzzle;
}

void followPath(Puzzle *puzzle, char *path){
    for(int i = 0; i < (int)strlen(path); i++){
        if(path[i] == 'r'){
            moveRight(puzzle, findEmptyIndex(puzzle));
        }
        else if(path[i] == 'l'){
            moveLeft(puzzle, findEmptyIndex(puzzle));
        }
        else if(path[i] == 'd'){
            moveDown(puzzle, findEmptyIndex(puzzle));
        }
        else if(path[i] == 'u'){
            moveUp(puzzle, findEmptyIndex(puzzle));
        }
    }
}


char *findSolvePath(Puzzle puzzle, char direction, int moveNum, int emptyIndex, int maxMoves){
    

    if(moveNum == maxMoves){
        return NULL;
    }
    // Puzzle currPuzzle = puzzle;
    Puzzle *currPuzzlePtr = copyPuzzle(puzzle.grid, puzzle.size, puzzle.image);

    if(direction == 'l'){
        emptyIndex = moveLeft(currPuzzlePtr, emptyIndex);
        moveNum += 1;
    }
    else if(direction == 'r'){
        emptyIndex = moveRight(currPuzzlePtr, emptyIndex);
        moveNum += 1;
    }
    else if(direction == 'u'){
        emptyIndex = moveUp(currPuzzlePtr, emptyIndex);
        moveNum += 1;
    }
    else if(direction == 'd'){
        emptyIndex = moveDown(currPuzzlePtr, emptyIndex);
        moveNum += 1;
    }


    if(isSolved(currPuzzlePtr)){
        // printf("solution");
        char *solution = malloc((moveNum*sizeof(char)) +1);
        solution[moveNum] = '\0';
        solution[moveNum-1] = direction;
        deletePuzzle(currPuzzlePtr);
        return solution;
    }

    char *result = NULL;


    if((isLegalMove(currPuzzlePtr, 'l', emptyIndex)) && direction != 'r'){
        // if(moveNum == 0){
        //     printf("left");
        // }
        result = findSolvePath(*currPuzzlePtr, 'l', moveNum, emptyIndex, maxMoves);
        if(result != NULL){
            result[moveNum] = 'l';
            deletePuzzle(currPuzzlePtr);
            return result;
        }
    }

    if((isLegalMove(currPuzzlePtr, 'r', emptyIndex)) && direction != 'l'){
        // if(moveNum == 0){
        //     printf("right");
        // }
        result = findSolvePath(*currPuzzlePtr, 'r', moveNum, emptyIndex, maxMoves);
        if(result != NULL){
            result[moveNum] = 'r';
            deletePuzzle(currPuzzlePtr);
            return result;
        }
    }

    if((isLegalMove(currPuzzlePtr, 'u', emptyIndex)) && direction != 'd'){
        // if(moveNum == 0){
        //     printf("up");
        // }
        result = findSolvePath(*currPuzzlePtr, 'u', moveNum, emptyIndex, maxMoves);
        if(result != NULL){
            result[moveNum] = 'u';
            deletePuzzle(currPuzzlePtr);
            return result;
        }
    }

    if((isLegalMove(currPuzzlePtr, 'd', emptyIndex)) && direction != 'u'){
        // if(moveNum == 0){
        //     printf("sdcwdc");
        // }
        result = findSolvePath(*currPuzzlePtr, 'd', moveNum, emptyIndex, maxMoves);
        if(result != NULL){
            result[moveNum] = 'd';
            deletePuzzle(currPuzzlePtr);
            return result;
        }
    }
    deletePuzzle(currPuzzlePtr);
    return NULL;


}
