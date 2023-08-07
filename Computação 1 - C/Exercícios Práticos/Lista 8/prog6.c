#include <stdio.h>

typedef struct _TEMPO {
    int hora, minuto, segundo;
} TEMPO;

int main(){
    TEMPO t1, t2, t3;
    int tempo_total;

    printf("Digite as horas, minutos e segundos de t1: ");
    scanf("%d %d %d", &t1.hora, &t1.minuto, &t1.segundo);

    printf("Digite as horas, minutos e segundos de t2: ");
    scanf("%d %d %d", &t2.hora, &t2.minuto, &t2.segundo);

    tempo_total = (t1.hora * 3600) + (t2.hora * 3600) + (t1.minuto * 60) + (t2.minuto * 60) + (t1.segundo) + (t2.segundo);

    t3.hora    = (tempo_total/3600);
    t3.minuto  = (tempo_total - (3600*t3.hora))/60;
    t3.segundo = (tempo_total - (3600*t3.hora)-(t3.minuto*60));

    printf("O resultado da soma de t1 com t2 eh: %02d:%02d:%02d\n", t3.hora, t3.minuto, t3.segundo);

    return 0;
}