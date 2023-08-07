
/*#include <stdio.h>
#include <string.h>
#include <stdlib.h>
*/
#include "funcoes.h"

int main(void){
    FILE *arte;
    int i, turnos=0;    

    /*inicializa os jogadores e as linhas de seus tabuleiros respectivos*/
    jogador j1, j2;
    j1.tabuleiro = (unsigned char **)malloc(LIN*sizeof(unsigned char *));
    j2.tabuleiro = (unsigned char **)malloc(LIN*sizeof(unsigned char *));

    strcpy(j1.nome, NOM_JOG1);
    strcpy(j2.nome, NOM_JOG2);
    
    if(j1.tabuleiro==NULL || j2.tabuleiro==NULL){
        printf("Nao consegui alocar memoria 1\n");
        exit(1);
    }

    /*inicializa as colunas do tabuleiro de j1*/
    for(i=0;i<LIN;i++){
        *(j1.tabuleiro+i)= (unsigned char *)malloc(COL*sizeof(unsigned char));
        if((*(j1.tabuleiro+i)==NULL)){
            printf("Nao consegui alocar memoria 2\n");
            exit(1);
        }
    }

    /*inicializa os navio de j1*/
    j1.navios=(navio *)malloc(NAVIOS*sizeof(navio));

    strcpy((j1.navios)->nome, NOM_NAV1);
    (j1.navios)->size=TAM_NAV1;
    strcpy((j1.navios+1)->nome, NOM_NAV2);
    (j1.navios+1)->size=TAM_NAV2;
    strcpy((j1.navios+2)->nome, NOM_NAV3);
    (j1.navios+2)->size=TAM_NAV3;
    strcpy((j1.navios+3)->nome, NOM_NAV4);
    (j1.navios+3)->size=TAM_NAV4;

    for(i=0;i<NAVIOS;i++){
        (j1.navios+i)->pri_posicao=NULL;
        /*printf("%s\n", (j1.navios+i)->nome);*/
    }
    

    /*inicializa as colunas do tabuleiro de j2*/
    for(i=0;i<LIN;i++){
        *(j2.tabuleiro+i)= (unsigned char *)malloc(COL*sizeof(unsigned char));
        if((*(j2.tabuleiro+i)==NULL)){
            printf("Nao consegui alocar memoria 3\n");
            exit(1);
        }
    }

    /*inicializa os navio de j2*/
    j2.navios=(navio *)malloc(NAVIOS*sizeof(navio));

    strcpy((j2.navios)->nome, NOM_NAV1);
    (j2.navios)->size=TAM_NAV1;
    strcpy((j2.navios+1)->nome, NOM_NAV2);
    (j2.navios+1)->size=TAM_NAV2;
    strcpy((j2.navios+2)->nome, NOM_NAV3);
    (j2.navios+2)->size=TAM_NAV3;
    strcpy((j2.navios+3)->nome, NOM_NAV4);
    (j2.navios+3)->size=TAM_NAV4;

    for(i=0;i<NAVIOS;i++){
        (j2.navios+i)->pri_posicao=NULL;
        /*printf("%s\n", (j2.navios+i)->nome);*/
    }
    
    /*limpa a tela*/
    system("cls");

    /*preenche os tabuleiros com o caractere inicial, agua*/
    preenche_tabuleiro(j1.tabuleiro);
    preenche_tabuleiro(j2.tabuleiro);

    
    /*coloca os navios do jogador j1 no tabuleiro dele*/
    coloca_navios(j1, j2);

    /*faz a transicao entre jogadores*/
    transicao(j1);

    /*coloca os navios do jogador j2 no tabuleiro dele*/
    coloca_navios(j2, j1);

    /* Zuben: Teste para afundar submarino */
    /*
    ataque(j1);
    ataque(j1);
    */
    
    transicao(j2);
    
    /*print_tabuleiro(j1, j2);*/
    
    for(turnos=0;;turnos++){
        fflush(stdin);
        
        turnos%2==0?print_tabuleiro(j1, j2):print_tabuleiro(j2, j1);
        turnos%2==0?ataque(j2, j1):ataque(j1, j2);
        
        i=(turnos%2==0?checa_derrota(j2):checa_derrota(j1));
        if(i==1){
            break;
        }
        fflush(stdin);
        
        turnos%2==0?transicao(j1):transicao(j2);
    }

    if(turnos%2==0){
        arte = fopen("vitoriaj1.txt", "r");
    }else{
        arte = fopen("vitoriaj2.txt", "r");
    }
    if(arte==NULL){
        printf("erro");
        exit(1);
    }

    fflush(stdin);
    printf("Aperte ENTER para continuar\n");
    getc(stdin);
    fflush(stdin);
    system("cls");

    while(!feof(arte)){
        i = fgetc(arte);
        /*putc(letra, stdin);*/
        /*fputc(letra, stdin);*/
        printf("%c", i);
    }
    printf("\n");

    fflush(stdin);
    printf("Aperte ENTER para fechar o jogo\n");
    getc(stdin);
    fflush(stdin);
    system("cls");

    return 0;
}

