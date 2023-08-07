#include "funcoes.h"
/*#include <conio.h>*/


void preenche_tabuleiro(unsigned char **tabuleiro){
    int i, j;

    /*printf("preenchendo agora");*/
    for(i=0;i<LIN;i++){
        for(j=0;j<COL-1;j++){
            *(*(tabuleiro+i)+j)=176;
            /*printf("x");*/
        }
        /*printf("b\n");*/
    }
    /*printf("preenchido com sucesso");*/
}
/*void print_tabuleiro(unsigned char **tabuleiro)*/


/*PRINTA O TABULEIRO DO JOGADOR (j) EMBAIXO E DO INIMIGO(j_outro) EMCIMA*/
void print_tabuleiro(jogador j, jogador j_outro){
    int i, x;
    char linha='A';
    /*printf("printando agora");*/
    printf("%s 1 2 3 4 5 6 7 8 9 10\n", j_outro.nome);
    for(i=0;i<LIN;i++){
        printf(" %c ", linha+i);
        for(x=0;x<COL-1;x++){
            /*SUBSTITUI POR AGUA O SIMBOLO DO NAVIO INIMIGO, E PRINTA O RESTO NORMAL*/
            if(*(*(j_outro.tabuleiro+i)+x)==CHAR_NAVIO){
                printf("%c%c", CHAR_AGUA, CHAR_AGUA);
            }else{
                printf("%c%c", *(*(j_outro.tabuleiro+i)+x), *(*(j_outro.tabuleiro+i)+x));
            }
        }
        printf("\n");
    }
    /*printf("printado com sucesso");*/
    printf("\n   --------------------\n\n");
    
    linha='A';
    /*printf("printando agora");*/
    printf("%s 1 2 3 4 5 6 7 8 9 10\n", j.nome);
    for(i=0;i<LIN;i++){
        printf(" %c ", linha+i);
        for(x=0;x<COL-1;x++){
            printf("%c%c", *(*(j.tabuleiro+i)+x), *(*(j.tabuleiro+i)+x));
        }
        printf("\n");
    }
}
/*
void print_tabuleiros(jogador j, jogador j_outro){
    print_tabuleiro(j_outro);
    printf("\n------------------------------------------\n\n");
    print_tabuleiro(j);
}
*/


/*LE ONDE O JOGADOR QUER COLOCAR OS NAVIOS
VALIDA OS COMANDOS
COLOCA OS NAVIAS DO JOGADOR(j) NO TABULEIRO DELE*/
void coloca_navios(jogador j, jogador j_outro){
    char lin1, lin2;
    int col1, col2, i; 
    system("cls");
    print_tabuleiro(j, j_outro);
    printf("Modelo de posicao (ex: C1 C5)\n");

    for(i=0;i<NAVIOS;i++){
        fflush(stdin);
        printf("Escolha a posicao do seu %s(%d posicoes): ", (j.navios+i)->nome, (j.navios+i)->size);
        scanf(" %c%d", &lin1, &col1);
        scanf(" %c%d", &lin2, &col2);

        fflush(stdin);

        while(!checa_validade_navio(j, i, lin1, col1, lin2, col2)){
            
            fflush(stdin);
            /*clrscr();*/
            system("cls");

            print_tabuleiro(j, j_outro);
            
            printf("Posicao invalida\n");
            printf("Modelo de posicao (ex: C1 C5)\n");

            printf("Escolha a posicao do seu %s: ", (j.navios+i)->nome);
            scanf(" %c%d", &lin1, &col1);
            scanf(" %c%d", &lin2, &col2);
        }
        printf("posicao valida\n");

        system("cls");

        coloca_navio(j, i, lin1, col1, lin2, col2);
        print_tabuleiro(j, j_outro);
        /*printf("a");*/
        /*exit(1);*/
    }
}

