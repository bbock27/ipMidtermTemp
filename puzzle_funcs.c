#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "puzzle.h"

// TODO: implement functions

Puzzle *createPuzzle(int size){

    
    
}


int findEmptyIndex(Puzzle *puzzle){
    for(int i = 0; i < (puzzle->size * puzzle->size); i++){
        if(puzzle->grid[i] == 0){
            return i;
        }
    }
    return -1;
}



int isLegalMove(Puzzle *puzzle, char direction, int emptyIndex){
    if(direction == 'l'){
        if((emptyIndex+1) % (puzzle->size) == 0){
            return 0; //false
        }
        return 1; // true
    }
    else if(direction == 'r'){
        if((emptyIndex-1) % (puzzle->size) == 0){
            return 0; //false
        }
        return 1; // true
    }
    else if(direction == 'd'){
        if(emptyIndex - puzzle->size >= 0){
            return 0; //false
        }
        return 1; // true
    }

    else if(direction == 'u'){
        if((emptyIndex) + (puzzle->size) >= puzzle->size){
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
            return 0;
        }
    }
    return 1;
}


Puzzle *copyPuzzle(int *grid, int size, char *image){
    Puzzle *newPuzzle = malloc(sizeof(Puzzle));
    newPuzzle->size = size;
    for(int i = 0; i < (newPuzzle->size * newPuzzle->size); i++){
        newPuzzle->grid[i] = grid[i];
    }
    strcpy(newPuzzle->image, image);
    return newPuzzle;
}


char *solve(Puzzle puzzle, char direction, int moveNum, int emptyIndex){
    
    

    if(moveNum == 1000){
        return NULL;
    }
    Puzzle currPuzzle = puzzle;
    Puzzle *currPuzzlePtr = &currPuzzle;

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

    if(isSolved(&puzzle)){
        char *solution = malloc((moveNum*sizeof(char)) +1);
        solution[moveNum] = '\0';
        solution[moveNum-1] = direction;
        return solution;
    }

    char *result = NULL;


    if((isLegalMove(currPuzzlePtr, 'l', emptyIndex)) && direction != 'r'){
        result = solve(*currPuzzlePtr, 'l', moveNum, emptyIndex);
        if(result != NULL){
            return result;
        }
    }

    if((isLegalMove(currPuzzlePtr, 'r', emptyIndex)) && direction != 'l'){
        result = solve(*currPuzzlePtr, 'r', moveNum, emptyIndex);
        if(result != NULL){
            return result;
        }
    }

    if((isLegalMove(currPuzzlePtr, 'u', emptyIndex)) && direction != 'd'){
        result = solve(*currPuzzlePtr, 'u', moveNum, emptyIndex);
        if(result != NULL){
            return result;
        }
    }

    if((isLegalMove(currPuzzlePtr, 'd', emptyIndex)) && direction != 'u'){
        result = solve(*currPuzzlePtr, 'd', moveNum, emptyIndex);
        if(result != NULL){
            return result;
        }
    }
    return NULL;


}
