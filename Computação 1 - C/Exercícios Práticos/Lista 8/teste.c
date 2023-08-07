#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAMNOME 81

typedef struct _ALUNO {
    char nome[TAMNOME];
    float salario;
    float imposto;
} ALUNO;



int main(){
    ALUNO *alunos;
    int qnt_alunos, i;

    printf("Qual a quantidade de alunos? ");
    scanf("%d", &qnt_alunos); getchar();

    alunos = (ALUNO *) malloc(qnt_alunos * sizeof(ALUNO));
    if (!alunos){
        printf("Sem memoria");
        return 1;
    }

    for (i = 0; i < qnt_alunos; i++){
        printf("Digite o nome do aluno [%d]: ", i+1);
        fgets((alunos+i)->nome, TAMNOME, stdin);
        *((alunos+i)->nome+(strlen((alunos+i)->nome)-1)) = 0;
        printf("Digite o salario do aluno [%d]: ", i+1);
        scanf("%f", &((alunos+i)->salario)); getchar();
        printf("Digite o imposto do aluno [%d]: ", i+1);
        scanf("%f", &((alunos+i)->imposto)); getchar();
    }

    for (i = 0; i < qnt_alunos; i++){
        printf("\nAluno[%d] = %s\n", i+1, (alunos+i)->nome);
        printf("Salario do aluno[%d] = %f\n", i+1, (alunos+i)->salario);
        printf("Imposto do aluno[%d] = %f\n", i+1, (alunos+i)->imposto);
    }
    printf("\n");

    free(alunos);

    return 0;
}