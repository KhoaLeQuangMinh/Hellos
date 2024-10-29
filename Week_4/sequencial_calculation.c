#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
    double *a = malloc(8*sizeof(float));
    for(int i = 0; i < 8; i++){
        a[i] = i;
    }
    for(int j = 0; j < 8; j++){
        printf("%f\n", a[j]);
    }
    printf("%lu\n", sizeof(double));
    printf("%lu\n", sizeof(char));
    free(a);
    return 0;

}