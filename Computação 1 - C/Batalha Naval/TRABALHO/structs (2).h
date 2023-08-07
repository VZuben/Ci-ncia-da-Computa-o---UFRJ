/* Área de definição do jogador, tabuleiro e navios e os controles necessários para o programa */
typedef struct _NAVIO navio;
struct _NAVIO {
    unsigned char *pri_posicao;
    unsigned char *ult_posicao;
    int size, direction, lin, col;
    char nome[20];
};

typedef struct _JOGADOR jogador;
struct _JOGADOR{
    unsigned char **tabuleiro;
    char nome[3];
    navio *navios;

};