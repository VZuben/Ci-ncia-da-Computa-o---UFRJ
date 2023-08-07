/* Implementação das funções necessárias para o programa Batalha Naval */

#include "funcoes.h"

/* Carrega o tabuleiro com todas as posicoes com CHAR_AGUA */
void preenche_tabuleiro(unsigned char **tabuleiro){
    int i, j;

    for(i=0;i<LIN;i++){
        for(j=0;j<COL-1;j++){
            *(*(tabuleiro+i)+j)=CHAR_AGUA;
        }
    }
}


/* Imprime o tabuleiro do jogador (j) embaixo e do inimigo(j_outro) em cima */
void print_tabuleiro(jogador j, jogador j_outro){
    int i, x;
    char linha='A';
    printf("%s 1 2 3 4 5 6 7 8 9 10\n", j_outro.nome);
    for(i=0;i<LIN;i++){
        printf(" %c ", linha+i);
        for(x=0;x<COL-1;x++){
            /* Substitui por agua o simbolo do navio inimigo, e imprime o resto normal */
            if(*(*(j_outro.tabuleiro+i)+x)==CHAR_NAVIO){
                printf("%c%c", CHAR_AGUA, CHAR_AGUA);
            }else{
                printf("%c%c", *(*(j_outro.tabuleiro+i)+x), *(*(j_outro.tabuleiro+i)+x));
            }
        }
        printf("\n");
    }
    printf("\n   --------------------\n\n");
    linha='A';
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
    Le onde o jogador quer colocar os navios
    valida os comandos
    coloca os navios do jogador(j) no tabuleiro dele 
*/
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
    }
}

/* Transiciona entre a colocação dos navios de um jogador e de outro */
void transicao(jogador j_saida){
    FILE *arte;
    char letra;

    fflush(stdin);
    printf("Aperte ENTER para trocar de jogador");
    getc(stdin);
    
    fflush(stdin);
    system("cls");
    arte=NULL;
    if(!strcmp(j_saida.nome, NOM_JOG1)){
        arte = fopen("j1paraj2.txt", "r");
        system("color 04");
    }else{
        arte = fopen("j2paraj1.txt", "r");
        system("color 02");
    }
    if(arte==NULL){
        printf("erro");
        exit(1);
    }
    
    while(!feof(arte)){
        letra = fgetc(arte);
        printf("%c", letra);
    }
    fclose(arte);
    printf("\n");
    printf("\n");
    printf("Aperte ENTER para trocar de jogador");
    
    getc(stdin);
    fflush(stdin);
    system("cls");
    return;
}

/* Coloca os navios do jogador(j) no tabuleiro dele */
void coloca_navio(jogador j, int navio, char lin1, int col1, char lin2, int col2){
    int i;
    /* Define a pri_posicao do navio */
    (j.navios+navio)->pri_posicao=(*(j.tabuleiro+lin1-DIF_CH_INT))+col1-1;
    (j.navios+navio)->lin=lin1-DIF_CH_INT;
    (j.navios+navio)->col=col1-1;

    /* Preenche o tabuleiro, verificando a direção dos navios colocados */
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

/* Valida a posição do navio escolhida pelo jogador */
int checa_validade_navio(jogador j, int navio, char lin1, int col1, char lin2, int col2){
    int i;

    if(lin1<'A'||lin1>('A'+LIN-1)||lin2<'A'||lin2>('A'+LIN-1)||col1<1||col1>(COL-1)||col2<1||col2>(COL-1)) return 0;

    if(lin1==lin2 && (col2-col1)==(j.navios+navio)->size-1){
        for(i=0;i<(j.navios+navio)->size;i++){
            if(*(*(j.tabuleiro+lin1-DIF_CH_INT)+col1-1+i)==CHAR_NAVIO){
                return 0;
            }
            
        }
        return 1;
        /* Verifica mesma coluna */
    }else if(col1==col2 && (lin2-lin1)==(j.navios+navio)->size-1){
        for(i=0;i<(j.navios+navio)->size;i++){
            if(*(*(j.tabuleiro+lin1-DIF_CH_INT+i)+col1-1)==CHAR_NAVIO){
                return 0;
            }
        }
        return 1;
    }else{
        return 0;
    }
}

/* Utilizado na fase de ataque, verefica_area_tiro() descobre qual navio foi acertado e se ele foi completamente destruido ou não  */ 
int verifica_area_tiro (jogador j, jogador j_outro, int lin, int col) {
    int navio, achei_navio = 0, i;
    unsigned char *posicao_tiro, valor;


    /* Chegou aqui sabe-se que acertou uma posição, agora varre os navios para descobrir qual ele acertou */
    for (navio = 0; navio < NAVIOS && achei_navio == 0; navio++){
        /* Pega a posição da memória do tiro transformando a linha e coluna em endereço de memória do tabuleiro */
        posicao_tiro = (* ( j.tabuleiro + lin ) ) + col;
        
        /* Compara a posicao_tiro com todas as posições do navio */

        /* Para horizontal: */
        if((j.navios+navio)->direction == 0){
            for(i=0;i<(j.navios+navio)->size;i++){
                /* Representação da posicao de memória: &j.tabuleiro [linha][coluna+i] */
                if (*(j.tabuleiro + (j.navios+navio)->lin) + (j.navios+navio)->col+i == posicao_tiro){
                    achei_navio = 1;
                    break;
                }
            }

        /* Para vertical: */
        } else{
            for(i=0;i<(j.navios+navio)->size;i++){
                /* Representaçãoda posicao de memória: &j.tabuleiro [linha+i][coluna] */
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

/* Avalia o que tem na posição atacada, informando "BOMBA!" se acertou um navio, "AGUA" se errou. Também marca o mapa com acertou ou erro */
int avalia_ataque(jogador j, jogador j_outro, int lin, int col){

    unsigned char *posicao = *(j.tabuleiro+lin)+col;

    if (*posicao == CHAR_NAVIO) {        
        *posicao = CHAR_ACERTO_NAVIO;
        system("cls");
        print_tabuleiro(j_outro,j);
        printf("BOMBA!\n");

    } else if ( *posicao == CHAR_ACERTO_NAVIO ) {
        return 1;
    } else {
        *posicao = CHAR_ACERTO_AGUA;
        system("cls");
        print_tabuleiro(j_outro,j);
        printf("Agua!\n");   
        return 0;     
    }

    verifica_area_tiro (j, j_outro, lin, col);

    return 0;
}

/* Rotina principal do ataque, que entra as coordenadas, checa se são válidas e as identificam como acerto ou erro */
void ataque(jogador j, jogador j_outro){
    char lin;
    int col, fim_ataque=0;
    
    do {
        fflush(stdin);
        printf("Escolha a coordenada do seu ataque: ");
        scanf(" %c%d", &lin, &col);
        
        if ((lin < 'A' ||lin>'A'+LIN-1) || (col < 1 || col>COL-1)){
            system("cls");
            print_tabuleiro(j_outro, j);
            printf ("Coordenadas invalidas!\n");
        }

        else {
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

/* Checa a derrota do jogador verificando se ainda existem navios não-destruidos */
int checa_derrota(jogador j_atingido){
    int i;
    for(i=0;i<NAVIOS;i++){
        if((j_atingido.navios+i)->pri_posicao!=NULL){
            return 0;
        }
    }
    return 1;
}