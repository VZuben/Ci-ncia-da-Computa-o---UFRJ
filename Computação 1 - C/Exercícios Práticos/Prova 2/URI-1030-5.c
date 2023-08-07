/*  Nome: Pedro Henrique Figueiredo Von Zuben
     DRE: 119055699 
PROGRAMA: URI - 1030 (Lista encadeada) */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _LISTA {
    int conteudo;
    struct _LISTA *prox;
} LISTA;


/* A função buscar procura o conteúdo X dentro da lista encadeada e retorna o ponteiro para posição anterior a ele. */
LISTA *buscar (int x, LISTA *primeiro) {
   LISTA *p = primeiro->prox, *anterior;

    anterior = primeiro;
    while (p != NULL) {
        if (p->conteudo == x) {
            return anterior;
        }
        anterior = p;
        p = p->prox; 
    }
    return NULL;
}

/* A função iserir adiciona um elemento no modelo de cabeça de lista. */
LISTA * inserir (int x, LISTA *p){
    LISTA *nova;
    nova = (LISTA *) malloc (sizeof (LISTA));
    nova->conteudo = x;
    nova->prox = p->prox;
    p->prox = nova;
    return nova;
}

/* A função remover remove o elemento seguinte ao ponteiro anterior recebido no parâmetro. */
void remover (LISTA *anterior) {
   LISTA *lixo;

   lixo = anterior->prox;
   anterior->prox = lixo->prox;
   free (lixo);
}

/* A função imprimir imprime a lista encadeada pulando a cabeça de lista */
void imprimir (LISTA *primeiro) {
    LISTA *p;

    if (primeiro->prox != NULL){
        for (p = primeiro->prox; p != NULL; p = p->prox)
            printf ("%d ", p->conteudo);
        printf("\n");
    }
}

int main(){
    int contador, x, y;
    char comando;
    LISTA *primeiro, *final, *elemento, *p;

    primeiro = (LISTA *) malloc (sizeof (LISTA));
    primeiro->prox = NULL;
    final = primeiro;

    contador = 0;
    while (1) {                                                 /*loop infinito para criar a lista encadeada*/
        scanf("%d", &x);
        if (x < 0) break;                                      /*condição de parada*/
        inserir (x, primeiro);                                
        contador++;
        if (contador == 1) final = primeiro->prox;           /*guardando o ponteiro para o final da lista*/
    }
    fflush(stdin);
    while (1) {                                               /*loop infinito usado para receber os comandos*/
        scanf("%c", &comando);
        if (comando == 'X') break;                            /*condição de parada*/
        if (comando == 'I'){
            scanf("%d", &x);
            scanf("%d", &y);
            elemento = buscar(x, primeiro);
            if (elemento != NULL){
                inserir (y, elemento);
            } else {
                final = inserir (y, final);
            }
        }
        if (comando == 'R'){
            scanf("%d", &x);
            elemento = buscar (x, primeiro);
            if (elemento != NULL){
                if (elemento->prox == final){
                    final = elemento;
                }
                remover (elemento);
            }
        }
    }

    imprimir (primeiro);

    do {
        p = primeiro->prox; /*Limpa a memória a partir da Cabeça da Fila */
        free(primeiro);
        primeiro = p;
    } while (p != NULL);

    return 0;
}