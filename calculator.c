#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int calculate(char* cal[], int N){
    int result = atoi(cal[0]);
    for(int i = 1; i < N; i+=2){
        char op = cal[i][0];
        int num = atoi(cal[i+1]);
        switch(op)
        {
        case '+':
            result  += num;
            break;
        case '-':
            result  -= num;
            break;
        case '*':
            result  *= num;
            break;
        case '/':
            result = floor(result / num);
            break;
        default:
            break;
        }
    }
    return result;
}
int main(){
    printf("How many operation do you want to calculate?: ");
    int N;
    scanf("%d", &N);
    char* cal[N];
    for(int i = 0; i < N; i++){
        cal[i] = (char*)malloc(100 * sizeof(char));
        scanf("%s", cal[i]);
    }
    int result = calculate(cal, N);
    printf("%d\n", result);
    for(int i = 0; i < N; i++){
        free(cal[i]);
    }

    return 0;
}
