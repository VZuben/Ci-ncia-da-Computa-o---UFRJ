#include <stdio.h>

/*Pedro Henrique Figueiredo Von Zuben 119055699*/

int main(){
    
    int i=0;
    char string1[1024], string2[1024];

    fgets(string1,1024, stdin);
    fflush(stdin);                  /* tirar \n no final */
    fgets(string2,1024, stdin);
    fflush(stdin);                  /* tirar \n no final */

    while (string2[i] != 0){
        string1[i] = string2[i];   /* percorre a string origem até encontrar o \0 */
        i++;
    }                              /* não importa a string 2 ser menor q a 1, pois o \0 cortara o restante da 1 */
    string1[i]=0;                  /* o i sai com uma posição a mais que a gente usa pra copiar o \0 */
    
    printf("%s\n", string1);
    
    
    return 0;
}