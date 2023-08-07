#include <stdio.h>
int main (void){
	float a,b,c;
	
    printf("Todos os números a seguir precisam ser diferentes, \n");
	printf("Entre com o primeiro número: ");
	scanf("%f", &a);
	printf("Entre com o segundo número: ");
	scanf("%f", &b);
    printf("Entre com o terceiro número: ");
	scanf("%f", &c);
	if (a>b && a>c) printf("O primeiro número é o maior\n");
    if (b>a && b>c) printf("O segundo número é o maior\n");
    if (c>a && c>b) printf("O terceiro número é o maior\n");
    return 0;
}