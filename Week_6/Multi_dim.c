#include <stdlib.h>
#include <time.h>
#include <stdio.h>

struct MultiArray
{
    int* data;
    int* shape;
};

/**
 * Indexing multi array using an index array
 *
 * array [2][1] = get_data(array, [2, 1])
*/
int get_data(struct MultiArray* array, int* indexes, int n_dims)
{
    int flatten_index = 0;
    int multi_index = 1;
    for (int i = n_dims-1; i >= 0; i--){
        flatten_index += indexes[i]*multi_index;
        multi_index *= array->shape[i];
    }
    return array->data[flatten_index];
}

int main()
{
    // set random seed to current time
    srand(time(NULL));

    struct MultiArray* array = malloc(sizeof(struct MultiArray));

    // create 3x4 array
    array->data = malloc(3 * 2 * 2 * sizeof(int));

    // assign random data (0 -> 9)
    for (int i = 0; i < 3 * 2 * 2; i++)
    {
        array->data[i] = i;
        // printf("array->data[%d] = %d\n", i, array->data[i]);
    }

    // assign shape
    array->shape = malloc(3 * sizeof(int));
    array->shape[0] = 3;
    array->shape[1] = 2;
    array->shape[2] = 2;

    int indexes[] = { 1, 0, 1 };
    int out = get_data(array, indexes, 3);
    printf("%d\n",out);
    return 0;
}