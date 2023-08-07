/* Este programa recebe 2 números e retorna seu produto.
*/

#include <stdio.h>

int main (void){

    int a, b, prod;

    scanf("%d %d", &a, &b);

    prod = a * b;

    printf("PROD = %d\n", prod);
    
    return 0;
}