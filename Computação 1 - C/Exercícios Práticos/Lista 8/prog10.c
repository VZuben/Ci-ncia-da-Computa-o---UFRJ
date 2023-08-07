#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 5
#define TAMNOME 81

typedef struct _JOGADOR {
    int pontos;
    char nome[42];
} JOGADOR;

int main (){
    JOGADOR *p;
    int i;

    p = (JOGADOR *) malloc(TAM * sizeof(JOGADOR));
    if (!p){
        printf("Sem memoria!");
        return 1;
    }

    for (i = 0; i < TAM; i++){
        printf("Digite o nome do jogador [%d]: ", i+1);
        fgets((p+i)->nome, TAMNOME, stdin);
        *((p+i)->nome+(strlen((p+i)->nome)-1)) = 0;
        printf("Digite os pontos do jogador [%d]: ", i+1);
        scanf("%d", &((p+i)->pontos)); getchar();
    }

    for (i = 0; i < TAM; i++){
        printf("\nJogador[%d] = %s\n", i+1, (p+i)->nome);
        printf("Pontos = %d\n", (p+i)->pontos);
    }
    printf("\n");

    free(p);

    return 0;
}