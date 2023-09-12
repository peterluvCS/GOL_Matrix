#include <stdio.h>
#include <stdlib.h>

void printMatrix(unsigned int *matrix) {
    for (int i = 0; i < 5; i++){
        for (int j = 0; j < 5; j++){
            printf("%d", *(matrix + 5 * i + j - 1));
        }
        printf("\n");
    }
} 

unsigned int countNeighbors(char array[5][5],int row, int col) {
    char * ptr = &array[0][0];
    ptr = ptr + row * 5 + col;

    unsigned int sum = 0;
    if (*(ptr+1) == '*') sum++;
    if (*(ptr-1) == '*') sum++;
    if (*(ptr+5) == '*') sum++;
    if (*(ptr-5) == '*') sum++;
    if (*(ptr+4) == '*') sum++;
    if (*(ptr+6) == '*') sum++;
    if (*(ptr-4) == '*') sum++;
    if (*(ptr-6) == '*') sum++;

    return sum;
}

int main() {
    
    unsigned int matrix[5][5];
    unsigned int *ptr = matrix;
    for (int i = 0; i < 5; i++){{}
        for (int j = 0; j < 5; j++) {
            if (i == 2){
                matrix[i][j] = 1;
            } else {
                matrix[i][j] = 0;
            }           
        }
    }

    printf("%d\n", countNeighbors(matrix, 2, 2));
    

    return EXIT_SUCCESS;
}