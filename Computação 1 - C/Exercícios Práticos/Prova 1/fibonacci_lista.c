 #include <stdio.h>
 
 void fibonacci(int termo_N, unsigned long long int N[]){
    unsigned long long int termo=0, termo_next=1, soma;
    int i;

    for (i = 0; i <= 60; i++){
        N[i] = termo;

        soma = termo + termo_next;
        termo = termo_next;
        termo_next = soma;
    }
}

int main(){
    unsigned long long int N[61];
    int termo_N, i;

    scanf("%d", &termo_N);
    fibonacci(termo_N, N);

    for (i = 0; i <= termo_N; i++){
        printf("Fib(%d) = %llu\n", i, N[i]);
    }

    return 0;
}