#include <stdio.h>
#include <stdlib.h>

struct _point {
    unsigned int sum;
    char state;
};
typedef struct _point point;

void printMatrix(point *matrix) {
    for (int i = 1; i <= 5; i++){
        for (int j = 1; j <= 5; j++){
            printf("%c ", (matrix + 7 * i + j)->state);
        }
        printf("\n");
    }
} 

void countNeighbors(point *matrix) {
    point *ptr = matrix;
   
    if ((ptr+1)->state == '*') ptr->sum++;
    if ((ptr-1)->state == '*') ptr->sum++;
    if ((ptr+6)->state == '*') ptr->sum++;
    if ((ptr-6)->state == '*') ptr->sum++;
    if ((ptr+7)->state == '*') ptr->sum++;
    if ((ptr-7)->state == '*') ptr->sum++;
    if ((ptr+8)->state == '*') ptr->sum++;
    if ((ptr-8)->state == '*') ptr->sum++;

    //return sum;
}

void changeState(point *matrix){
    point *ptr = matrix;

    if (ptr->state == '*') {
        if (ptr->sum < 2 || ptr->sum > 3) {
            ptr->state = ' ';
        } else {
            ptr->state = '*';
        }
    } else if (ptr->state == ' ') {
        if (ptr->sum < 3 || ptr->sum > 3) {
            ptr->state = ' ';
        } else {
            ptr->state = '*';
        }
    }
}

int main() {
    
    point matrix[7][7];

    point defaultPoint;
    defaultPoint.state = ' ';
    defaultPoint.sum = 0;

    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < 7; j++) {
            matrix[i][j] = defaultPoint;
        }
    }

    point *ptr = matrix;

    for (int j = 1; j <= 5; j++){       
        (ptr + 3 * 7 + j)->state = '*';
        //matrix[3][j]->state = '*';        
    }
    // printMatrix(matrix);
    //unsigned int (*ptr)[7] = matrix;
    //printMatrix(matrix);
    
    point *element;
    for (int row = 1; row <= 5; row++) {
        for (int col = 1; col <= 5; col++) {
            element = &matrix[row][col];
            countNeighbors(element);
        }
    }

    for (int row = 1; row <= 5; row++) {
        for (int col = 1; col <= 5; col++) {
            element = &matrix[row][col];
            changeState(element);
        }
    }

    printMatrix(matrix);
    
    

    return EXIT_SUCCESS;
}