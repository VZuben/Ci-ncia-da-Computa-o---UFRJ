#include <stdio.h>

typedef struct _TEMPO {
    int hora, minuto, segundo;
} TEMPO;

int main(){
    TEMPO t1, t2;
    int totalSegundos_t1, totalSegundos_t2;

    printf("Digite as horas, minutos e segundos de t1: ");
    scanf("%d %d %d", &t1.hora, &t1.minuto, &t1.segundo);

    printf("Digite as horas, minutos e segundos de t2: ");
    scanf("%d %d %d", &t2.hora, &t2.minuto, &t2.segundo);

    totalSegundos_t1 = (t1.hora * 3600) + (t1.minuto * 60) + (t1.segundo);
    totalSegundos_t2 = (t2.hora * 3600) + (t2.minuto * 60) + (t2.segundo);

    if (totalSegundos_t1 == totalSegundos_t2){
        printf("Os tempos gastos sao iguais\n");
    }

    else if (totalSegundos_t1 > totalSegundos_t2){
        printf("t1 eh maior que t2\n");
    }

    else if (totalSegundos_t2 > totalSegundos_t1){
        printf("t2 eh maior que t1\n");
    }

    return 0;
}