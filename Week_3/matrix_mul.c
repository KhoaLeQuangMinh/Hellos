#include <stdio.h>
#include <stdlib.h>

int** matrix_mul(int** matrix_1, int** matrix_2, int a, int b, int x, int y){
    int rows;
    int columns;
    if((b != x)){
        return 0;
    }
    // allocate memories for result
    int** result = (int**)malloc(a*sizeof(int*));
    rows = a;
    columns = y;
    for(int i = 0; i < a; i++){
        result[i] = (int*)malloc(y*sizeof(int));
    }

    // setting the default values to 0
    for (int i = 0; i < rows; i++){
        for(int j = 0; j < columns; j ++){
            result[i][j] = 0;
        }
    }
    // multiply matrix
    for (int i = 0; i < rows; i++){
        for(int j = 0; j < columns; j ++){
            for(int k = 0; k < b; k++){
                result[i][j] += matrix_1[i][k] * matrix_2[k][j]; // i is the anchor for the first matrix in term of rows and j is the anchor for the second matrix in term of column then k will be the variable that runs among them
            }
            
        }
    }
    
    return result;
}


int main(){
    int a,b;
    int x,y;
    int rows;
    int columns;
    printf("The number of rows in the first Matrix: ");
    scanf("%d",&a);
    printf("The number of columns in the first Matrix: ");
    scanf("%d",&b);
    printf("The number of rows in the second Matrix: ");
    scanf("%d",&x);
    printf("The number of columns in the second Matrix: ");
    scanf("%d",&y);

    // allocate matrix_1
    int** matrix_1 = (int**)malloc(a * sizeof(int*));
    for(int i = 0; i < a; i++){
        matrix_1[i] = (int*)malloc(b * sizeof(int));
    }

    for(int i = 0; i < a; i++){
        for(int j = 0; j < b; j++){
            printf("Enter the element [%d][%d] of the first matrix: ", i,j);
            scanf("%d", &matrix_1[i][j]);
        }
    }

    // allocate matrix_2
    int** matrix_2 = (int**)malloc(x * sizeof(int*));
    for(int i = 0; i < x; i++){
        matrix_2[i] = (int*)malloc(y * sizeof(int));
    }

    for(int i = 0; i < x; i++){
        for(int j = 0; j < y; j++){
            printf("Enter the element [%d][%d] of the second matrix: ", i,j);
            scanf("%d", &matrix_2[i][j]);
        }
    }

    if (b == x){
        rows = a;
        columns = y;
    }
    
    // get values from the function
    int** result = matrix_mul(matrix_1, matrix_2, a, b, x, y);
    for (int i = 0; i < rows; i++){
        for(int j = 0; j < columns; j ++){
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }

    // free all the memories
    for (int i = 0; i < a; i++) {
        free(matrix_1[i]);  // Free each row
    }
    free(matrix_1);

    for (int i = 0; i < x; i++) {
        free(matrix_2[i]);  // Free each row
    }
    free(matrix_2);

    for (int i = 0; i < a; i++) {
        free(result[i]);
    }
    free(result);
    return 0;
}