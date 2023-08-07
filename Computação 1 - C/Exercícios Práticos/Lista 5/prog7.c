#include <stdio.h>

int main(){
    double N[100], number;
    int i;

    scanf("%lf", &number);

    for (i = 0; i < 100; i++){
        N[i] = number;
        number *= 1.0/2;
    }

    for (i = 0; i < 100; i++) printf("N[%d] = %.4lf\n", i, N[i]);

    return 0;
}