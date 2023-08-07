/* Este programa recebe a duração em segundos de um determinado evento
e o informa expresso no formato horas:minutos:segundos.
*/

#include <stdio.h>

int main (void){
	int horas,minutos,segundos;

    scanf("%d", &segundos);

    horas = (segundos/3600);
    minutos = (segundos - (3600*horas))/60;
    segundos = (segundos - (3600*horas)-(minutos*60)); 

    printf("%d:%d:%d\n", horas,minutos,segundos);

    return 0;
}