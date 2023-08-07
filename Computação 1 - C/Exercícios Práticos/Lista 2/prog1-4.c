/* Esta é a questão 1 até a 4 da segunda lista de exercícios práticos.
*/

#include <stdio.h>

#define MPH 2.23694

int main (void){
	unsigned int horas,minutos,segundos,tempo_total_segundos;
	float distancia,velocidade_media;

	printf("\n Entre com a quantidade de horas gastas no percurso: ");
	scanf("%u", &horas);
	printf("\n Entre com a quantidade de minutos gastos no percurso: ");
	scanf("%u", &minutos);
    printf("\n Entre com a quantidade de segundos gastos no percurso: ");
	scanf("%u", &segundos);
	printf("\n Entre com a distancia, em metros, do percurso: ");
	scanf("%f", &distancia);
	
    tempo_total_segundos = (horas*60*60) + (minutos*60) + segundos;
    velocidade_media = (distancia/tempo_total_segundos)*MPH;

    printf("\n The average speed in miles of the calculated body is: %-10.5f \n\n",velocidade_media);

    return 0;
}