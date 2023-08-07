#include <stdio.h>

#define TAM 100

int TamanhoCadeia (char v[]) {
    int tamanho=0;
    while (v[tamanho] != 0){
        tamanho++;     
    }
    return tamanho;
}

int palindromo(char frase[], int tamanho, int contador){
    int posicao, i, j=0;
    char frase_limpa[TAM];

    for (i=0; i < tamanho; i++){
        if ((frase[i] >= 'A' && frase[i] <= 'Z') || (frase[i] >= 'a' && frase[i] <= 'z')){
            frase_limpa[j] = frase[i];
            j++;
        }
    }
    frase_limpa[j] = 0;
    tamanho = j;

    posicao = tamanho-1;

    if (contador >= tamanho/2){
        return 1;
    }

    else if (frase_limpa[contador] == frase_limpa[posicao - contador]){
        return palindromo (frase_limpa, tamanho, contador + 1);
    }
    
    else {
        return 0;
    }
}

int main(){
    char frase[TAM];

    printf("Digite uma frase:\n");
    fgets(frase, TAM, stdin);
    frase[TamanhoCadeia(frase) - 1] = 0;

    printf("%d", palindromo(frase, TamanhoCadeia(frase), 0));

    return 0;
}