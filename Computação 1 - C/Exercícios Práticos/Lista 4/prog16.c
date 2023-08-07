#include <stdio.h>
 
int main(void) {
    int N, i, X, j, teste;

    scanf("%d", &N);

    for(i = 1; i <= N; i++){
        teste = 0;
        scanf("%d", &X);
        for (j = 2; j < X; j++){
            if (X % j == 0){
                printf("%d nao eh primo\n", X);
                teste = 1;
                break;
            }
        }
        if (teste == 0){
            printf("%d eh primo\n", X);
        }
    }   
    return 0;
}