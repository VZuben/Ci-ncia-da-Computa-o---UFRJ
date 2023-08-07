#include <stdio.h>

void decriptografa (char frase[]){
    int i;
    for (i = 0; i < 80; i++){
        if (frase[i] == 'a' || frase[i] == 'A'){
            frase[i] += 25;
        }
        else if ((frase[i] >= 'A' && frase[i] <= 'Z') || (frase[i] >= 'a' && frase[i] <= 'z')){
            frase[i] -= 1;
        }
    }
}

int main (){
    char frase[80];
    fgets(frase, 80, stdin);

    decriptografa (frase);
    printf("A frase decriptografada eh: %s", frase);

    return 0;
}