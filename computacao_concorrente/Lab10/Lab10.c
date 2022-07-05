/* Disciplina: Computacao Concorrente */
/* Prof.: Silvana Rossetto */
/* Aluno: Pedro Henrique Figueiredo Von Zuben */
/* DRE: 119055699 */
/* Módulo 3 - Laboratório: 10 */
/* Codigo:  O algoritmo abaixo implementa uma solução para o problema 
dos leitores e escritores com prioridade para escrita utilizando semáfaros */


#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <semaphore.h>
#include <unistd.h>

#define L 10 //numero de threads leitoras
#define E 5 //numero de threads escritoras

/* Variaveis globais */
int l=0; //contador de threads lendo
int e=0; //contador de threads escrevendo

/* Semáforos */
sem_t em_e, em_l, escr, leit;


/* Thread Leitora */
void * leitor (void * arg) {
    int *id = (int *) arg;
    while(1) {
        sem_wait(&leit);
        sem_wait(&em_l); 
        printf("L[%d] quer ler\n", *id);
        l++; if(l==1) sem_wait(&escr);
        sem_post(&em_l);                      
        sem_post(&leit);
        printf("L[%d] esta lendo\n", *id);
        //le...
        sem_wait(&em_l); 
        printf("L[%d] terminou de ler\n", *id);
        l--; if(l==0) sem_post(&escr);
        sem_post(&em_l);
        sleep(1);
    }
    free(arg);
    pthread_exit(NULL);
}

/* Thread Escritora */
void * escritor (void * arg) {
    int *id = (int *) arg;
    while(1) {
        sem_wait(&em_e); 
        printf("E[%d] quer escrever\n", *id);
        e++; if(e==1) sem_wait(&leit);
        printf("E[%d] esta esperando\n", *id);
        sem_post(&em_e);
        sem_wait(&escr);     
        printf("E[%d] esta escrevendo\n", *id);                  
        //escr...
        printf("E[%d] terminou de escrever\n", *id);
        sem_post(&escr);
        sem_wait(&em_e);
        e--; if(e==0) sem_post(&leit);
        sem_post(&em_e);
        sleep(1);
    }
    free(arg);
    pthread_exit(NULL);
}

/* Funcao principal */
int main(int argc, char *argv[]) {
    int i; 
    pthread_t tid[L+E];  //identificadores das threads no sistema
    int id[L+E];         //identificadores locais das threads 2, 3 e 4

    // Inicia os semáforos
    sem_init(&em_l, 0, 1);
    sem_init(&em_e, 0, 1);
    sem_init(&leit, 0, 1);      
    sem_init(&escr, 0, 1);      

    //cria as threads leitoras
    for(int i=0; i<L; i++) {
        id[i] = i+1;
        if(pthread_create(&tid[i], NULL, leitor, (void *) &id[i])) exit(-1);
    } 

    //cria as threads escritoras
    for(int i=0; i<E; i++) {
        id[i+L] = i+1;
        if(pthread_create(&tid[i+L], NULL, escritor, (void *) &id[i+L])) exit(-1);
    } 

    /* Espera todas as threads completarem */
    for (i = 0; i < L+E; i++) {
        pthread_join(tid[i], NULL);
    }

    /* Desaloca variaveis e termina */
    sem_destroy(&em_l);
    sem_destroy(&em_e);
    sem_destroy(&leit);
    sem_destroy(&escr);

}
