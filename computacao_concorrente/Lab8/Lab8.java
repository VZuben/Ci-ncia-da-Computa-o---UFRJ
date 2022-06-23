/* Disciplina: Computacao Concorrente */
/* Prof.: Silvana Rossetto */
/* Aluno: Pedro Henrique Figueiredo Von Zuben */
/* DRE: 119055699 */
/* Módulo 2 - Laboratório: 8 */
/* Codigo: Leitores e escritores usando monitores em Java */
/* -------------------------------------------------------------------*/



// Classe que contém a variável inteira (recurso compartilhado entre as threads) e os métodos relacionados a ela.
class Numero {
	private int numero;          // Recurso compartilhado entre as threads
	private boolean corretudePy; // Variável que controla se a impressão do log do programa vai ser .py ou não

	// Construtor
	Numero(boolean corretudePy) {
	  this.numero = 0; 
    	  this.corretudePy = corretudePy;
	}
	
	// Retorna o valor atual do número inteiro
	public int get() {
	  return this.numero;
	}
	
	// Atribui um valor ao número inteiro
	public void set(int n) {
	  this.numero = n;
	}
	
        // Imprime o valor atual do número inteiro
        public void imprimeNumero() {
          if(!corretudePy) System.out.println("Numero atual = " + this.numero);              
        }

	// Imprime se o valor atual do número inteiro é par ou ímpar
	public void ehPar() {
          if (this.numero % 2 == 0) {
              if(!corretudePy) System.out.printf("Numero atual eh par\n");
          } else {
              if(!corretudePy) System.out.printf("Numero atual eh impar\n");
          } 
	}
}

//--------------------------------------------------------

// Monitor que implementa a logica do padrao leitores/escritores
// Todos os métodos contidos nesta classe indicam se a thread 
// que está lendo ou escrevendo é uma thread leitora/escritora
// caso o programa não esteja configurado para imprimir um log .py
class LE {
  private int leit, escr;  
  private boolean corretudePy; // Variável que controla se a impressão do log do programa vai ser .py ou não
  
  // Construtor
  LE(boolean corretudePy) { 
      this.leit = 0; //leitores lendo (0 ou mais)
      this.escr = 0; //escritor escrevendo (0 ou 1)
      this.corretudePy = corretudePy;
  } 
  
  // Entrada para leitores
  public synchronized void EntraLeitor (int id, boolean leitorEscritor) {
    try { 
      while (this.escr > 0) {
          System.out.println ((leitorEscritor && !this.corretudePy ? "le.leitorEscritorBloqueado("+id+")" : "le.leitorBloqueado("+id+")"));
          wait();  //bloqueia pela condicao logica da aplicacao 
      }
      this.leit++;  //registra que ha mais um leitor lendo
      System.out.println ((leitorEscritor && !this.corretudePy ? "le.leitorEscritorLendo("+id+")" : "le.leitorLendo("+id+")"));       
    } catch (InterruptedException e) { }
  }
  
  // Saida para leitores
  public synchronized void SaiLeitor (int id, boolean leitorEscritor) {
      this.leit--; //registra que um leitor saiu
      if (this.leit == 0) 
            this.notify(); //libera escritor (caso exista escritor bloqueado)
      System.out.println ((leitorEscritor && !this.corretudePy ? "le.leitorEscritorSaindo("+id+")" : "le.leitorSaindo("+id+")")); 
  }
  
  // Entrada para escritores
  public synchronized void EntraEscritor (int id, boolean leitorEscritor) {
    try { 
      while ((this.leit > 0) || (this.escr > 0)) {
          System.out.println ((leitorEscritor && !this.corretudePy ? "le.leitorEscritorBloqueado("+id+")" : "le.escritorBloqueado("+id+")"));
          wait();  //bloqueia pela condicao logica da aplicacao 
      }
      this.escr++; //registra que ha um escritor escrevendo
      System.out.println ((leitorEscritor && !this.corretudePy ? "le.leitorEscritorEscrevendo("+id+")" : "le.escritorEscrevendo("+id+")"));
    } catch (InterruptedException e) { }
  }
  
  // Saida para escritores
  public synchronized void SaiEscritor (int id, boolean leitorEscritor) {
      this.escr--; //registra que o escritor saiu
      notifyAll(); //libera leitores e escritores (caso existam leitores ou escritores bloqueados)
      System.out.println ((leitorEscritor && !this.corretudePy ? "le.leitorEscritorSaindo("+id+")" : "le.escritorSaindo("+id+")"));
  }
}
  
  


