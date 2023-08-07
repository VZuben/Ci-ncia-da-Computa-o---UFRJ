#include <stdio.h>

int main (void){
    int N, i, j;
    
    scanf("%d",&N);

    for (i = 1; i <= N; i++) {
        int X, Y, soma_impar;
        soma_impar = 0;

        scanf("%d %d", &X, &Y);
        if (X < Y){
            for (j = X + 1; j < Y; j++){
                if (j % 2 != 0){
                soma_impar += j;
                }
            }
        }   
        if (X > Y){
            for (j = Y + 1; j < X; j++){
                if (j % 2 != 0){
                soma_impar += j;
                }
            }
        }
    printf("%d\n", soma_impar);
    }
    return 0;
}