/*TRANSICIONA ENTRE A COLOCACAO DOS NAVIOS DE UM JOGADOR E DE OUTRO*/
void transicao(jogador j_saida){
    FILE *arte;
    char letra;

    fflush(stdin);
    printf("Aperte ENTER para trocar de jogador");
    getc(stdin);
    
    fflush(stdin);
    system("cls");
    /*j_saida.nome==NOM_JOG1*/
    arte=NULL;
    if(!strcmp(j_saida.nome, NOM_JOG1)){
        arte = fopen("j1paraj2.txt", "r");
    }else{
        arte = fopen("j2paraj1.txt", "r");
    }
    if(arte==NULL){
        printf("erro");
        exit(1);
    }
    
    while(!feof(arte)){
        letra = fgetc(arte);
        /*putc(letra, stdin);*/
        /*fputc(letra, stdin);*/
        printf("%c", letra);
    }
    fclose(arte);
    printf("Aperte ENTER para trocar de jogador");
    
    getc(stdin);
    fflush(stdin);
    system("cls");
    return;
}

/*COLOCA OS NAVIAS DO JOGADOR(j) NO TABULEIRO DELE*/

/* Zuben: precisei adicionar os atributos linha coluna e direção para facilitar a verificação do tiro, verefique seu código "coloca_navio" */
void coloca_navio(jogador j, int navio, char lin1, int col1, char lin2, int col2){
    int i;
    /*define a pri_posicao do navio*/
    (j.navios+navio)->pri_posicao=(*(j.tabuleiro+lin1-DIF_CH_INT))+col1-1;
    (j.navios+navio)->lin=lin1-DIF_CH_INT;
    (j.navios+navio)->col=col1-1;

    /*preenche o tabuleiro e define a ult_posicao do navio*/
    if(lin1==lin2){
        (j.navios+navio)->direction = 0;
        for(i=0;i<(j.navios+navio)->size;i++){
            *(*(j.tabuleiro+lin1-DIF_CH_INT)+col1-1+i)=CHAR_NAVIO;
        }
        (j.navios+navio)->ult_posicao=(*(j.tabuleiro+lin1-DIF_CH_INT))+col1-1+i;

    } else{
        (j.navios+navio)->direction = 1;
        for(i=0;i<(j.navios+navio)->size;i++){
            *(*(j.tabuleiro+lin1-DIF_CH_INT+i)+col1-1)=CHAR_NAVIO;
        }
        (j.navios+navio)->ult_posicao=(*(j.tabuleiro+lin1-DIF_CH_INT))+col1-1+i;
    }
    
}

/*VALIDA AS POSICOES ESCOLHIDAS PELO JOGADOR PARA ONDE COLOCAR O NAVIO DELE*/
int checa_validade_navio(jogador j, int navio, char lin1, int col1, char lin2, int col2){
    int i;

    if(lin1<'A'||lin1>('A'+LIN-1)||lin2<'A'||lin2>('A'+LIN-1)||col1<1||col1>(COL-1)||col2<1||col2>(COL-1)) return 0;

    /*printf("%c%d - %c%d\n", lin1, col1, lin2, col2);*/
    /*verifica mesma linha*/
    if(lin1==lin2 && (col2-col1)==(j.navios+navio)->size-1){
        for(i=0;i<(j.navios+navio)->size;i++){
            /*printf("a");*/
            if(*(*(j.tabuleiro+lin1-DIF_CH_INT)+col1-1+i)==CHAR_NAVIO){
                /*printf("1\n");*/
                return 0;
            }
            
        }
        return 1;
        /*verifica mesma coluna*/
    }else if(col1==col2 && (lin2-lin1)==(j.navios+navio)->size-1){
        for(i=0;i<(j.navios+navio)->size;i++){
            if(*(*(j.tabuleiro+lin1-DIF_CH_INT+i)+col1-1)==CHAR_NAVIO){
                /*printf("2\n");*/
                return 0;
            }
        }
        return 1;
    }else{
        /*printf("3\n");*/
        return 0;
    }
}

