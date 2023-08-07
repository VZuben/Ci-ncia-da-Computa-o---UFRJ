#include <stdio.h>
#include <string.h>

/*Pedro Henrique Figueiredo Von Zuben 119055699*/

#define MAX_ALUNOS 1024
#define MAX_TAM_NOME 128

int main(){
    
    int i=-1, max_alunos, trocou, temp;
    char nome[MAX_ALUNOS][MAX_TAM_NOME], temps[MAX_TAM_NOME]; /* nome é uma matrix bidimensional pelo fato de cada linha nessa matrix ser um aluno diferente*/
    int  nota[MAX_ALUNOS];

    do {
   
        i++;

        fgets(nome[i], MAX_TAM_NOME, stdin);
        fflush(stdin);   /*limpa \n */
     
        scanf("%d", &nota[i]); 
        fflush(stdin);  /*limpa \n */
        
    } while(nota[i] != -1);

    max_alunos = i -1; /* diminuo 1 do tamanho maximo para tirar a nota -1 que não existe */

    do {
        trocou = 0;
        for (i = 0; i < max_alunos; i++){
            if (nota[i] > nota[i + 1]){
                /* Troca no vetor de notas */
                temp = nota[i];
                nota[i] = nota[i + 1];
                nota[i + 1] = temp;                              /* tentei criar um bubble sort aki, mas não deu tempo para otimiza-lo e transforma-lo em função*/
                
                /* Troca no vetor de nomes */
                strcpy(temps, nome[i]);
                strcpy(nome[i], nome[i + 1]);          /*usei o strcpy para testar rapidamente se funcionava mas acabei não tendo tempo de copiar o código de strcpy que fiz DEPOIS pra cá*/
                strcpy(nome[i + 1], temps);             /* eu fiz o srcpy DEPOIS pois comecei pela questão 4 e depois fui indo em ordem decrescente*/

                trocou = 1;         /* se não trocou, já está ordenado então sai do while */
            }
        }
    } while (trocou == 1);

    for (i = 0; i <= max_alunos; i++){
      printf ("%s %d\n", nome[i], nota[i]);
    }

    return 0;
}
