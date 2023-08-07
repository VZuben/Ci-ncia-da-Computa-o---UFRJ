/* Este programa recebe 4 números e retorna o produto do primeiro com o segundo 
menos o produto do terceiro com o quarto
*/

#include <stdio.h>

int main (void){

    int A, B, C, D, diferenca;

    scanf("%d %d %d %d", &A, &B, &C, &D);

    diferenca = (A * B - C * D);

    printf("DIFERENCA = %d\n", diferenca);
    
    return 0;
}