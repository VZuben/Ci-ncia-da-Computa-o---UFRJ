#include <stdio.h>
#include <stdlib.h>

#define TAM 10

typedef struct _CELULA {
    int conteudo;
    struct _CELULA *prox;
} CELULA;

int altura(CELULA *p){
    int contador=0;
    while(p != NULL){
        contador++;
        p = p->prox;
    }
    return contador;
}

int main(){
    int i, posicao;
    CELULA *primeiro, *p, *temp;

    for (i = 0; i < TAM; i++){
        p = (CELULA *) malloc(sizeof(CELULA));
        if (!p){
            printf("Sem memoria!");
            return 1;
        }
        printf("Entre o valor da posicao [%d]: ", (i+1));
        scanf("%d", &(p->conteudo));

        p->prox = NULL;

        if (i == 0){
            primeiro = p;
        } else{
            temp->prox = p;
        }

        temp = p;
    }

    printf("Entre com a posicao do elemento: ");
    scanf("%d", &posicao);

    p = primeiro;

    for (i = 0; i < posicao; i++){
        p = p->prox;
    }

    printf("Altura: %d\n", altura(p));

    return 0;
}