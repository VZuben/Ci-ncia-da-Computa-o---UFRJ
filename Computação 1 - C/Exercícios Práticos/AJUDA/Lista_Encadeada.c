#include <stdio.h>
#include <stdlib.h>

#define TAM 10

typedef struct _CELULA {
    int conteudo;
    struct _CELULA *prox;
} CELULA;

void insere (int x, CELULA *p){
   CELULA *nova;

   nova = malloc (sizeof (CELULA));
   nova->conteudo = x;
   nova->prox = p->prox;
   p->prox = nova;
}

void imprima (CELULA *le) {
   CELULA *p;
   for (p = le->prox; p != NULL; p = p->prox)
      printf ("%d\n", p->conteudo);
}

int main(){
    int i, x;
    CELULA *primeiro;

   primeiro = malloc (sizeof (CELULA));
   primeiro->prox = NULL;

    for (i = 0; i < TAM; i++){
        printf("Entre o valor da posicao [%d]: ", (i+1));
        scanf("%d", &x);
        insere (x, primeiro);
    }

    imprima(primeiro);

    return 0;
}