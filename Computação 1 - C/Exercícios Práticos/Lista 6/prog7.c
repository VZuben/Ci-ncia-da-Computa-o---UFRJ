#include <stdio.h>

double Pi (int termos);

int main(){
    int termos;

    printf("Digite o numero de termos da serie que deseja usar para calcular Pi.\n");
    scanf("%d", &termos);

    printf("O valor de Pi eh: %lf\n", Pi(termos));

    return 0;
}

double Pi (int termos){
    int i, j, sinal=1;
    double soma=0;
    for(i=0, j=1; i < termos; i++, j+=2){
        soma += sinal*(1.0/j);
        sinal = -sinal;
    }
    
    return 4*soma;
}