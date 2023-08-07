#include <stdio.h>

int produto(int x, int y){
    if (x < 0 && y < 0){
        return produto(-x, -y);
    }
    else if (x < y){
        return produto (y, x);
    }
    else if (y < 0){
        return -x + produto(x,y+1);
    }
    else if (y > 0){
        return x + produto(x,y-1);
    }
    else return 0;
}

int main(){
    int x, y;

    printf("Digite dois numeros a serem multiplicados.\n");
    scanf("%d %d", &x, &y);

    printf("O produto entre %d e %d eh %d.\n", x, y, produto(x,y));

    return 0;
}