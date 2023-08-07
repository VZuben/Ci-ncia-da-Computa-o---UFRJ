#include <stdio.h>

#define TAM 13571113

void LeVetor (double vetor[], int tam);
double MaiorElementoVetor (double vetor[], int tam);
double MediaVetor(double vetor[], int tam);
void OrdenaVetor(double vetor[], int tam);
void ImprimeVetor(double vetor[], int tam);

int main(void){
    double vetor[TAM];
    double media, maior;

    LeVetor(vetor, TAM);
    maior = MaiorElementoVetor(vetor, TAM);
    media = MediaVetor(vetor, TAM);
    printf("Maior elemento e: %f\n", maior);
    printf("Media do Vetor e: %f\n", media);
    OrdenaVetor(vetor, TAM);
    ImprimeVetor(vetor, TAM);

    return 0;
}

void LeVetor (double vetor[], int tam){
    int i;
    for (i = 0; i < tam; i++){
        scanf("%lf", &vetor[i]);
    }
}

double MaiorElementoVetor (double vetor[], int tam){
    int i;
    double maior=vetor[0];
    for(i = 0; i < tam; i++){
        if (maior < vetor[i]){
            maior = vetor[i];
        }
    }
    return maior;
}

double MediaVetor(double vetor[], int tam){
    int i;
    double soma=0;
    for (i = 0; i < tam; i++){
        soma += vetor[i];
    }
    return soma/tam;
}

void OrdenaVetor(double vetor[], int tam){
    int trocou, i, temp;
    do {
        trocou = 0;
        for (i = 0; i < tam - 1; i++){
            if (vetor[i] > vetor[i + 1]){
                temp = vetor[i];
                vetor[i] = vetor[i + 1];
                vetor[i + 1] = temp;
                trocou = 1;
            }
        }
        tam--;
    } while (trocou == 1);
}

void ImprimeVetor(double vetor[], int tam){
    int i;
    for (i = 0; i < tam; i++){
        printf("Vetor[%d]= %lf\n", i, vetor[i]);
    }
}