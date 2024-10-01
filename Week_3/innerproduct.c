#include <stdio.h>
#include <stdlib.h>

int innerproduct(int* a, int* b, int n){
    int result = 0;
    for (int i = 0; i < n; i++){
        result += a[i]*b[i];
    }
    return result;
}
int main(){
    int n;
    scanf("%d", &n);
    int* a = malloc(n*sizeof(int));
    int* b = malloc(n*sizeof(int));
    for(int i = 0; i < n; i++){
        printf("Enter %dth Vector A\n", i+1);
        scanf("%d", &a[i]);
    } 
    for(int i = 0; i < n; i++){
        printf("Enter %dth Vector B\n", i+1);
        scanf("%d", &b[i]);

    }
    printf("The innerproduct of A and B is %d\n", innerproduct(a, b, n));
    
    free(a);
    free(b);
    return 0;
}