#include <stdio.h>
#include <stdlib.h>

#define TAM 5

typedef struct _CELULA {
    int conteudo;
    struct _CELULA *prox;
} CELULA;

int igual_iterativo(CELULA *p, CELULA *p_2) {
    while (p != NULL){
        if (p->conteudo != p_2->conteudo)
            return 1;
        p = p->prox;
        p_2 = p_2->prox;
    }
    return 0;
}

int igual_recurssivo(CELULA *p, CELULA *p_2) {

    if (p->conteudo != p_2->conteudo)
        return 1;
    if (p->prox != NULL)
        return igual_recurssivo(p->prox, p_2->prox);
    return 0;
}

int main(){
    int i, x;
    CELULA *le, *p, *temp, *le_2, *p_2, *temp_2;

    for (i = 0; i < TAM; i++){
        p = (CELULA *) malloc(sizeof(CELULA));
        if (!p){
            printf("Sem memoria!");
            return 1;
        }
        printf("Entre o valor da lista 1 posicao [%d]: ", (i+1));
        scanf("%d", &(p->conteudo));

        p->prox = NULL;

        if (i == 0){
            le = p;
        } else{
            temp->prox = p;
        }

        temp = p;
    }

    for (i = 0; i < TAM; i++){
        p_2 = (CELULA *) malloc(sizeof(CELULA));
        if (!p_2){
            printf("Sem memoria!");
            return 1;
        }
        printf("Entre o valor da lista 2 posicao [%d]: ", (i+1));
        scanf("%d", &(p_2->conteudo));

        p_2->prox = NULL;

        if (i == 0){
            le_2 = p_2;
        } else{
            temp_2->prox = p_2;
        }

        temp_2 = p_2;
    }

    x = igual_iterativo(le, le_2);
    if (x == 1) printf("Iterativo: Sao diferentes\n");
    else printf("Iterativo: Sao iguais\n");

    x = igual_recurssivo(le, le_2);
    if (x == 1) printf("Recurssivo: Sao diferentes\n");
    else printf("Recurssivo: Sao iguais\n");

    return 0;
}