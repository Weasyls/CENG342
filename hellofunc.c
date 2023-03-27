#include <stdio.h>
#include <hellomake.h>

double* matrixVectorMultiplication(double** matrix, double* vector, int x, int y){
    int i = 0, j = 0;
    double* result = (double*)malloc(5 * sizeof(double));
    for(i = 0; i < x; i++){
        for(j = 0; j < y; j++){
            result[i] += matrix[i][j] * vector[j];
        }
    }
    return result;
}