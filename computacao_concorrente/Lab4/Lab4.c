/* Disciplina: Computacao Concorrente */
/* Prof.: Silvana Rossetto */
/* Aluno: Pedro Henrique Figueiredo Von Zuben */
/* DRE: 119055699 */
/* Módulo 1 - Laboratório: 4 */
/* Codigo: Função que recebe um vetor de entrada de numeros inteiros e gera um vetor de saída de
numeros reais, calculando a raiz quadrada de todos os elementos do vetor de entrada
que forem primos (de forma sequencial e concorrente). Comunicação entre threads usando variável compartilhada e exclusao mutua com bloqueio*/

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include "timer.h"
#include <time.h>
#include <math.h>

long long int dim;      //dimensao do vetor de entrada e saída
int nthreads;           //numero de threads
int i_global = 0;       //variavel compartilhada entre as threads (identificador de thread global)
int *vetorEntrada;      //vetor de entrada com dimensao dim 
float *vetorSaidaSeq;   //vetor de saída feito de forma sequencial com dimensao dim 
float *vetorSaidaConc;  //vetor de saída feito de forma concorrente com dimensao dim 
pthread_mutex_t bastao; //variavel de lock para exclusao mutua

//funçao que descobre se o elemento passado é primo ou não.
int ehPrimo(long long int n) { 
    if (n <= 1)
        return 0;
    if (n == 2)
        return 1;
    if (n % 2 == 0)
        return 0;
    for (int i = 3; i < sqrt(n) + 1; i += 2)
        if (n % i == 0)
            return 0;
    return 1;
}

void processaPrimosSeq() {
    for(int i=0; i<dim; i++) {
        if (ehPrimo(vetorEntrada[i]))
            vetorSaidaSeq[i] = sqrt(vetorEntrada[i]);
        else
            vetorSaidaSeq[i] = vetorEntrada[i];
    }
}

void *processaPrimosConc(void *arg) {
    int i_local;  //identificador de thread local

    //sincronização utilizando exclusao mutua com bloqueio
    pthread_mutex_lock(&bastao);
    i_local = i_global;
    i_global++;
    pthread_mutex_unlock(&bastao);

    while (i_local < dim) {
        if (ehPrimo(vetorEntrada[i_local]))
            vetorSaidaConc[i_local] = sqrt(vetorEntrada[i_local]);
        else 
            vetorSaidaConc[i_local] = vetorEntrada[i_local];
        
        //sincronização utilizando exclusao mutua com bloqueio
        pthread_mutex_lock(&bastao);
        i_local = i_global; i_global++;
        pthread_mutex_unlock(&bastao);
    }
    pthread_exit(NULL);
}

//fluxo principal
int main(int argc, char *argv[]) {
    double ini, fim, tempo_seq, tempo_conc;; //tomada de tempo

   //recebe e valida os parametros de entrada (dimensao do vetor, numero de threads)
   if(argc < 3) {
       fprintf(stderr, "Digite: %s <dimensao do vetor> <numero threads>\n", argv[0]);
       return 1; 
   }
    dim = atoll(argv[1]);
    nthreads = atoi(argv[2]);
    pthread_t tid[nthreads];  //identificadores das threads no sistema

    //--Alocação de Memoria
    vetorEntrada = (int *) malloc(sizeof(int) * dim);
    if(vetorEntrada == NULL) {
        fprintf(stderr, "ERRO--malloc\n");
        return 2;
   }
    vetorSaidaSeq = (float *) malloc(sizeof(float) * dim);
    if(vetorSaidaSeq == NULL) {
        fprintf(stderr, "ERRO--malloc\n");
        return 2;
   }
    vetorSaidaConc = (float *) malloc(sizeof(float) * dim);
    if(vetorSaidaConc == NULL) {
        fprintf(stderr, "ERRO--malloc\n");
        return 2;
   }

    //inicializacao das estruturas de dados de entrada e saida
    for (int i=0; i<dim; i++){
        vetorEntrada[i]   = (rand() % 400001) + 400000;    //(rand() % (b-a+1)) + a ------- Vetor com elementos aleatórios entre [a, b]
        vetorSaidaSeq[i]  = 0;
        vetorSaidaConc[i] = 0;
    }   

    //FORMA SEQUENCIAL
    GET_TIME(ini);
    processaPrimosSeq();
    GET_TIME(fim);
    tempo_seq = fim - ini;

    //FORMA CONCORRENTE
    GET_TIME(ini);
    //--inicilaiza o mutex (lock de exclusao mutua)
    pthread_mutex_init(&bastao, NULL);

    //--cria as threads
    for (long int t = 0; t < nthreads; t++) {
        if (pthread_create(&tid[t], NULL, processaPrimosConc, NULL)) {
            printf("--ERRO: pthread_create()\n");
            exit(-1);
        }
    }

    //--espera todas as threads terminarem
    for (int t = 0; t < nthreads; t++) {
        if (pthread_join(tid[t], NULL)) {
            printf("--ERRO: pthread_join()\n");
            exit(-1);
        }
    }

    pthread_mutex_destroy(&bastao);  //libera a area de memoria alocada
    GET_TIME(fim);
    tempo_conc = fim - ini;

    //corritude
    for (int i=0; i<dim; i++){
        if (vetorSaidaSeq[i] != vetorSaidaConc[i]) {
            printf("Os vetores de saída não são iguais\n");
            return 3;
        }
    }
    printf("Os vetores de saída são iguais\n");
    printf("Tempo sequencial:   %lf\n", tempo_seq);
    printf("Tempo concorrente:  %lf\n", tempo_conc);

    //libera as areas de memoria alocadas
    free(vetorEntrada);
    free(vetorSaidaSeq);
    free(vetorSaidaConc);
    
    return 0;
}