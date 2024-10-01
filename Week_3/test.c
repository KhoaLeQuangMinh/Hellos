#include <stdio.h>
#include <stdlib.h>

// Function to get the max values along the specified axis (0 for columns, 1 for rows)
void get_max_2d_array(int** arr, int rows, int columns, int axis, int result[]) {
    if (axis == 0) {  // Max along columns
        for (int i = 0; i < columns; i++) {
            int max = arr[0][i];  // Initialize with the first element in the column
            for (int j = 1; j < rows; j++) {
                if (arr[j][i] > max) {
                    max = arr[j][i];  // Find the max in the column
                }
            }
            result[i] = max;  // Store max value for this column
        }
    } else if (axis == 1) {  // Max along rows
        for (int i = 0; i < rows; i++) {
            int max = arr[i][0];  // Initialize with the first element in the row
            for (int j = 1; j < columns; j++) {
                if (arr[i][j] > max) {
                    max = arr[i][j];  // Find the max in the row
                }
            }
            result[i] = max;  // Store max value for this row
        }
    }
}

int main() {
    int rows, columns;
    
    // Get dimensions from the user
    printf("Enter the number of rows: ");
    scanf("%d", &rows);
    
    printf("Enter the number of columns: ");
    scanf("%d", &columns);

    // Dynamically allocate memory for the 2D array
    int** arr = (int**)malloc(rows * sizeof(int*)); // the address of the array of pointers
    for (int i = 0; i < rows; i++) {
        arr[i] = (int*)malloc(columns * sizeof(int)); // the address of the array
    }

    // Get elements of the 2D array from the user
    printf("Enter the elements of the 2D array:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            printf("Element at [%d][%d]: ", i, j);
            scanf("%d", &arr[i][j]);
        }
    }

    int max_columns[columns];  // Array to store max values along columns
    int max_rows[rows];        // Array to store max values along rows

    // Get the max values along columns (axis 0)
    get_max_2d_array(arr, rows, columns, 0, max_columns);

    // Print max values for each column
    printf("Max along columns: ");
    for (int i = 0; i < columns; i++) {
        printf("%d ", max_columns[i]);
    }
    printf("\n");

    // Get the max values along rows (axis 1)
    get_max_2d_array(arr, rows, columns, 1, max_rows);

    // Print max values for each row
    printf("Max along rows: ");
    for (int i = 0; i < rows; i++) {
        printf("%d ", max_rows[i]);
    }
    printf("\n");

    // Free dynamically allocated memory
    for (int i = 0; i < rows; i++) {
        free(arr[i]);  // Free each row
    }
    free(arr);  // Free the array of pointers

    return 0;
}