#include <stdio.h>

typedef struct _PESSOA {
    char nome[30], sexo;
    int idade;
} PESSOA;


int main(){
    int i, j, *pi, *pj;

    pj = &*&j;
    *pj = &j;
    pi = &i;
    i = *&*&j;
    i = (*pi)+++*pj;

    return 0;
}
