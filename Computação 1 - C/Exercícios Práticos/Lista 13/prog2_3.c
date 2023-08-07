#include <stdio.h>
#include <stdlib.h>

#define TAM 10

typedef struct _CELULA {
    int conteudo;
    struct _CELULA *prox;
} CELULA;

int profundidade(CELULA *primeiro, CELULA *c){
    int contador = 0;
    CELULA *p = primeiro;

    while(p != c){
        contador++;
        p = p->prox;
    }
    return contador-1;
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

    printf("Profundidade: %d\n", profundidade(primeiro, p));

    return 0;
}