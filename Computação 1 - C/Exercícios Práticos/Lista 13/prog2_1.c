#include <stdio.h>
#include <stdlib.h>

#define TAM 10

typedef struct _CELULA {
    int conteudo;
    struct _CELULA *prox;
} CELULA;

int conta_interativo (CELULA *p) {
    int contador=0;
    for (; p != NULL; p = p->prox)
        contador++;
    
    return contador;
}

int conta_recurssivo (CELULA *p) {
    static int contador=0;
    if (p != NULL) {
        contador++;
        conta_recurssivo (p->prox);
   }
   return contador;
}

int main(){
    int i;
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

    printf("\n");
    printf("Contador Interativo: %d", conta_interativo(primeiro));
    printf("\n");
    printf("Contador Recurssivo: %d", conta_recurssivo(primeiro));
    printf("\n\n");

    return 0;
}