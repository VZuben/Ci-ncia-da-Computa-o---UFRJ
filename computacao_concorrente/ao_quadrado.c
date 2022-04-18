/* Disciplina: Computacao Concorrente */
/* Prof.: Silvana Rossetto */
/* Aluno: Pedro Henrique Figueiredo Von Zuben */
/* DRE: 119055699 */
/* Módulo 1 - Laboratório: 1 */
/* Codigo: Função que eleva ao quadrado cada elemento de um vetor de 
10.000 elementos (para cada elemento a_i do vetor, calcula (a_i)² 
e escreve o resultado na mesma posição do elemento) 
utilizando duas threads (além da thread principal). */

#include <stdio.h>
#include <stdlib.h> 
#include <pthread.h>

#define NTHREADS 2
#define QNT_ELEMENTOS 10000

int vetor[QNT_ELEMENTOS];

//funcao que a thread ira executar
void * ao_quadrado (void * arg) {
    int ident = * (int *) arg;
    //thread de número 1 eleva os elementos do vetor de 0 à 4999 ao quadrado
    if (ident == 1) {
        for(int i=0; i<(QNT_ELEMENTOS/2); i++) {
           vetor[i] = vetor[i]*vetor[i];
        }
    //thread de número 2 eleva os elementos do vetor de 5000 à 10000 ao quadrado
    } else {
        for(int i=QNT_ELEMENTOS/2; i<QNT_ELEMENTOS; i++) {
           vetor[i] = vetor[i]*vetor[i];
        }
    }

    pthread_exit(NULL);
}

//funcao principal
int main(void) {
    pthread_t tid[NTHREADS]; //identificador da thread no sistema
    int ident[NTHREADS];     //identificador local da thread 

    //inicializando o vetor de 10.000 elementos.
    //cada elemento tem o valor de sua posição.
    for(int i=0; i<QNT_ELEMENTOS; i++) {
        vetor[i] = i;
    }

    //cria as threads
    for(int i=1; i<=NTHREADS; i++) {
        ident[i-1] = i;
        if (pthread_create(&tid[i-1], NULL, ao_quadrado, (void *)&ident[i-1]))
            printf("ERRO -- pthread_create\n");
    }
    //espera as threads terminarem
    for(int i=0; i<NTHREADS; i++) {
        if (pthread_join(tid[i], NULL))
            printf("ERRO -- pthread_create\n");
    }
    //imprime o vetor de 10.000 elementos com seus elementos ao quadrado.
    for(int i=0; i<QNT_ELEMENTOS; i++) {
           printf("vetor[%d] = %d\n", i, vetor[i]);
    }

}
