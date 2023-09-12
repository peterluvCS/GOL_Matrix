#include <stdio.h>
#include <stdlib.h>

void printMatrix(char *matrix) {
    for (int i = 0; i < 5; i++){
        for (int j = 0; j < 5; j++){
            printf("%c", *(matrix + i * 5+ j));
        }
    }
} 

int main() {
    char matrix[5][5];
    for (int j = 0; j < 5; j++) {
        matrix[2][j] = '*' ;
    }
    printMatrix(*matrix);
    

    return EXIT_SUCCESS;
}