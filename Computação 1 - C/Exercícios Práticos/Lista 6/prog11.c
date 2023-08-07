#include <stdio.h>

void Converter (int numeroBase10, int numeroBase2[32]){
    int i=0;

    for (i=0; i < 32; i++){
        numeroBase2[i]=0;
    }

    i = 31;

    while (numeroBase10 != 0){
        numeroBase2[i] = numeroBase10 % 2;
        i--;
        numeroBase10 = numeroBase10 / 2;
    }

}

int main(){
    int numeroBase10, numeroBase2[32], i;

    printf("Digite um numero inteiro em decimal:\n");
    scanf ("%d", &numeroBase10);
    printf ("O numero em binario eh: ");

    Converter (numeroBase10, numeroBase2);

    for (i=0; i < 32; i++){
        printf("%d ", numeroBase2[i]);
    }

    printf("\n");

    return 0;
}