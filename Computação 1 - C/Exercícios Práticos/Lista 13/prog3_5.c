#include <stdio.h>
#include <stdlib.h>

#define TAM 5

typedef struct _CELULA {
    int conteudo;
    struct _CELULA *prox;
} CELULA;

CELULA *menor_iterativo(CELULA *p) {
    CELULA *p_min;
    p_min = p;
    while (p != NULL){
        if (p_min->conteudo > p->conteudo)
            p_min = p;
        p = p->prox;
    }
    return p_min;
}

CELULA *menor_recurssivo(CELULA *p) {
    static CELULA *p_min = NULL;

    if ((p_min == NULL) || (p_min->conteudo > p->conteudo))
        p_min = p;
    if (p->prox == NULL)
        return p_min;
    else
        return menor_recurssivo(p->prox);
    }


int main(){
    int i;
    CELULA *le, *p, *temp;

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
            le = p;
        } else{
            temp->prox = p;
        }

        temp = p;
    }

    p = menor_iterativo(le);
    printf("Iterativo: O menor conteudo eh: %d\n", p->conteudo);

    p = menor_recurssivo(le);
    printf("Recurssivo: O menor conteudo eh: %d\n", p->conteudo);

    return 0;
}