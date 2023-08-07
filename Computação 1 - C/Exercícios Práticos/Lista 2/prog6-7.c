/* Esta é a questão 6 e 7 da segunda lista de exercícios práticos.
*/

#include <stdio.h>

int main (void){
	float temperatura_celcius,temperatura_fahrenheit,temperatura_kelvin;

	printf("\nEntre com a temperatura em graus celcius: ");
	scanf("%f", &temperatura_celcius);
	
    temperatura_fahrenheit = temperatura_celcius * 9/5 + 32;
    temperatura_kelvin     = temperatura_celcius + 273.15;

    printf("A temperatura em fahrenheit eh : %5.2f \n",temperatura_fahrenheit);
    printf("A temperatura em kelvin eh : %5.2f \n\n",temperatura_kelvin);

    return 0;
}