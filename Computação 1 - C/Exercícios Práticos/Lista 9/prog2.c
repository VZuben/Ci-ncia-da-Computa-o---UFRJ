#include <stdio.h>

int mdc(int x, int y){
    if (x < 0 && y < 0){
        return mdc(-x, -y);
    }
    else if (x < y){
        return mdc(y, x);
    }
    else if (y < 0){
        return mdc(x, -y);
    }
    else if (x % y != 0){
        return mdc(y, x % y);
    }
    else{
        return y;
    }
}

int main(){
    int x, y;

    printf("Digite dois numeros a serem tirados seu MDC\n");
    scanf("%d %d", &x, &y);

    if (y == 0){
        printf("O mdc entre %d e %d eh %d\n", x, y, x);
        return 1;
    }

    if (x == 0){
        printf("O mdc entre %d e %d eh %d\n", x, y, y);
        return 2;
    }
    
    printf("O mdc entre %d e %d eh %d\n", x, y, mdc(x, y));

    return 0;
}