#include <stdio.h>
int main (void){
	float taxa,quant_meses,valor_original;
	
	printf("Entre com a taxa do juros: ");
	scanf("%f", &taxa);
	printf("Entre com a quantidade de meses: ");
	scanf("%f", &quant_meses);
    printf("Entre com o valor original: ");
	scanf("%f", &valor_original);
	printf("\n Valor do juros total pelo atraso: %5.2f", taxa * quant_meses * valor_original);
    return 0;
}