int verifica_area_tiro (jogador j, jogador j_outro, int lin, int col) {
    int navio, achei_navio = 0, i;
    unsigned char *posicao_tiro, valor;


    /* Chegou aqui sabe-se que acertou uma posição, agora varre os navios para descobrir qual ele acertou */
    for (navio = 0; navio < NAVIOS && achei_navio == 0; navio++){
        /*pega a posição da memória do tiro transformando a linha e coluna em endereço de memória do tabuleiro*/
        posicao_tiro = (* ( j.tabuleiro + lin ) ) + col;
        
        /* compara a posicao_tiro com todas as posições do navio */

        /* Para horizontal: */
        if((j.navios+navio)->direction == 0){
            for(i=0;i<(j.navios+navio)->size;i++){
                /*representaçãoda posicao de memória: &j.tabuleiro [linha][coluna+i] */
                if (*(j.tabuleiro + (j.navios+navio)->lin) + (j.navios+navio)->col+i == posicao_tiro){
                    achei_navio = 1;
                    break;
                }
            }

        /* Para vertical: */
        } else{
            for(i=0;i<(j.navios+navio)->size;i++){
                /*representaçãoda posicao de memória: &j.tabuleiro [linha+i][coluna] */
                if (*(j.tabuleiro + (j.navios+navio)->lin + i) + (j.navios+navio)->col == posicao_tiro){
                    achei_navio = 1;
                    break;
                }
            }
        }
    }

    /* Uma vez descoberto o navio, verifica-se se foi totalmente abatido */
    /* A presença de um CHAR_NAVIO identifica que o navio não foi afundado totalmente */
    if (achei_navio == 1){
        navio--;
        if((j.navios+navio)->direction == 0){
            for(i=0;i<(j.navios+navio)->size;i++){
                /* Obtem o valor apontado pelo endereço do tabuleiro */
                valor = *(*(j.tabuleiro + (j.navios+navio)->lin) + (j.navios+navio)->col+i);
                if (valor == CHAR_NAVIO){
                    return 1;                    
                }
            }
        } else{
            for(i=0;i<(j.navios+navio)->size;i++){
                valor = *(*(j.tabuleiro + (j.navios+navio)->lin + i) + (j.navios+navio)->col);
                if (valor == CHAR_NAVIO){
                    return 1;
                }
            }
        }
    }
    
    (j.navios+navio)->pri_posicao=NULL;
    system("cls");
    print_tabuleiro(j_outro,j);
    printf("BOMBA!\n");
    printf ("Afundou %s!\n", (j.navios+navio)->nome);
    return 0;
}

int avalia_ataque(jogador j, jogador j_outro, int lin, int col){

    unsigned char *posicao = *(j.tabuleiro+lin)+col;

    if (*posicao == CHAR_NAVIO) {        
        *posicao = CHAR_ACERTO_NAVIO;
        system("cls");
        print_tabuleiro(j_outro,j);
        printf("BOMBA!\n");

    } else if ( *posicao == CHAR_ACERTO_NAVIO ) {
        /*printf("Posicao ja atacada!\n");*/
        return 1;
    } else {
        *posicao = CHAR_ACERTO_AGUA;
        system("cls");
        print_tabuleiro(j_outro,j);
        printf("Agua!\n");   
        return 0;     
    }

   if ( verifica_area_tiro (j, j_outro, lin, col) == 0 ) {
       /*
        system("cls");
        print_tabuleiro(j_outro,j);
        printf("BOMBA!\n");
        printf ("Afundou!\n");
        */
    }

    return 0;
}

void ataque(jogador j, jogador j_outro){
    char lin;
    int col, fim_ataque=0;
    
    do {
        /*print_tabuleiro(j_outro, j);*/
        fflush(stdin);
        printf("Escolha a coordenada do seu ataque: ");
        scanf(" %c%d", &lin, &col);
        
        if ((lin < 'A' ||lin>'A'+LIN-1) || (col < 1 || col>COL-1)){
            system("cls");
            print_tabuleiro(j_outro, j);
            printf ("Coordenadas invalidas!\n");
        }

        else {
            /*print_tabuleiro(j_outro, j);*/
            if (avalia_ataque(j, j_outro, lin-DIF_CH_INT, col-1) == 0) 
               fim_ataque = 1;
            else{
                system("cls");
                print_tabuleiro(j_outro, j);
                printf("Posicao ja atacada!\n");
            }
        }

    } while (fim_ataque == 0);
}

int checa_derrota(jogador j_atingido){
    int i;
    for(i=0;i<NAVIOS;i++){
        if((j_atingido.navios+i)->pri_posicao!=NULL){
            return 0;
        }
    }
    return 1;
}