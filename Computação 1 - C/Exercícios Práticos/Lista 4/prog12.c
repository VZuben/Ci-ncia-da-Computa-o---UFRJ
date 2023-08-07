#include <stdio.h>
 
int main (void){
    int N, i;

    scanf("%d", &N);

    for (i = N - 1; i > 1 ; i--){
        N *= i;
    }
    printf("%d\n", N);
    return 0;
}