#include <stdio.h>

#define N 5

int maior(int posicao, int vetor[], int maior_numero){
    if (posicao == 0){
        return maior_numero;
    }
    else if (maior_numero < vetor[posicao-1]){
        return maior(posicao-1, vetor, vetor[posicao-1]);
    }
    else {
        return maior(posicao-1, vetor, maior_numero);
    }
}

int main(){
    int vetor[N], i;

    for (i = 0; i < N; i++){
        printf("Digite o valor do vetor[%d]\n", i);
        scanf("%d", &vetor[i]);
    }

    printf("O maior elemento deste vetor eh: %d\n", maior(N-1, vetor, vetor[N-1]));

    return 0;
}