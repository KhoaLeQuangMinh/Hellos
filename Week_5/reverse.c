#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// define your swap function here

// reverse array function
void reverse_array(int *arr, int N)
{
    // your code here
    int NN = N/2;
    for(int i = 0; i < NN; i++ ){
        int j = N - 1 - i;
        int temp = arr[j];
        arr[j] = arr[i];
        arr[i] = temp;
    }
    // use your swap function
}

int main()
{
    int arr[] = {1, 4, 3, 7, 6};
    reverse_array(arr, 5);
    for (int i = 0; i < 5; i++){
        printf("%d\n", arr[i]);
    }
    return 0; // set break point
}