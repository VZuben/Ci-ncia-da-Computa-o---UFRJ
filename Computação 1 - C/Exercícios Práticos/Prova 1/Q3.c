#include <stdio.h>

/*Pedro Henrique Figueiredo Von Zuben 119055699*/

int main(){
    
    int i=0, posicao=-1;  /*valor quando não encontrado pedido na questão*/
    char string[1024], caracter;

    fgets(string,1024, stdin);
    fflush(stdin);                /* limpa o \n */

    caracter = getchar();
    fflush(stdin);      /* limpa o \n */

    while (string[i] != 0){   /*percorrendo a string até o final*/

        if (string[i] == caracter) { /*achando o caracter, o programa para*/
            posicao = i;
            break;
        }
        i++;
    }

    printf("posicao = %d\n", posicao);
    
    return 0;
}