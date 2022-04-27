/* Disciplina: Computacao Concorrente */
/* Prof.: Silvana Rossetto */
/* Aluno: Pedro Henrique Figueiredo Von Zuben */
/* DRE: 119055699 */
/* Módulo 1 - Laboratório: 2 */
/* Codigo: Função que  realiza a Multiplicacao de matriz-matriz (considerando apenas matrizes quadradas) */

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<pthread.h>
#include "timer.h"

float *mat_A;      //matriz A de entrada
float *mat_B;      //matriz B de entrada
float *saida_seq;  //Matriz de saida sequencial
float *saida_conc; //Matriz de saida concorrente
int nthreads;      //numero de threads

typedef struct{
   int id;  //identificador do elemento que a thread ira processar
   int dim; //dimensao das estruturas de entrada
} tArgs;

//funcao que as threads executarao (multiplicação matriz-matriz de forma concorrente)
void * tarefa(void *arg) {
   int soma_produto;
   tArgs *args = (tArgs*) arg;
   //printf("Thread %d\n", args->id);
   for(int i=args->id; i<args->dim; i+=nthreads) {
      for(int j=0; j<args->dim; j++) {
         soma_produto=0;
         for(int k=0; k<args->dim; k++){
            soma_produto += mat_A[i*(args->dim)+k] * mat_B[k*(args->dim)+j];
         }
         saida_conc[i*(args->dim)+j] = soma_produto;
      }
   }
   pthread_exit(NULL);
}

//função que calcula a multiplicação matriz-matriz de forma sequencial
void mult_mat_seq(float *mat_A, float *mat_B, float *saida_seq, int dim){
   int soma_produto;
   for(int i=0; i<dim; i++) {
      for(int j=0; j<dim; j++) {
         soma_produto=0;
         for(int k=0; k<dim; k++){
            soma_produto += mat_A[i*dim+k] * mat_B[k*dim+j];
         }
         saida_seq[i*dim+j] = soma_produto;
      }      
   }
}

//função que checa se a saida sequencial é igual a saida concorrente
int corretude(float *saida_seq, float *saida_conc, int dim) {
   for (int i=0; i<dim*dim; i++) {
      if (saida_seq[i] != saida_conc[i]) return 4;
   }
   return 0;
}

//fluxo principal
int main(int argc, char* argv[]) {
   int dim;        //dimensao da matriz de entrada
   pthread_t *tid; //identificadores das threads no sistema
   tArgs *args;    //identificadores locais das threads e dimensao
   double inicio, fim, tempo_seq, tempo_conc;
   srand((unsigned) time(NULL));
   

   //leitura e avaliacao dos parametros de entrada
   if(argc<3) {
      printf("Digite: %s <dimensao da matriz> <numero de threads>\n", argv[0]);
      return 1;
   }
   dim = atoi(argv[1]);
   nthreads = atoi(argv[2]);
   if (nthreads > dim) nthreads=dim;

   //alocacao de memoria para as estruturas de dados
   mat_A = (float *) malloc(sizeof(float) * dim * dim);
   if (mat_A == NULL) {printf("ERRO--malloc\n"); return 2;}
   mat_B = (float *) malloc(sizeof(float) * dim * dim);
   if (mat_B == NULL) {printf("ERRO--malloc\n"); return 2;}
   saida_seq = (float *) malloc(sizeof(float) * dim * dim);
   if (saida_seq == NULL) {printf("ERRO--malloc\n"); return 2;}
   saida_conc = (float *) malloc(sizeof(float) * dim * dim);
   if (saida_conc == NULL) {printf("ERRO--malloc\n"); return 2;}


   //inicializacao das estruturas de dados de entrada e saida
   for(int i=0; i<dim; i++) {
      for(int j=0; j<dim; j++) {
         mat_A[i*dim+j] = rand() % 10000;    //equivalente mat_A[i][j]
         mat_B[i*dim+j] = rand() % 10000;    //equivalente mat_B[i][j]
         saida_seq[i*dim+j]  = 0;            //equivalente saida_seq[i][j]
         saida_conc[i*dim+j] = 0;            //equivalente saida_conc[i][j]
      }
   }

   //multiplicacao da matriz A pelo mattriz B de forma sequencial
   GET_TIME(inicio);
   mult_mat_seq(mat_A, mat_B, saida_seq, dim);
   GET_TIME(fim)   
   tempo_seq = fim - inicio;
   printf("Tempo da multiplicacao sequencial (dimensao %d) (nthreads %d): %lf\n", dim, nthreads, tempo_seq);

   //multiplicacao da matriz A pelo mattriz B de forma concorrente
   GET_TIME(inicio);
   //alocacao das estruturas
   tid = (pthread_t*) malloc(sizeof(pthread_t)*nthreads);
   if(tid==NULL) {puts("ERRO--malloc"); return 2;}
   args = (tArgs*) malloc(sizeof(tArgs)*nthreads);
   if(args==NULL) {puts("ERRO--malloc"); return 2;}
   //criacao das threads
   for(int i=0; i<nthreads; i++) {
      (args+i)->id = i;
      (args+i)->dim = dim;
      if(pthread_create(tid+i, NULL, tarefa, (void*) (args+i))){
         puts("ERRO--pthread_create"); return 3;
      }
   } 
   //espera pelo termino da threads
   for(int i=0; i<nthreads; i++) {
      pthread_join(*(tid+i), NULL);
   }
   GET_TIME(fim)   
   tempo_conc = fim - inicio;
   printf("Tempo da multiplicacao concorrente (dimensao %d) (nthreads %d): %lf\n", dim, nthreads, tempo_conc);

   if (corretude(saida_seq, saida_conc, dim) != 0) printf("As matrizes de saída não são iguais\n");
   else printf("As matrizes de saída são iguais\n");

   printf("Ganho de desempenho com a versão concorrente (aceleração): %lf\n", tempo_seq/tempo_conc);

   //liberacao da memoria
   free(mat_A);
   free(mat_B);
   free(saida_seq);
   free(saida_conc);
   free(args);
   free(tid);

   return 0;
}
