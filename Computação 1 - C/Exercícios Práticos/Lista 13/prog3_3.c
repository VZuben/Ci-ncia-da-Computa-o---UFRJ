#include <stdio.h>
#include <stdlib.h>

#define TAM 5

typedef struct _CELULA {
    int conteudo;
    struct _CELULA *prox;
} CELULA;

int crescente (CELULA *le) {
    CELULA *p = le;
    while (p->prox != NULL){
        if ((p->conteudo) < (p->prox->conteudo))
            p = p->prox;
        else return 0;
    }
    return 1;
}

int main(){
    int i, x;
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

    x = crescente(le);

    if (x == 0)
        printf("Nao eh crescente");
    else
        printf("Eh crescente");  

    return 0;
}