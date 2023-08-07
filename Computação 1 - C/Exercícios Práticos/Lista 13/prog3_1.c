#include <stdio.h>
#include <stdlib.h>

#define TAM 5

typedef struct _CELULA {
    int conteudo;
    struct _CELULA *prox;
} CELULA;

CELULA *busca (int x, CELULA *le) {
   CELULA *p = le;
   while (p != NULL) {
      if (p->conteudo == x) {
          return p;
      }
      p = p->prox; 
    }
    return NULL;
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

    printf("Digite o inteiro X a ser buscado: ");
    scanf("%d", &x);

    p = busca(x, le);

    if (p == NULL)
        printf("Nao achei\n");
        else
            printf("Achei, %d\n", p->conteudo);
        
    return 0;
}