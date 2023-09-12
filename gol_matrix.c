#include <stdio.h>
#include <stdlib.h>

// void printMatrix(char *matrix) {
//     for (int i = 0; i < 5; i++){
//         for (int j = 0; j < 5; j++){
//             printf("%c", *(matrix + i * 5+ j));
//         }
//     }
// }

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
    char matrix[5][5];

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (i == 2) {
                matrix[i][j] = '*';
            } else {
                matrix[i][j] = ' ';
            }
        }
    }

    printf("%d\n", countNeighbors(matrix, 2, 2));
    

    return EXIT_SUCCESS;
}