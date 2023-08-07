#include <stdio.h>

#define ALTURA 10
#define LARGURA 10

int MoveEsquerda (int x);
int MoveDireita (int x);
int MoveCima (int y);
int MoveBaixo (int y);

int main (void) {
    int px=0, py = 0;
    char ordem;
    int continua = 1;

    while (continua) {
        fflush(stdin);
        ordem = getchar();
        switch(ordem) {
            case 'a': case 'A':
                px = MoveEsquerda(px);
                break;
            case 'd': case 'D':
                px = MoveDireita(px);
                break;
            case 'w': case 'W':
                py = MoveCima(py);
                break;
            case 'x': case 'X':
                py = MoveBaixo(py);
                break;
            case 'q': case 'Q':
                continua = 0;
                break;
            default:
                puts("Opcao invalida");
        }
        printf("Estou em %d %d\n", px, py);
    }
    return 0;
}

int MoveEsquerda(int x) {
    if (x > 0) x--;
    return x;
}

int MoveDireita(int x) {
    if (x < LARGURA) x++;
    return x;
}

int MoveCima(int y) {
    if (y < ALTURA) y++;
    return y;
}

int MoveBaixo(int y) {
    if (y > 0) y--;
    return y;
}