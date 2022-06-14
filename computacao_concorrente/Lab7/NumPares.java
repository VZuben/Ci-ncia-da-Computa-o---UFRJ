/* Disciplina: Computacao Concorrente */
/* Prof.: Silvana Rossetto */
/* Aluno: Pedro Henrique Figueiredo Von Zuben */
/* DRE: 119055699 */
/* Módulo 2 - Laboratório: 7 */
/* Codigo: Programa concorrente em Java para encontrar a quantidade de numeros pares em um vetor de inteiros */

//classe da estrutura de dados (recurso) compartilhado entre as threads
class VetorInfos {
    private int vetor[];         //vetor de inteiros
    private int numParesConc=0;  //quantidade de números pares no vetor[]
    public int tamVetor;         //tamanho do vetor

    //construtor
    public VetorInfos(int vetor[]) { 
        this.vetor = vetor; 
        this.tamVetor = vetor.length;
    }

    //incrementa o contador numParesConc se o número no vetor[pos] for par
    public synchronized void checaPar(int pos){
        if(vetor[pos]%2==0){
            this.numParesConc++;
        }
    }

    //retorna a quantidade de números pares no vetor[]
    public synchronized int get(){
        return this.numParesConc;
    }
}

//classe que estende Thread e que define a tarefa das threads do programa
class ThreadChecadora extends Thread{
    private int id;                 //identificador da thread
    private int nthreads;           //número de threads
    private int sizeBlock;          //tamanho do bloco
    private VetorInfos vetorInfos;  //objeto compartilhado entre as threads

    //construtor
    public ThreadChecadora(int id, int nthreads, int sizeBlock, VetorInfos vetorInfos){
        this.id = id;
        this.nthreads = nthreads;
        this.sizeBlock = sizeBlock;
        this.vetorInfos = vetorInfos;
    }

    //método main das threads
    public void run(){
        final int start = id*this.sizeBlock; //elemento inicial do bloco da thread
        final int end;                       //elemento final(nao processado) do bloco da thread

        if(this.id == nthreads-1){
            end = this.vetorInfos.tamVetor;  //trata o resto se houver
        }else{
            end = (id+1)*(this.sizeBlock);
        }

        //checa a quantidade de números pares do bloco da thread
        for(int i = start; i<end; i++){
            this.vetorInfos.checaPar(i);
        }
    }
}

//classe da aplicação
class NumPares {
    static final int tamVetor = 1000000;             //tamanho do vetor
    static final int nthreads = 2;                   //número de threads
    static final int sizeBlock = tamVetor/nthreads;  //tamanho do bloco
    private static int numParesSeq = 0;

    public static void main (String[] args) {
        
        //aloca espaço para um vetor de threads
        Thread[] threads = new Thread[nthreads];

        //cria um vetor com cada elemento sendo igual ao seu índice
        int[] vetor = new int[tamVetor];
        for (int i = 0; i < tamVetor; i++){
            vetor[i] = i;
        }

        //cria uma instancia do recurso compartilhado entre as threads
        VetorInfos vetorInfos = new VetorInfos(vetor);
        
        //cria as threads da aplicacao
        for (int i = 0; i < threads.length; i++){
            threads[i] = new ThreadChecadora(i, nthreads, sizeBlock, vetorInfos);
        }

        //inicia as threads
        for (int i=0; i<threads.length; i++){
            threads[i].start();
        }

        //espera pelo termino de todas as threads
        for (int i = 0; i<threads.length; i++){
            try { threads[i].join(); } catch (InterruptedException e) { return; }
        }

        //checa a quantidade de números pares dentro do vetor[] de maneira sequencial
        for(int i = 0; i < tamVetor; i++){
            if(vetor[i]%2==0)
                numParesSeq++;
        }
        
        //teste de corretude
        if (numParesSeq == vetorInfos.get()){
            System.out.println("O teste de corretude passou!");
            System.out.println("Total de numeros pares no vetor = " + vetorInfos.get());
        } else {
            System.out.println("O teste de corritude não passou!\n");
        }
    }
}