#include <stdio.h>

int main (void){
    int i, N, a, b, c;

    a = 0;
    b = 1;

    scanf("%d", &N);

    for (i = 1; i <= N; ++i) {
        printf("%d", a);
        if (i == N) {
            printf("\n");
            break;
        }
        printf(" ");
        c = a + b;
        a = b;
        b = c;
    }
    return 0;
}