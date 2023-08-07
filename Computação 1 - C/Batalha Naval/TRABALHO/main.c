/* 
    Programa: Trabalho Final de Computação I - Batalha Naval

    Nome: Michel Monteiro Schorr              - DRE: 120017379
    Nome: Pedro Henrique Figueiredo Von Zuben - DRE: 119055699
    Nome: Pedro Alberton Buttel da Veiga      - DRE: 119143125

    OBS: PRECISA SER RODADO NO WINDOWS!!!

    Descrição: 

        O programa Batalha Naval é um jogo feito para duas pessoas, criado utilizando ponteiros, structs e é rodado pelo terminal. Ele tem as seguintes regras:

            1- Cada jogador entra com 4 navios (Porta-Aviões com 5 peças, encouraçado com 4 peças, cruzador com 3 peças e submarino com 2 peças);
            2- Os navios não podem estar sobrepostos, no entanto podem estar "grudados";
            3- O ataque é realizado dando as coordenadas do mapa (uma matriz 10x10), exemplo: C1;
            4- O jogo termina quando todos os navios de algum jogador afunda, o jogador que realizar tal feito é o vencedor.
    
*/

#include "funcoes.h"

int main(void){
    FILE *arte;
    int i, turnos=0;    

    /* Inicializa os jogadores e as linhas de seus tabuleiros respectivos */
    jogador j1, j2;
    system("color 07");
    j1.tabuleiro = (unsigned char **)malloc(LIN*sizeof(unsigned char *));
    j2.tabuleiro = (unsigned char **)malloc(LIN*sizeof(unsigned char *));

    strcpy(j1.nome, NOM_JOG1);
    strcpy(j2.nome, NOM_JOG2);
    

    /* Teste para falta de memória */
    if(j1.tabuleiro==NULL || j2.tabuleiro==NULL){
        printf("Nao consegui alocar memoria 1\n");
        exit(1);
    }

    /* Inicializa as colunas do tabuleiro de j1 */
    for(i=0;i<LIN;i++){
        *(j1.tabuleiro+i)= (unsigned char *)malloc(COL*sizeof(unsigned char));
        if((*(j1.tabuleiro+i)==NULL)){
            printf("Nao consegui alocar memoria 2\n");
            exit(1);
        }
    }

    /* Inicializa os navio de j1 */
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
    }
    

    /* Inicializa as colunas do tabuleiro de j2 */
    for(i=0;i<LIN;i++){
        *(j2.tabuleiro+i)= (unsigned char *)malloc(COL*sizeof(unsigned char));
        if((*(j2.tabuleiro+i)==NULL)){
            printf("Nao consegui alocar memoria 3\n");
            exit(1);
        }
    }

    /* Inicializa os navio de j2 */
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
    }
    
    /* Limpa a tela */
    system("cls");

