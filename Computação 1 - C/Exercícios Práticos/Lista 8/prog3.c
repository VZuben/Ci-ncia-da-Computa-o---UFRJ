#include <stdio.h>
#include <math.h>

float hypotf(float , float);

typedef struct _PONTO {
    float x, y;
} PONTO;

int main (void) {
    PONTO p1, p2;
    float distancia;

    printf("Entre com as coordenadas do ponto p1\n");
    scanf("%f %f", &p1.x, &p1.y);

    printf("Entre com as coordenadas do ponto p2\n");
    scanf("%f %f", &p2.x, &p2.y);

    distancia = hypotf(p1.x-p2.x, p1.y-p2.y);

    printf("A distancia entre os dois pontos eh: %f", distancia);

    return 0;
}