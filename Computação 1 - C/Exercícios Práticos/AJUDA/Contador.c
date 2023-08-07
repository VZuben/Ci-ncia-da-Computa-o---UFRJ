#include <stdio.h>
#include <stdlib.h>

int main(){
    int contador=-1;
    FILE *pa;
    char *nome = "texto.txt";

    if((pa = fopen(nome, "r"))==NULL) {
        printf("\n\n Erro ao abrir o arquivo - leitura.\n");
        exit (1);
    }

    do {
        contador++;
        fgetc(pa);
    } while (!feof(pa));
    
    fclose(pa);
    printf("Contador: %d", contador);

    return 0;
}
