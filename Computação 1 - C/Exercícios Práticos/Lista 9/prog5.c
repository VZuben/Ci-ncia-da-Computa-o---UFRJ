#include <stdio.h>

#define DIM 100


void inverte(int tamanho, float vetor[]){
    float temp;

    if (tamanho > DIM/2){
        temp = vetor[tamanho-1];
        vetor[tamanho-1] = vetor [DIM-tamanho];
        vetor[DIM-tamanho] = temp;
        inverte(tamanho - 1, vetor);
    }
    return;
}

int main(){
    int i;
    float vetor[DIM];

    for (i = 0; i < DIM; i++){
        printf("Digite o valor do vetor[%d]\n", i);
        scanf("%f", &vetor[i]);
    }

    inverte(DIM, vetor);

    for (i = 0; i < DIM; i++){
        printf("vetor[%d] = %5.2f\n", i,  vetor[i]);
    }

    return 0;
}