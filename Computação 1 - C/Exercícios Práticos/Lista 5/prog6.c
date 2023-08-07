#include <stdio.h>

int main(){
    unsigned long long int N[61], termo=0, termo_next=1, soma;
    int T , i, j;

    for (i = 0; i <= 60; ++i){
        N[i] = termo;

        soma = termo + termo_next;
        termo = termo_next;
        termo_next = soma;
    }

    scanf("%d",&T);

    for (i = 0; i < T; i++){
        scanf ("%d", &j);
        printf("Fib(%d) = %llu\n", j, N[j]);
    }
    return 0;
}