#include <dlfcn.h>
#include <stddef.h>
#include <stdio.h>

void* handle = NULL;
#define GetProcAddress dlsym

// COMPLILE
// gcc -DLESS sort_import_function.c -o main
// gcc sort_import_function.c -o main
// declare function pointers

int (*greater) (int, int);
int (*less) (int, int);
void (*bubble_sort) (int*, int, int(*func)(int, int));

void DllOpen(const char* lib_name)
{
    handle = dlopen(lib_name, RTLD_LAZY);

    if (!handle)
    {
        printf("Could not load library: %s\n", lib_name);
        return;
    }

    greater = (int (*)(int, int)) GetProcAddress(handle, "greater");
    less = (int (*)(int, int)) GetProcAddress(handle, "less");
    bubble_sort = (void(*)(int*, int, int(*func)(int,int))) GetProcAddress(handle, "bubble_sort");
}

int main()
{
    int N = 5;
    int arr[] = { 1, 4, 3, 7, 6 };
    DllOpen("./sort_lib.so");
#ifdef LESS
    bubble_sort(arr, N, less);
#else
    bubble_sort(arr, N, greater);
#endif
    for(int i = 0; i < N; i++){
        printf("%d", arr[i]);
    }

    return 0; // set break point
}