//-----------------------------------------------------------------------------------------------------




  // Representa a thread escritora
  // Modifica o valor do número inteiro (recurso compartilhado) incrementando seu valor de 1 (operação de escrita).
  class T1 extends Thread {
    int id; //identificador da thread
    int delay; //atraso bobo...
    LE monitor; //objeto monitor para coordenar a lógica de execução das threads
    Numero numero; //recurso compartilhado
  
    // Construtor
    T1 (int id, int delayTime, LE m, Numero numero) {
      this.id = id;
      this.delay = delayTime;
      this.monitor = m;
      this.numero = numero;
    }
  
    // Método executado pela thread
    public void run () {
      try {
        for (;;) {
          this.monitor.EntraEscritor(this.id, false); 
          numero.set(numero.get()+1); //numero = numero + 1
          this.monitor.SaiEscritor(this.id, false); 
          sleep(this.delay); //atraso bobo...
        }
      } catch (InterruptedException e) { return; }
    }
  }
  
  //--------------------------------------------------------

  // Representa a thread leitora
  // Lê o valor de número inteiro (recurso compartilhado) e o imprime na tela indicando se é um valor par ou ímpar (operação de leitura)
  class T2 extends Thread {
    int id; //identificador da thread
    int delay; //atraso bobo
    LE monitor; //objeto monitor para coordenar a lógica de execução das threads
    Numero numero; //recurso compartilhado
  
    // Construtor
    T2 (int id, int delayTime, LE m, Numero numero) {
      this.id = id;
      this.delay = delayTime;
      this.monitor = m;
      this.numero = numero;
    }
  
    // Método executado pela thread
    public void run () {
      try {
        for (;;) {
          this.monitor.EntraLeitor(this.id, false);
          numero.imprimeNumero(); //imprime o valor atual do número inteiro
          numero.ehPar(); //imprime se o valor atual do número inteiro é par ou ímpar
          this.monitor.SaiLeitor(this.id, false);
          sleep(this.delay); //atraso bobo...
        }
      } catch (InterruptedException e) { return; }
    }
  }

  //--------------------------------------------------------

  // Representa a thread leitora/escritora
  // Lê o valor do número inteiro (recurso compartilhado) e o imprime na tela (operação de leitura);
  // Faz um processamento "bobo" qualquer (mais significativo);
  // E depois modifica o valor do número inteiro escrevendo o valor do seu identificador de thread (operação de escrita);
  class T3 extends Thread {
    int id; //identificador da thread
    int delay; //atraso bobo...
    LE monitor; //objeto monitor para coordenar a lógica de execução das threads
    Numero numero; //recurso compartilhado
  
    // Construtor
    T3 (int id, int delayTime, LE m, Numero numero) {
      this.id = id;
      this.delay = delayTime;
      this.monitor = m;
      this.numero = numero;
    }
  
    // Método executado pela thread
    public void run () {
      double j=777777777.7, i;
      try {
        for (;;) {
          this.monitor.EntraLeitor(this.id, true);
          numero.imprimeNumero(); //imprime o valor atual do número inteiro
          this.monitor.SaiLeitor(this.id, true);
          sleep(this.delay); //atraso bobo...
          for (i=0; i<100000000; i++) {j=j/2;} //faz um processamento "bobo" qualquer (mais significativo)
          this.monitor.EntraEscritor(this.id, true);
          numero.set(this.id); //numero = id
          this.monitor.SaiEscritor(this.id, true);
          sleep(this.delay); //atraso bobo...
        }
      } catch (InterruptedException e) { return; }
    }
  }

  //--------------------------------------------------------

  // Classe principal
public class Lab8 {
    static final int E = 3;   // Quantidade de threads escritoras
    static final int L = 2;   // Quantidade de threads leitoras
    static final int L_E = 5; // Quantidade de threads leitoras/escritoras
  
    public static void main (String[] args) {

      boolean corretudePy = false;                // Variável que controla se a impressão do log do programa vai ser .py ou não.

      //se escrevermos "corretudePy" como argumento na hora de executar, a impressão do log do programa vai ser .py 
      if(args.length > 0 && args[0].equals("corretudePy")) corretudePy = true;
      
      int i;
      Numero numero = new Numero(corretudePy);    // Número  (objeto compartilhado entre leitores e escritores)
      LE monitor = new LE(corretudePy);           // Monitor (objeto compartilhado entre leitores e escritores)
      T1[] escritoras = new T1[E];                // Threads escritoras
      T2[] leitoras = new T2[L];                  // Threads leitoras
      T3[] leitorasEscritoras = new T3[L_E];      // Threads leitoras/escritoras

      
  
      //inicia o log de saida
      System.out.println ("import verificaLE");
      System.out.println ("le = verificaLE.LE()");
      


      for (i=0; i<E; i++) {
        escritoras[i] = new T1(i+1, (i+1)*500, monitor, numero);
        escritoras[i].start(); 
     }

      for (i=0; i<L; i++) {
         leitoras[i] = new T2(i+1, (i+1)*500, monitor, numero);
         leitoras[i].start(); 
      }

      for (i=0; i<L_E; i++) {
        leitorasEscritoras[i] = new T3(i+1, (i+1)*500, monitor, numero);
        leitorasEscritoras[i].start(); 
     }

    }
}
  
