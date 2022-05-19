/* Disciplina: Computacao Concorrente */
/* Prof.: Silvana Rossetto */
/* Aluno: Pedro Henrique Figueiredo Von Zuben */
/* DRE: 119055699 */
/* Módulo 2 - Laboratório: 5 */
/* Codigo: Uso de variáveis de condição e suas operações básicas para sincronização por condição */

/****** Condicoes logicas da aplicacao:
 1- A thread 5 deve sempre ser a primeira a imprimir sua mensagem.
 2- A thread 1 deve sempre ser a ultima a imprimir sua mensagem.
 3- A ordem em que as threads 2, 3 e 4 imprimem suas mensagens nao importa, 
mas todas devem sempre imprimir suas mensagens depois da thread 5 e antes da thread 1.  
******/

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define NTHREADS  5

/* Variaveis globais */
int primeiro_contador = 0;
int ultimo_contador = 0;
pthread_mutex_t primeiro_contador_mutex;
pthread_mutex_t ultimo_contador_mutex;
pthread_cond_t meio_cond;
pthread_cond_t ultimo_cond;


/* Thread 5 */
void *A () {
    printf("Seja bem-vindo!\n");

    pthread_mutex_lock(&primeiro_contador_mutex);
    primeiro_contador++;
    pthread_mutex_unlock(&primeiro_contador_mutex);

    pthread_mutex_lock(&ultimo_contador_mutex);
    pthread_cond_broadcast(&meio_cond);
    pthread_mutex_unlock(&ultimo_contador_mutex);

    pthread_exit(NULL);
}

/* Thread 2, 3 e 4 */
void *B (void *arg) {
    int id = * (int *) arg;
    pthread_mutex_lock(&primeiro_contador_mutex);
    if (primeiro_contador == 0){
        pthread_cond_wait(&meio_cond, &primeiro_contador_mutex);
    }    
    pthread_mutex_unlock(&primeiro_contador_mutex);

    if(id == 1)
        printf("Fique a vontade.\n");
    if(id == 2)
        printf("Sente-se por favor.\n");
    if(id == 3)
        printf("Aceita um copo d’agua?.\n");

    pthread_mutex_lock(&ultimo_contador_mutex);
    ultimo_contador++;
    if (ultimo_contador == 3) { 
        pthread_cond_signal(&ultimo_cond);
    }
    pthread_mutex_unlock(&ultimo_contador_mutex); 

    pthread_exit(NULL);
}

/* Thread 1 */
void *C () {
  pthread_mutex_lock(&ultimo_contador_mutex);
  if (ultimo_contador < 3) { 
     pthread_cond_wait(&ultimo_cond, &ultimo_contador_mutex);
  }
  pthread_mutex_unlock(&ultimo_contador_mutex); 
  printf("Volte sempre!\n");
  pthread_exit(NULL);
}

/* Funcao principal */
int main(int argc, char *argv[]) {
    int i; 
    pthread_t tid[NTHREADS];  //identificadores das threads no sistema
    int tid_meio[3];          //identificadores locais das threads 2, 3 e 4

    /* Inicilaiza o mutex (lock de exclusao mutua) e a variavel de condicao */
    pthread_mutex_init(&primeiro_contador_mutex, NULL);
    pthread_mutex_init(&ultimo_contador_mutex, NULL);
    pthread_cond_init (&meio_cond, NULL);
    pthread_cond_init (&ultimo_cond, NULL);
    
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
    pthread_mutex_destroy(&primeiro_contador_mutex);
    pthread_mutex_destroy(&ultimo_contador_mutex);
    pthread_cond_destroy(&meio_cond);
    pthread_cond_destroy(&ultimo_cond);
}
