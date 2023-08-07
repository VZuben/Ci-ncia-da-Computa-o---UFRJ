#include <stdio.h>

int main(){
    int N[10], i, number;

    scanf("%d", &number);

    for (i = 0; i < 10; i++){
        N[i] = number;
        number *= 2;
    }

    for (i = 0; i < 10; i++) printf("N[%d] = %d\n", i, N[i]);

    return 0;
}