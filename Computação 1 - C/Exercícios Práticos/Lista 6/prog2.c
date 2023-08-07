#include <stdio.h>

long int fat(long int);
long int c (long int n, long int p);

int main (void) {
    long int n, p;
    while (1) {
        scanf("%ld %ld", &n, &p);
        if (n < p) break;
        printf("O valor da combinacao de %ld %ld a %ld vale %ld\n",
            n, p, p, c(n, p));
    }
    return 0;
}
long int fat (long int n) {
    if (n > 0){
        return n * (fat(n-1));
    }
    else {
        return 1;
    }
}
long int c (long int n, long int p){
    return fat(n)/(fat(n-p) * fat(p));
}