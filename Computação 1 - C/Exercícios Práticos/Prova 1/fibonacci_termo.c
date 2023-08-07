 #include <stdio.h>
 
 unsigned long long int fibonacci(int termo_N){
    unsigned long long int N[61], termo=0, termo_next=1, soma;
    int i;

    for (i = 0; i <= 60; i++){
        N[i] = termo;

        soma = termo + termo_next;
        termo = termo_next;
        termo_next = soma;
    }
    return N[termo_N];
}

int main(){
    int termo_N;

    scanf("%d", &termo_N);

    printf("Fib(%d) = %llu\n", termo_N, fibonacci(termo_N));
    
    return 0;
}