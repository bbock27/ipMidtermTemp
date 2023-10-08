#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "puzzle.h"

// TODO: implement functions

Puzzle *createPuzzle(int size){

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
        if((emptyIndex) / (puzzle->size) == 0){
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
void moveLeft(Puzzle *puzzle, int emptyIndex){
    
    puzzle->grid[emptyIndex] = puzzle->grid[emptyIndex+1];
    puzzle->grid[emptyIndex+1] = 0;
    
}

//slides tile right -- results in the open space moving to the left
void moveRight(Puzzle *puzzle, int emptyIndex){
    puzzle->grid[emptyIndex] = puzzle->grid[emptyIndex-1];
    puzzle->grid[emptyIndex-1] = 0;
}

//slides tile down -- results in the open space moving up
void moveDown(Puzzle *puzzle, int emptyIndex){
    puzzle->grid[emptyIndex] = puzzle->grid[emptyIndex-puzzle->size];
    puzzle->grid[emptyIndex-puzzle->size] = 0;
}

//slides tile up -- results in the open space moving down
void moveUp(Puzzle *puzzle, int emptyIndex){
    puzzle->grid[emptyIndex] = puzzle->grid[emptyIndex+puzzle->size];
    puzzle->grid[emptyIndex+puzzle->size] = 0;
}

int isSolved(Puzzle *puzzle){
    for(int i = 1; i < puzzle->size; i++){
        if(puzzle->grid[i] == 0){
            if(i == (puzzle->size-1)){
                return 1;
            }

            if(puzzle->grid[i+1] < puzzle->grid[i-1]){
                return 0;
            }
            i++;
        }
        if(puzzle->grid[i] < puzzle->grid[i-1]){
            return 0;
        }
    }
    return 1;
}




char *solve(Puzzle *puzzle, char direction, int moveNum, int emptyIndex){
    if(isSolved(puzzle)){
        char *solution = malloc((moveNum*sizeof(char)) +1);
        solution[moveNum] = '\0';
        solution[moveNum-1] = direction;
        return solution;
    }

    if(moveNum == 100){
        return NULL;
    }

    Puzzle *currPuzzle = puzzle;

    if(direction == 'l'){
        moveLeft(currPuzzle, emptyIndex);
    }
    else if(direction == 'r'){
        moveRight(currPuzzle, emptyIndex);
    }
    else if(direction == 'u'){
        moveUp(currPuzzle, emptyIndex);
    }
    else if(direction == 'd'){
        moveDown(currPuzzle, emptyIndex);
    }

    char *result;


    if((isLegalMove(currPuzzle, 'l', emptyIndex)) && direction != 'r'){
        result = solve(currPuzzle, 'l', moveNum+1, emptyIndex+1);
        if(result == NULL){
            return NULL;
        }
        else{
            return result;
        }
    }

    if((isLegalMove(currPuzzle, 'r', emptyIndex)) && direction != 'l'){
        result = solve(currPuzzle, 'r', moveNum+1, emptyIndex-1);
        if(result == NULL){
            return NULL;
        }
        else{
            return result;
        }
    }

    if((isLegalMove(currPuzzle, 'u', emptyIndex)) && direction != 'd'){
        result = solve(currPuzzle, 'u', moveNum+1, emptyIndex-(currPuzzle->size));
        if(result == NULL){
            return NULL;
        }
        else{
            return result;
        }
    }

    if((isLegalMove(currPuzzle, 'd', emptyIndex)) && direction != 'u'){
        result = solve(currPuzzle, 'r', moveNum+1, emptyIndex+(currPuzzle->size));
        if(result == NULL){
            return NULL;
        }
        else{
            return result;
        }
    }


}
