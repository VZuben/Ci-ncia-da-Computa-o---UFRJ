/*  Nome: Pedro Henrique Figueiredo Von Zuben
     DRE: 119055699 
PROGRAMA: URI - 1031 (Carga de um avião) */

#include <stdio.h>
#include <stdlib.h>

unsigned long int qntd_memoria(){
    unsigned long int megabytes=0, bytes=0, kbytes=0;
    char *p;
    while(1){
        p = malloc(megabytes * 1000000);
        if (!p){
            free(p);
            break;
        }
        megabytes++;
        free(p);
    }

    while(1){
        p = malloc(((megabytes - 1) * 1000000) + kbytes * 1000);
        if (!p){
            free(p);
            break;
        }
        kbytes++;
        free(p);
    } 

    while(1){
        p = malloc(((megabytes - 1) * 1000000) + ((kbytes - 1) * 1000) + bytes);
        if (!p){
            free(p);
            break;
        }
        bytes++;
        free(p);
    }
    printf("Memoria Calculada!\nMemoria total: %lu\n", (((megabytes - 1) * 1000000) + ((kbytes - 1) * 1000) + bytes));
    return ((megabytes - 1) * 1000000) + ((kbytes - 1) * 1000) + bytes;
}

int main(){
    unsigned long int peso_max = qntd_memoria(), peso, peso_total=0;

    do {
        scanf("%lu", &peso);
        peso_total += peso;
    } while (peso != 0);

    if (peso_total < peso_max){
        printf("Pronto para decolar!\n");
    } else{
        printf("Sobrepeso!\n");
    }

    return 0;
}