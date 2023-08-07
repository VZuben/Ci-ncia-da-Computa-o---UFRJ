#include <stdio.h>

int QuantasVezes(char frase[], char c){
    int vezes=0,i;
    for (i = 0; i < 80; i++){
        if (c == frase[i]){
            vezes += 1;
        }
    }
    return vezes;
}

int main() {
    char c;
    char frase[80];
    int vezes;

    gets(frase);

    c = 'a';
    vezes = QuantasVezes(frase, c);
    printf("A vogal '%c' apareceu %d vezes\n", c, vezes);

    c = 'e';
    vezes = QuantasVezes(frase, c);
    printf("A vogal '%c' apareceu %d vezes\n", c, vezes);

    c = 'i';
    vezes = QuantasVezes(frase, c);
    printf("A vogal '%c' apareceu %d vezes\n", c, vezes);

    c = 'o';
    vezes = QuantasVezes(frase, c);
    printf("A vogal '%c' apareceu %d vezes\n", c, vezes);

    c = 'u';
    vezes = QuantasVezes(frase, c);
    printf("A vogal '%c' apareceu %d vezes\n", c, vezes);

    return 0;
}