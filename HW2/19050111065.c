#include <stdlib.h>

int main() {
    int i, j, x, y;
    char str[25];
    
    scanf("%d %d %s",&x, &y, str);
    
    double* matrix[x];
    for (i = 0; i < x; i++){
        matrix[i] = (double*) malloc(y * sizeof(double));
    }

    return 0;
}