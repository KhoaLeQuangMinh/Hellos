
extern int greater(int a, int b);
extern int less(int a, int b);
extern void bubble_sort(int* arr, int N, int(*func)(int, int));

// COMPILE 
// gcc -c -fPIC sort_lib.c -o sort_lib.o
// gcc sort_lib.o -shared -o sort_lib.so
// exchange values of the pointers
void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubble_sort(int* arr, int N, int(*func)(int, int))
{
    if (N >= 2)
    {
        for (int i = 0; i < N - 1; i++)
        {
            if (func(arr[i],arr[i + 1]))
            {
                swap(&(arr[i]), &arr[i + 1]);
            }
        }

        bubble_sort(arr, N - 1, func);
    }
}

int greater(int a, int b)
{
    return a > b ? 1 : 0; // ternary operator
}


int less(int a, int b)
{
    return a < b ? 1 : 0; // ternary operator
}