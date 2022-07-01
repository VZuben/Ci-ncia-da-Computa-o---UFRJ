/* Disciplina: Computacao Concorrente */
/* Prof.: Silvana Rossetto */
/* Aluno: Pedro Henrique Figueiredo Von Zuben */
/* DRE: 119055699 */
/* Módulo 3 - Laboratório: 9 */
/* Codigo: uso de semáfaros para implementar a exclusão mútua e sincronização condicional */

/****** Condicoes logicas da aplicacao:
 1- A thread 5 deve sempre ser a primeira a imprimir sua mensagem.
 2- A thread 1 deve sempre ser a ultima a imprimir sua mensagem.
 3- A ordem em que as threads 2, 3 e 4 imprimem suas mensagens não importa, 
mas todas devem sempre imprimir suas mensagens depois da thread 5 e antes da thread 1.  
******/

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <semaphore.h>

#define NTHREADS  5

/* Variaveis globais */
int count = 3;      // quantidade de mensagens que faltam ser imprimidas depois da thread 5 e antes da thread 1
sem_t em;           // semaforo para exclusao mutua entre as threads
sem_t condB, condC; // Semáforos para sincronizar a ordem de execução das threads


/* Thread 5 */
void *A () {
    printf("Seja bem-vindo!\n");

    // Permite as execuções das threads 2, 3 e 4
    sem_post(&condB);
    sem_post(&condB);
    sem_post(&condB);

    pthread_exit(NULL);
}

/* Thread 2, 3 e 4 */
void *B (void *arg) {
    int id = * (int *) arg;

    sem_wait(&condB); // Espera a thread 5 executar

    if(id == 1)
        printf("Fique a vontade.\n");
    if(id == 2)
        printf("Sente-se por favor.\n");
    if(id == 3)
        printf("Aceita um copo d’agua?.\n");


    sem_wait(&em); // Entrada na seção crítica
    count--;
    if(count == 0) sem_post(&condC); // Permite a execução da thread 1 quando não houverem mais mensagens a serem imprimidas
    sem_post(&em); // Saída da seção crítica

    pthread_exit(NULL);
}

/* Thread 1 */
void *C () {
    sem_wait(&condC); // Espera as threads 2, 3 e 4 executarem

    printf("Volte sempre!\n");

    pthread_exit(NULL);
}

/* Funcao principal */
int main(int argc, char *argv[]) {
    int i; 
    pthread_t tid[NTHREADS];  //identificadores das threads no sistema
    int tid_meio[3];          //identificadores locais das threads 2, 3 e 4

    // Inicia os semáforos
    sem_init(&em, 0, 1);
    sem_init(&condB, 0, 0);
    sem_init(&condC, 0, 0);

    
    /* Cria as threads */
    pthread_create(&tid[0], NULL, C, NULL);
    for(int i=1; i <= 3; i++){
        tid_meio[i-1] = i;
        pthread_create(&tid[i], NULL, B, (void*) &tid_meio[i-1]); 
    }
    pthread_create(&tid[4], NULL, A, NULL);

    /* Espera todas as threads completarem */
    for (i = 0; i < NTHREADS; i++) {
        pthread_join(tid[i], NULL);
    }

    /* Desaloca variaveis e termina */
    sem_destroy(&em);
    sem_destroy(&condB);
    sem_destroy(&condC);
}
