/* Este programa recebe o raio de uma esfera e retorna seu volume.
*/

#include <stdio.h>
#include <math.h>

#define PI 3.14159

int main (void){

	double raio, volume;
    
    scanf("%lf", &raio);

    volume = (4 * PI * pow(raio,3))/3;

    printf("VOLUME = %.3lf\n", volume);

    return 0;
}