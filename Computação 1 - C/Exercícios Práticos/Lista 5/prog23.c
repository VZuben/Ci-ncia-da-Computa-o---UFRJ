#include <stdio.h>
#include <string.h>
 
int main() {
    int N, M, k, i, j;
    unsigned long long int matrix[21][21], n_digitos[100], maior[100];
    char formato[20];
    
    scanf("%d ", &N);
    for (k = 0; k < N; k++){

        scanf("%d ", &M);
        for (i = 0; i < M; i++){
            for (j = 0; j < M; j++){
                scanf("%llu", &matrix[i][j]);
            }
        }

        for (i = 0; i < M; i++){
            for (j = 0; j < M; j++){
                matrix[i][j] *= matrix[i][j];
            }
        }

        for(j = 0; j < 100; j++){
            maior[j] = 0;
            n_digitos[j] = 0;
        }

        for(i = 0; i < M; i++){
            for(j = 0; j < M; j++){
                if(matrix[i][j] > maior[j]){
                    maior[j] = matrix[i][j];
                }
            }
        }

        for(j = 0; j < M; j++){   
            while(maior[j] != 0){
                n_digitos[j] = n_digitos[j] + 1;
                maior[j] = maior[j] / 10;
            }
        }

        if(k > 0) printf("\n");
        printf("Quadrado da matriz #%d:\n", k + 4);
        for(i = 0; i < M; i++){
            for(j = 0; j < M; j++){
                if(j > 0) printf(" ");
                sprintf(formato,"%%%llullu", n_digitos[j]);
                printf(formato, matrix[i][j]);
            }
            printf("\n");
        }
    }
    return 0;
}
