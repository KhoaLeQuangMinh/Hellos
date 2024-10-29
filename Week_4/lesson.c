#include <stdio.h>
#include <stdlib.h>

int main(){
    int arr[5] = {1,2,3,4,5};
    int *ptr = arr;
    for(int i = 0; i < 5; i++){
        printf("%d\n", *(ptr+i));
        printf("%d\n", ptr[i]);
        printf("%d\n", arr[i]);
        printf("%d\n", *(&ptr[i]));
        printf("%d\n", *(&arr[i]));

    }
    int** n_ptr = malloc(5*sizeof(int*));
    for(int i = 0; i < 5; i++){
        n_ptr[i] = ptr+i;
    }
    for(int j = 0; j < 5; j++){
        printf("%d\n", *(n_ptr[j]));
    }   
}