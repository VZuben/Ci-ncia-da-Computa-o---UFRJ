#include <stdio.h>

int main (void){
    int N, i, j;
    
    scanf("%d",&N);

    for (i = 1; i <= N; i++) {
        int X, s_div;
        s_div = 0;

        scanf("%d",&X);
        for (j = 1; j < X; j++) {
            if((X%j) == 0){
                s_div += j;
            }
        }
        if (s_div == X) {
            printf("%d eh perfeito\n", X);
        }
        else {
            printf("%d nao eh perfeito\n", X);
        }
    }
    return 0;
}