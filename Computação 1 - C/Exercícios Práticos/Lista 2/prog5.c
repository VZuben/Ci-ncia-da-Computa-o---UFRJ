/* Esta é a questão 5 da segunda lista de exercícios práticos.
*/

#include <stdio.h>
#include <math.h>

#define PI 3.14159

int main (void){
	float volume;
    const int raio = 5;
    
    volume = (4 * PI * pow(raio,3))/3;

    printf("\n O volume eh: % 10.5f \n\n", volume);

    return 0;
}