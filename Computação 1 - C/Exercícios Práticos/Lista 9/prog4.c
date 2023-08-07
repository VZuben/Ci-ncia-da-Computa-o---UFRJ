#include <stdio.h>

int fat(int N){
    if (N > 0){
        return N * (fat(N-1));
    }
    else {
        return 1;
    }
}

int main(){
    int N;
    
    printf("Digite um numero para ser tirado seu fatorial.\n");
    scanf("%d", &N);

    if (N < 0){
        printf("Nao existe fatorial de numero negativo");
        return 1;
    }

    printf("O fatorial de %d eh %d.\n", N, fat(N));

    return 0;
}