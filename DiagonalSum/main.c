/*
 * Author: Madhu
 * Source: https://www.hackerrank.com/contests/smart-interviews/challenges/si-diagonal-traversal-of-matrix
 * Date: 18-10-2017
 */

#include <stdio.h>
#include <stdlib.h>

void scanMatrix(int **matrix, int rows, int cols) {
    int i,j;
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
}

int findDiagonalSum(int **matrix, int x, int y, int size) {
    int sum = 0;
    for (int i = x, j = y; i < size && j < size; i++, j++) {
        sum += matrix[i][j];
    }
    return sum;
}

void printDiagonalSums(int **matrix, int size) {
    int i,j;
    for(i = size -1; i >= 0; i--)
        printf("%d ", findDiagonalSum(matrix, 0, i, size));
    for(i = 1; i < size; i++)
        printf("%d ", findDiagonalSum(matrix, i, 0, size));
    printf("\n");
}

int main() {
    int testcases;
    scanf("%d", &testcases);
    while(testcases--) {
        int **matrix, size;
        scanf("%d", &size);
        matrix = (int **)malloc(sizeof(int *) * size);
        for(int i = 0; i < size; i++)
            matrix[i] = (int *)malloc(sizeof(int) * size);
        scanMatrix(matrix, size, size);
        printDiagonalSums(matrix, size);
    }
}