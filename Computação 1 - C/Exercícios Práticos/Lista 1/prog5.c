#include <stdio.h>
int main (void){
	float a,b;
	
	printf("Entre com o primeiro número: ");
	scanf("%f", &a);
	printf("Entre com o segundo valor: ");
	scanf("%f", &b);
	if (a==b) printf("O números são iguais\n");
    if (a>b){
            printf("Os números são diferentes\n");
            printf("%5.2f > %5.2f", a, b);
    }
    if (b>a){
            printf("Os números são diferentes\n");
            printf("%5.2f > %5.2f", b, a);
    }
    
    return 0;
}