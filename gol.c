#include <stdio.h>
#include <string.h>

//define the dimensions of the matrix
#define row 5
#define col 5

//store user's decision about whether continue the game
char choice[4];

//compute the amount of this cell's neighbors in alive state
unsigned int countNeighbors(char *board, int r, int c) {
    unsigned int count = 0;
    //search the outside 8 cells' states of this cell in order
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            //cells of row 0 and column 0 don't have 8 neighbors
            //list these possibles to exclude them
            if ((r + i < 0) | (r + i > 4) | (c + j < 0) | (c + j > 4) | (i == 0 && j == 0)) {
                continue;
            }
            if (*(board + i * col + j) == '*') {
                count ++;
            }
        }
    }

    return count;

}

//receive the alive neighbors amount computed from function countNeighbors
//update the state on another board according to the GOL rules
void nextState(char *oldBoard, char *newBoard, int neighbors) {
    //GOL rules: cell only becomes alive when
    //1. cell's original state is alive and the amount of alive neighbors = 2 or 3
    //2. cell's original state is dead and the amount of alive neighbors = 3
    if (*oldBoard == '*' && (neighbors == 2 || neighbors == 3)) {
        *newBoard = '*';
    } else if (*oldBoard == ' ' && (neighbors == 3)) {
        *newBoard = '*';
    } else {
        *newBoard = ' ';
    }
}

void check_and_next(char *initialBoard, char *newBoard) {
    //visit cells on board in order
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            //firstly compute amount of the alive neighbors
            unsigned int neighbors = countNeighbors(initialBoard + i * row + j, i, j);

            //secondly update states of cells on the new board
            nextState(initialBoard + i * row + j, newBoard + i * row + j, neighbors);
        }
    }

   //print the current state of matrix
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            printf("%c ", *(newBoard + i * row + j));
            *(initialBoard + i * row + j) = *(newBoard + i * row + j);
        }
        printf("\n");
    }

    printf("Continue the Game of Life? (Type yes or not)\n");
    gets(choice);
}

int main (void) {
    //define the initial state of cells in the original board
    //space stands for dead state, * stands for alive state
    char initialBoard[row][col] = {
        {' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' '},
        {'*', '*', '*', '*', '*'},
        {' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' '},
    };
    
    //initialize a new board to show the updated matrix
    char newBoard[row][col]= {
        {' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' '},
    };

    //if user want to update more times,
    //he can type "yes" or "no" to decide whether to continue the game
    printf("Continue the Game of Life? (Type yes or not)\n");

    gets(choice);
    while (strcmp(choice, "yes") == 0) {
        check_and_next(&initialBoard[0][0], &newBoard[0][0]);
    }


    return 0;
}