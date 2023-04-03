#include <stdio.h>
#include <hellomake.h>
#include <stdlib.h>
#include <mpi.h>

// Emirhan AKITURK 19050111065

/*
    Parallel Matrix-Vector multiplication
    using openmpi
*/

double* matrixVectorMultiplication(double** matrix, double* vector, int x, int y, int rank, int core_count){
    double* result;
    int i,j;
    double sum;
    double time_start, time_end;
    int start_index, end_index, task_size;

    // dividing tasks equally
    task_size = x / core_count;
    start_index = rank * task_size;
    end_index = start_index + task_size;

    result = (double*)malloc(x * sizeof(double));
    
    time_start = MPI_Wtime();
    // parallel calculation
    for(i = start_index; i < end_index;i++){
        sum = 0;
        for (j = 0; j < y; j++){
            sum += matrix[i][j] * vector[j];
        }
        result[i] = sum;
    }

    //combining results
    double* combined_result = (double*)malloc(x * sizeof(double)); 
    MPI_Allreduce(result, combined_result, x, MPI_DOUBLE, MPI_SUM, MPI_COMM_WORLD);
    
    if(rank == 0){
        time_end = MPI_Wtime();
        printf("Core Count: %d\tTime Elapsed: %lfs\n",core_count, time_end-time_start);
    }

    free(result);
    return combined_result;
    }