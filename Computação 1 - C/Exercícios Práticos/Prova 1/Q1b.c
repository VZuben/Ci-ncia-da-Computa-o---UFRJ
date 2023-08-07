#include <stdio.h>

/*Pedro Henrique Figueiredo Von Zuben 119055699*/

#define TAM_MATRIZ 10

int main(){
    
    int i=0,j=0,flag_bomba=0;
    int tabuleiro[TAM_MATRIZ][TAM_MATRIZ];


    for (i=0; i<TAM_MATRIZ; i++) {
        for (j=0; i<TAM_MATRIZ; j++) {
            tabuleiro[i][j] = 0;
        }
    }
    tabuleiro[1][5] = 1;
    tabuleiro[2][5] = 1;
    tabuleiro[3][5] = 1;
    tabuleiro[4][6] = 1;
    tabuleiro[5][5] = 1;
    tabuleiro[6][2] = 1;
    tabuleiro[7][4] = 1;
    tabuleiro[8][2] = 1;
    tabuleiro[9][1] = 1;
    tabuleiro[1][1] = 1;

    while (1){

        scanf("%d %d", &i, &j);
           
         if (tabuleiro[i][j] == 1) {
             printf("Bomba!");
             break;
         }
    }
    
    return 0;
}