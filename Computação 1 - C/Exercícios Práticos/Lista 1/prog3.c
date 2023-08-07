#include <stdio.h>
#include <math.h>
int main (void){
	float a;

	printf("Entre com um número:");
	scanf("%f", &a);

	if (a > 0){
		printf("raiz quadrada %5.2f\n", sqrt(a));
	}
	else {
		printf("Não é possível calcular a raiz\n");
	}
	return 0;
}