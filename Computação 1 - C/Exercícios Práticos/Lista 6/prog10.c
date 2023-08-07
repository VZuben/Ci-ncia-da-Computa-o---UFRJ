#include <stdio.h>

#define TAM 100

int TamanhoCadeia (char v[]) {
    int tamanho=0;
    while (v[tamanho] != 0){
        tamanho++;     
    }
    return tamanho;
}

int ondeEsta(char frase1[], char frase2[]){
    int i=0, j=0, k=0;

    while ((frase2[j] != 0)) {
        
        if (frase2[j] != frase1[i]) {
            j++;
            i = 0;
        } else {
            k = 0;
            while (frase1[k] != 0 && frase2[j + k] != 0) {
              if (frase2[j + k] != frase1[k]) {
                 break;
              }
              k++;
            }
            /* Se passou o while completo é porque frase1 igual a fragmento da frase2 */
            if (frase1[k] == 0) return j;
            j++;
        }
    }
    return -1;
}

int main(){
    char frase1[TAM], frase2[TAM];
    int posicao;

    printf("Digite a frase 1:\n");
    fgets(frase1, TAM, stdin);
    frase1[TamanhoCadeia(frase1) - 1] = 0;

    printf("Digite a frase 2:\n");
    fgets(frase2, TAM, stdin);
    frase2[TamanhoCadeia(frase2) - 1] = 0;
    
    posicao = ondeEsta(frase1, frase2);

    if (posicao == -1){
        printf("O vetor 1 nao esta contido no vetor 2");
        return 1;
    }

    printf("O vetor 1 esta contido no vetor 2\n");
    printf("O vetor 1 aparece na posicao [%d] do vetor 2", posicao);

    return 0;
}