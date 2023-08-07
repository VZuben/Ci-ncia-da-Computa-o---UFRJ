#include <stdio.h>

#define TAM 81
void ConverteCadeiaParaMaiusculas(char v[]);
int TamanhoCadeia (char v[]);
char ConverteLetraParaMaiuscula(char c);
int EhLetraMinuscula (char c);

int main (void) {
    char frase[TAM];

    gets(frase);
    while (TamanhoCadeia(frase)) {
        ConverteCadeiaParaMaiusculas(frase);
        puts(frase);
        gets(frase);
    }
    return 0;
}
void ConverteCadeiaParaMaiusculas(char v[]) {
    int i;

    for (i=0; i<TamanhoCadeia (v); i++) {
        v[i] = ConverteLetraParaMaiuscula(v[i]);
    }
}
char ConverteLetraParaMaiuscula(char c) {
    if (EhLetraMinuscula(c)){
        c -= 32;
    }
    return c;
}
int EhLetraMinuscula (char c) {
    if (c >= 97 && c <= 122){
        return 1;
    }
    else{
        return 0;
    }
}
int TamanhoCadeia (char v[]) {
    int tamanho=0;
    while (v[tamanho] != 0){
        tamanho++;      
    }
    return tamanho;
}