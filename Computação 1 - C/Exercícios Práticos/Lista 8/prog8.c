#include <stdio.h>
#include <stdlib.h>

#define TAM 3

typedef struct _TEMPO {
    int hora, minuto, segundo;
} TEMPO;

int comparaTempo(TEMPO *t1, TEMPO *t2){
    int diferenca = ( (t1->hora * 3600) + (t1->minuto * 60)  + (t1->segundo) ) - ( (t2->hora * 3600) + (t2->minuto * 60) + (t2->segundo) );
    return diferenca;
}

int main(){
    TEMPO *t, temp;
    int i, tempo_total, trocou, tamanho;

    t = (TEMPO *) malloc(TAM * sizeof(TEMPO));
    if (!t){
        printf("Sem memoria!");
        return 1;
    }

    for (i = 1; i <= TAM; i++){
        printf("Digite as horas, minutos e segundos de t[%d]: ", i);
        scanf("%d %d %d", &((t+i-1)->hora), &((t+i-1)->minuto), &((t+i-1)->segundo));
    }

    for (i = 1; i <= TAM; i++){
        tempo_total      = ((t+i-1)->hora) * 3600 + ((t+i-1)->minuto) * 60 + ((t+i-1)->segundo);
        (t+i-1)->hora    = (tempo_total/3600);
        (t+i-1)->minuto  = (tempo_total - (3600*((t+i-1)->hora)))/60;
        (t+i-1)->segundo = (tempo_total - (3600*((t+i-1)->hora))-((t+i-1)->minuto)*60); 
    }
    
    do {
        trocou = 0;
        tamanho = TAM;
        for (i = 0; i < tamanho - 1; i++){
            if (comparaTempo(t + i, t + i + 1) > 0){
            /*if (*(t + i) > *(t + i + 1)){*/
                temp = *(t + i);
                *(t + i) = *(t + i + 1);
                *(t + i + 1) = temp;
                trocou = 1;
            }
        }
        tamanho--;
    } while (trocou == 1);

    for (i = 1; i <= TAM; i++){
        printf("Tempo [%d]: %02d:%02d:%02d\n", i, (t+i-1)->hora, (t+i-1)->minuto, (t+i-1)->segundo);
    }

    free(t);

    return 0;
}