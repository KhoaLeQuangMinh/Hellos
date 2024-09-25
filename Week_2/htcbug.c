#include <stdio.h>

int main(){
    char b = 'a';
    int n;
    int min;
    int x,y;
    x = 0;
    y = 1;
    char expression = '/';
    min = (x<y) ? x : y;
    float value = (float)b/5;
    printf("%d\n", min);
    switch (expression){
        case '+':
            printf("%d\n", x + y);
            break;
        case '-':
            printf("%d\n", x - y);
            break;
        case '*':
            printf("%d\n", x * y);
            break;
        case '/':
            printf("%d\n", x / y);
            break;
        default:
            break;
    }
    return 0;
}