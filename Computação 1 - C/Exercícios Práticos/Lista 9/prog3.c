#include <stdio.h>

int resto(int x, int y){
    if (x < y){
        return x;
    }
    else if (x - y >= y){
        return resto(x-y, y);
    }
    else{
        return x - y;
    }
}

int main(){
    int x, y;

    printf("Digite dois numeros a serem divididos para retornar o seu resto.\n");
    scanf("%d %d", &x, &y);

    if (x <= 0 || y <= 0){
        printf("Numero(s) incorreto(s)");
        return 1;
    }

    printf("O resto da divisao entre %d e %d eh %d", x, y, resto(x,y));

    return 0;
}