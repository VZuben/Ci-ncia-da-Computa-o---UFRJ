#include <stdio.h>
#include <string.h>

#define DIM 28

void bubble_sort(char vetor[], int tamanho){
    int trocou, i, temp;
    do {
        trocou = 0;
        for (i = 0; i < tamanho - 1; i++){
            if (vetor[i] > vetor[i + 1]){
                temp = vetor[i];
                vetor[i] = vetor[i + 1];
                vetor[i + 1] = temp;
                trocou = 1;
            }
        }
        tamanho--;
    } while (trocou == 1);
}


int main(){
    int N, i, j, k, flag_achei, flag_cheater, repetido;
    char diet[28], breakfast[28], lunch[28], comido[55], diner[55];

    scanf("%d", &N); getchar();

    for (i = 0; i < N; i++){

        
        fgets (diet, 28, stdin);
        fgets (breakfast, 28, stdin);
        fgets (lunch, 28, stdin);

        diet[strlen(diet)-1] = 0;
        breakfast[strlen(breakfast)-1] = 0;
        lunch[strlen(lunch)-1] = 0;

        diner[0] = 0;
        comido[0] = 0;
        flag_cheater = 0;
        strcat(comido, breakfast);
        strcat(comido, lunch);

        for (j = 0; j < strlen(comido); j++){
            repetido = 0;
            for (k = 0; k < strlen(comido); k++){
                if (comido[j] == comido[k]){
                    repetido++;
                }
            }
            if (repetido >= 2){
                printf("CHEATER\n");
                flag_cheater = 1;
                break;
            }
        }

        if (flag_cheater == 0){
            for (j = 0; j < strlen(comido); j++){
                flag_cheater = 1;
                for (k = 0; k < strlen(diet); k++){
                    if (comido[j] == diet[k]){
                        flag_cheater = 0;
                        break;
                    }
                }
                if (flag_cheater == 1){
                    printf("CHEATER\n");
                    break;
                }
            }
        }

        if (flag_cheater == 0){         
            for (j = 0; j < strlen(diet); j++){
                flag_achei = 0;
                for (k = 0; k < strlen(comido); k++){
                    if (diet[j] == comido[k]){
                        flag_achei = 1;
                        break;
                    }
                }
                if (flag_achei == 0 && strlen(diner) < 55){
                    diner[strlen(diner) + 1] = 0;
                    diner[strlen(diner)] = diet[j];
                }  

            } 
            bubble_sort(diner, strlen(diner));

            printf("%s\n", diner);  

        }
    }
    return 0;
}