/* tela inicial */
    fflush(stdin);
    printf(" /$$$$$$$              /$$               /$$ /$$                \n");
    printf("| $$__  $$            | $$              | $$| $$                \n");
    printf("| $$  | $$  /$$$$$$  /$$$$$$    /$$$$$$ | $$| $$$$$$$   /$$$$$$ \n");
    printf("| $$$$$$$  |____  $$|_  $$_/   |____  $$| $$| $$__  $$ |____  $$\n");
    printf("| $$__  $$  /$$$$$$$  | $$      /$$$$$$$| $$| $$  | $$  /$$$$$$$\n");
    printf("| $$  | $$ /$$__  $$  | $$ /$$ /$$__  $$| $$| $$  | $$ /$$__  $$\n");
    printf("| $$$$$$$/|  $$$$$$$  |  $$$$/|  $$$$$$$| $$| $$  | $$|  $$$$$$$\n");
    printf("|_______/  |_______/   |___/   |_______/|__/|__/  |__/ |_______/\n");
    printf("                                                                \n");
    printf("                                                                \n");
    printf("                                                                \n");
    printf("       /$$   /$$                               /$$              \n");
    printf("      | $$$ | $$                              | $$              \n");
    printf("      | $$$$| $$  /$$$$$$  /$$    /$$ /$$$$$$ | $$              \n");
    printf("      | $$ $$ $$ |____  $$|  $$  /$$/|____  $$| $$              \n");
    printf("      | $$  $$$$  /$$$$$$$ |  $$/$$/  /$$$$$$$| $$              \n");
    printf("      | $$|  $$$ /$$__  $$  |  $$$/  /$$__  $$| $$              \n");
    printf("      | $$ |  $$|  $$$$$$$   |  $/  |  $$$$$$$| $$              \n");
    printf("      |__/  |__/ |_______/    |_/    |_______/|__/              \n");
    
    for (i = 0; i < 3; i++)
    {
        printf("\n");
    }
    printf("0- Seu tabuleiro fica embaixo e o de seu oponente em cima;\n");
    printf("1- Cada jogador entra com 4 navios (Porta-Avioes com 5 pecas, encouracado com 4 pecas, cruzador com 3 pecas e submarino com 2 pecas);\n");
    printf("2- Os navios nao podem estar sobrepostos, no entanto podem estar \"grudados\";\n");
    printf("3- O ataque eh realizado dando as coordenadas do mapa (uma matriz 10x10), exemplo: C1;\n");
    printf("4- O jogo termina quando todos os navios de algum jogador afunda, o jogador que realizar tal feito eh o vencedor;\n");
    printf("\n");        
    printf("5- JOGUE >>> APENAS <<< COM LETRAS EM >>> CAIXA ALTA <<<!!!\n");

    for (i = 0; i < 3; i++)
    {
        printf("\n");
    }

    printf("JOGADOR 1 => VERDE\n");
    printf("JOGADOR 2 => VERMELHO\n");

    printf("\n");

    printf("APERTE >>> ENTER <<< PARA COMECAR O JOGO!\n");
    


    getc(stdin);
    
    /* Prepara a tela pro jogador 1 */
    system("color 02");

    /* Preenche os tabuleiros com o caractere inicial, agua */
    preenche_tabuleiro(j1.tabuleiro);
    preenche_tabuleiro(j2.tabuleiro);

    
    /* Coloca os navios do jogador j1 no tabuleiro dele */
    coloca_navios(j1, j2);

    /* Faz a transicao entre jogadores */
    transicao(j1);

    /* Coloca os navios do jogador j2 no tabuleiro dele */
    coloca_navios(j2, j1);
    
    /* Faz a transicao entre jogadores */
    transicao(j2);
    
    /* Loop principal do Jogo */
    for(turnos=0;;turnos++){
        fflush(stdin);
        
        turnos%2==0?print_tabuleiro(j1, j2):print_tabuleiro(j2, j1);
        turnos%2==0?ataque(j2, j1):ataque(j1, j2);
        
        /* Verifica o vencedor */
        i=(turnos%2==0?checa_derrota(j2):checa_derrota(j1));
        if(i==1){
            break;
        }
        fflush(stdin);
        
        turnos%2==0?transicao(j1):transicao(j2);
    }

    /* Dependendo de quem for o vencedor, arte recebe o troféu correspondente */
    if(turnos%2==0){
        arte = fopen("vitoriaj1.txt", "r");
    }else{
        arte = fopen("vitoriaj2.txt", "r");
    }

    /* Erro se o arquivo não existir */
    if(arte==NULL){
        printf("erro");
        exit(1);
    }

    fflush(stdin);
    printf("Aperte ENTER para continuar\n");
    getc(stdin);
    fflush(stdin);
    system("cls");

    /* Simples impressão de um troféu para o vencedor */
    system("color 06");
    while(!feof(arte)){
        i = fgetc(arte);
        printf("%c", i);
    }
    printf("\n");

    /* Aguarda ENTER para finalizar o jogo */
    fflush(stdin);
    printf("Aperte ENTER para fechar o jogo\n");
    getc(stdin);
    fflush(stdin);
    system("cls");

    return 0;
}

