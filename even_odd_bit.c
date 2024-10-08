#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int *toBinary(int n, int *size){
    int *out = malloc((floor(log2(n))+1)*sizeof(int));
    *size = floor(log2(n))+1;
    for(int i = 0; i < *size; i++){
        out[i] = n%2;
        n /= 2;
    }
    return out;
}
int main(){
    int n;
    int size = 0;
    scanf("%d", &n);
    int *ptr_arr = toBinary(n, &size);
    int even_odd[2];
    even_odd[0] = 0;
    even_odd[1] = 0;

    for(int i = 0; i < size; i++){
        if (ptr_arr[i] % 2 != 0 && i % 2 == 0){
            even_odd[0] += 1;
        }
        else if(ptr_arr[i] % 2 != 0 && i % 2 != 0){
            even_odd[1] += 1;
        }
    }
    
    printf("The number of even is: %d\n", even_odd[0]);
    printf("The number of odd is: %d\n", even_odd[1]);
    free(ptr_arr);
    return 0;
}