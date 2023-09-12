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