#include <stdio.h>
#include <stdlib.h>
int main(){
    int n ;
    scanf("%d",&n);
    int ans = 1;
    for(int i = 1; i<= n; i++){
        ans *= i;
    }
    int ans2 = 1;
    for (int i = n; i > 0; i--){
        ans2 *= i;
    }
    printf("%d\n",ans);
    printf("%d\n",ans2);
    return 0;
}