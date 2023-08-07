#include <stdio.h>
 
int main (void){
    int I, J, contador;

    contador = 0;
    
    for (I = 1, J = 7;; J --){
        if (contador == 3){
            I += 2;
            J += 5;
            contador = 0;
        }
        printf ("I=%d J=%d\n", I, J);
        if (I == 9 && J == 13) break;
        contador++;
    }
    return 0;
}