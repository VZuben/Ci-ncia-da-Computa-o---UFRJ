#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 5
#define TAMNOME 81

typedef struct _JOGADOR {
    int pontos;
    char nome[42];
} JOGADOR;

void bubble_sort(JOGADOR *p, int tamanho){
    JOGADOR temp;
    int i, trocou;
    do {
        trocou = 0;
        for (i = 0; i < tamanho - 1; i++){
            if (((p + i)->pontos) < ((p + i + 1)->pontos)){
                temp = *(p + i);
                *(p + i) = *(p + i + 1);
                *(p + i + 1) = temp;
                trocou = 1;
            }
        }
        tamanho--;
    } while (trocou == 1);

}

void imprime(JOGADOR *p, int tamanho){
    int i;
    for (i = 0; i < tamanho; i++){
        printf("\nJogador[%d] = %s\n", i+1, (p+i)->nome);
        printf("Pontos = %d\n", (p+i)->pontos);
    }
    printf("\n");
}

void le_jogador(JOGADOR *p, int i){
        printf("Digite o nome do jogador [%d]: ", i+1);
        fgets((p+i)->nome, TAMNOME, stdin);
        *((p+i)->nome+(strlen((p+i)->nome)-1)) = 0;
        printf("Digite os pontos do jogador [%d]: ", i+1);
        scanf("%d", &((p+i)->pontos)); getchar();
}

int main (){
    JOGADOR *p;
    int i;

    p = (JOGADOR *) malloc(TAM * sizeof(JOGADOR));
    if (!p){
        printf("Sem memoria!");
        return 1;
    }

    for (i = 0; i < TAM; i++){
        le_jogador(p, i);
    }

    bubble_sort(p, TAM);
    imprime(p, TAM);

    p = (JOGADOR *) realloc(p, (TAM + 1) * sizeof(JOGADOR));
    if (!p){
        printf("Sem memoria!");
        return 1;
    }

    le_jogador(p, TAM);
    bubble_sort(p, TAM + 1);

    p = (JOGADOR *) realloc(p, (TAM) * sizeof(JOGADOR));
    if (!p){
        printf("Sem memoria!");
        return 1;
    }

    imprime(p, TAM);

    free(p);

    return 0;
}