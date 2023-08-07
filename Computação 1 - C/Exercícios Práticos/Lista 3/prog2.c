/* Este programa recebe o raio e retorna a area do circulo correspondente.
*/

#include <stdio.h>
#include <math.h>

#define PI 3.14159

int main (void){

    double raio, area;

    scanf("%lf", &raio);

    area = PI * pow(raio,2);

    printf("A=%.4lf\n", area);

    return 0;
}