#include <stdio.h>

int main (void){
    int X, Y;
    float total;

    scanf("%d %d", &X, &Y);

    switch (X) {
        case 1 :
            total = Y * 4.00;
            break;
        case 2 :
            total = Y * 4.50;
            break;
        case 3 :
            total = Y * 5.00;
            break;
        case 4 :
            total = Y * 2.00;
            break;
        case 5 :
            total = Y * 1.50;
            break;
        default:
            printf("Codigo invalido!\n");
            return 1;
    }
    printf("Total: R$ %.2f\n", total);
    return 0;
}