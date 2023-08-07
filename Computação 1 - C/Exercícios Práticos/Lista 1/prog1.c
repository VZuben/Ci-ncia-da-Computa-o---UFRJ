#include <stdio.h>
int main (void){
	float m1, m2;

	m1 = (7+8+9)/3;
	m2 = (4+5+6)/3;

	printf("média aritimética dos números 7,8,9=%5.2f\n", m1);
	printf("média aritimética dos números 4,5,6=%5.2f\n", m2);
	printf("soma das duas médias aritiméticas=%5.2f\n", m1 + m2);
	printf("média das médias calculadas=%5.2f\n", (m1 + m2)/2);

	return 0;
}