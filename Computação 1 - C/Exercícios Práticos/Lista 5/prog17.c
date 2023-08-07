#include <stdio.h>
#include <string.h>
 
int main(){
    char string[100][51];
    int N, k, soma, L, i, j;

    scanf("%d ", &N);
    for (k = 0; k < N; k++){
        soma = 0;

        scanf("%d ", &L);
        for (i = 0; i < L; i++){
            fgets(string[i], 51, stdin);
            string[i][strlen(string[i])-1] = 0;
        }

        for (i = 0; i < L; i++){
            for (j = 0; j < strlen(string[i]) ; j++){
                soma += (string[i][j] - 65) + i + j;
            }
        }
        if (k < N - 1)
            printf("%d \n", soma);
        else 
            printf("%d\n", soma);

    }
    return 0;
}