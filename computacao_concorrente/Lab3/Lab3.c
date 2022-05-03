//Soma todos os elementos de um vetor de inteiro
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<pthread.h>
#include "timer.h"

long int dim;  //dimensao do vetor de entrada
int nthreads;  //numero de threads
double *vetor; //vetor de entrada com dimensao dim 

//fluxo das threads
void * tarefa(void * arg) {
   long int id = (long int) arg;      //identificador da thread
   long int tamBloco = dim/nthreads;  //tamanho do bloco de cada thread 
   long int ini = id * tamBloco;      //elemento inicial do bloco da thread
   long int fim;                      //elemento final(nao processado) do bloco da thread
   if(id == nthreads-1) fim = dim;
   else fim = ini + tamBloco;         //trata o resto se houver


   double maiorConc, menorConc;       //variaveis locais que guardam o maior e o menor elemento do bloco da thread
   maiorConc = vetor[ini];
   menorConc = vetor[ini];

   double *maior_menor_Local;         //vetor que guarda o maior e menor elemento do bloco da thread
   maior_menor_Local = (double*) malloc(sizeof(double)*2);
   if(maior_menor_Local==NULL) {exit(1);}

   //acha o maior e o menor elemento do bloco da thread
   for(long int i=ini; i<fim; i++){
      if (vetor[i] > maiorConc) maiorConc = vetor[i];
      if (vetor[i] < menorConc) menorConc = vetor[i];
   }
      maior_menor_Local[0] = maiorConc;
      maior_menor_Local[1] = menorConc;
   //retorna o maior e menor elemento do bloco da thread
   pthread_exit((void *) maior_menor_Local); 
}

//fluxo principal
int main(int argc, char *argv[]) {
   double ini, fim; //tomada de tempo
   pthread_t *tid;  //identificadores das threads no sistema
   double *retorno; //valor de retorno das threads

   //recebe e valida os parametros de entrada (dimensao do vetor, numero de threads)
   if(argc < 3) {
       fprintf(stderr, "Digite: %s <dimensao do vetor> <numero threads>\n", argv[0]);
       return 1; 
   }
   dim = atoi(argv[1]);
   nthreads = atoi(argv[2]);
   //aloca o vetor de entrada
   vetor = (double*) malloc(sizeof(double)*dim);
   if(vetor == NULL) {
      fprintf(stderr, "ERRO--malloc\n");
      return 2;
   }
   //preenche o vetor de entrada
   for(long int i=0; i<dim; i++)
      vetor[i] = (double)(rand() % 1000000)+(1.0/(double)((rand() % 1000)+1.0));


   double maiorSeq  = vetor[0]; //maior elemento do vetor de entrada - sequencial
   double menorSeq  = vetor[0]; //menor elemento do vetor de entrada - sequencial  
   //acha o maior e o menor elemento do vetor de entrada de forma sequencial
   GET_TIME(ini);
   for(long int i=0; i<dim; i++){
      if (vetor[i] > maiorSeq) maiorSeq = vetor[i];
      if (vetor[i] < menorSeq) menorSeq = vetor[i];  
   }
   GET_TIME(fim);
   printf("Tempo sequencial:  %lf\n", fim-ini);


   double maiorConc  = vetor[0]; //maior elemento do vetor de entrada - concorrente
   double menorConc  = vetor[0]; //menor elemento do vetor de entrada - concorrente
   //acha o maior e o menor elemento do vetor de entrada de forma concorrente
   GET_TIME(ini);
   tid = (pthread_t *) malloc(sizeof(pthread_t) * nthreads);
   if(tid==NULL) {
      fprintf(stderr, "ERRO--malloc\n");
      return 2;
   }
   //criar as threads
   for(long int i=0; i<nthreads; i++) {
      if(pthread_create(tid+i, NULL, tarefa, (void*) i)){
         fprintf(stderr, "ERRO--pthread_create\n");
         return 3;
      }
   }
   //aguardar o termino das threads
   for(long int i=0; i<nthreads; i++) {
      if(pthread_join(*(tid+i), (void**) &retorno)){
         fprintf(stderr, "ERRO--pthread_create\n");
         return 3;
      }
      //maior e menor elemento global
      if (retorno[0] > maiorConc) maiorConc = retorno[0];
      if (retorno[1] < menorConc) menorConc = retorno[1];  

      //libera as areas de memorias alocadas dentro das threads
      free(retorno);
   }
   GET_TIME(fim);
   printf("Tempo concorrente:  %lf\n", fim-ini);

   //exibir os resultados
   printf("Maior seq:  %.12lf\n", maiorSeq);
   printf("Menor seq:  %.12lf\n", menorSeq);
   printf("Maior conc: %.12lf\n", maiorConc);
   printf("Menor conc: %.12lf\n", menorConc);

   //Olhando o vetor (tirar do programa depois)
   /*puts("O vetor é:");
   for(long int i = 0; i<dim; i++){
      printf("%lf ", vetor[i]);
   }
   puts("\n");*/

   //libera as areas de memoria alocadas
   free(vetor);
   free(tid);

   return 0;
}
