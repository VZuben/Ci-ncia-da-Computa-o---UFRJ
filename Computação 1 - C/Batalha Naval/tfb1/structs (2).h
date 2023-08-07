typedef struct _NAVIO navio;
struct _NAVIO {
    unsigned char *pri_posicao;
    unsigned char *ult_posicao;
    int size, direction, lin, col; /* Zuben: precisei adicionar os atributos linha coluna e direção para facilitar a verificação do tiro, verefique seu código "coloca_navio" */
    char nome[20];
};

typedef struct _JOGADOR jogador;
struct _JOGADOR{
    unsigned char **tabuleiro;
    char nome[3];
    navio *navios;

};