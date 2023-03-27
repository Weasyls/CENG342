#include <hellomake.h>
#include <stdlib.h>
#include <stdio.h>

double randDouble();

int main(int argc, char *argv[]) {
    int i, j, x = atoi(argv[1]), y = atoi(argv[2]);
    char* str = argv[3];
    FILE *fp = fopen(str, "w+");

    srand(19050111065);
    
    //Creates 2d array according to x, y given by user
    double* matrix[x];
    for (i = 0; i < x; i++){
        matrix[i] = (double*)malloc(y * sizeof(double));
    }

    //Fills array with random doubles
    for(i = 0; i < x; i++){
        for(j = 0; j < y; j++){
            matrix[i][j] = randDouble();
        }
    }

    double vector_size = 6;
    double* vector = (double*)malloc(vector_size * sizeof(double));
    
    for(i = 0; i < vector_size; i++){
        vector[i] = randDouble();
    }

    double* result = matrixVectorMultiplication(matrix, vector, x, y);
    
    for(i = 0; i < x;i++){
        fprintf(fp, "%lf\n", result[i]);
    }
    fclose(fp);

    return 0;

    
}

double randDouble(){
    double max = 100.0, min = 1.0;
    /*random double between 0.0 - 1.0 divided by RAND_MAX and multiplied by range(max - min) in this case
    99.0 after we add the min value to get the random number */ 
    double number = ((double) rand() / RAND_MAX) * (max - min) + min;
    return number;
}