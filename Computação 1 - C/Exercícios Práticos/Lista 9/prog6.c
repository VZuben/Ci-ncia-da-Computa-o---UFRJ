#include <stdio.h>

int converte (N){
    if (N != 0){
        return ((N%2) + 10*converte(N/2));
    } 
    return 0;
}

int main(){
    int N;

    printf("Digite um numero inteiro em decimal\n");
    scanf ("%d", &N);
    printf ("O numero em binario eh: %d\n", converte(N));
    
    return 0;
}