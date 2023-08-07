#include <stdio.h>

void criptografa (char frase[]){
    int i;
    for (i = 0; i < 80; i++){
        if (frase[i] == 'z' || frase[i] == 'Z'){
            frase[i] -= 25;
        }
        else if ((frase[i] >= 'A' && frase[i] <= 'Z') || (frase[i] >= 'a' && frase[i] <= 'z')){
            frase[i] += 1;
        }
    }
}

int main (){
    char frase[80];
    fgets(frase, 80, stdin);

    criptografa (frase);
    printf("A frase criptografada eh: %s", frase);

    return 0;
}