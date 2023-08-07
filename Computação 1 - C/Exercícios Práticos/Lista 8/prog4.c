#include <stdio.h>
#include <math.h>

float hypotf(float , float);

typedef struct _PONTO {
    float x, y;
} PONTO;

typedef struct _CIRCUNFERENCIA {
    float raio;
    PONTO centro;
} CIRCUNFERENCIA;

int main (void) {
    PONTO p1;
    CIRCUNFERENCIA c1;
    float distancia;

    printf("Entre com as coordenadas do ponto p1\n");
    scanf("%f %f", &p1.x, &p1.y);

    printf("Entre com o raio de c1\n");
    scanf("%f", &c1.raio);

    printf("Entre com as coordenadas do centro de c1\n");
    scanf("%f %f", &c1.centro.x, &c1.centro.y);

    distancia = hypotf(p1.x-c1.centro.x, p1.y-c1.centro.y);

    if (distancia < c1.raio){
        printf("O ponto esta contido dentro da circunferencia\n");
    }

    else {
    printf("O ponto nao esta contido dentro da circunferencia\n");
    }

    return 0;
}