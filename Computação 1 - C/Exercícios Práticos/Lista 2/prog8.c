/* Esta é a questão 8 da segunda lista de exercícios práticos.
*/

#include <stdio.h>

int main (void){
	int tempo1,tempo2,tempo_total,horario_saida,horas,minutos,segundos;
    
    /* s=so+vt 
    */

    tempo1 = (15.0/25)*3600;
    tempo2 = (10.0/30)*3600;
    tempo_total = tempo1+tempo2+(15*60);
    horario_saida = (8*3600) - tempo_total;

    horas =   (horario_saida/3600);
    minutos = (horario_saida - (3600*horas))/60;
    segundos = (horario_saida - (3600*horas)-(minutos*60)); 

    printf("Eu preciso sair as %02d:%02d:%02d \n\n", horas,minutos,segundos);

    return 0;
}