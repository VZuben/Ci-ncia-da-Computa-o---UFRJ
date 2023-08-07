#include <stdio.h>
#include <stdlib.h>

int main(){
    unsigned long int n=0;
    char *p;
    while(1){
        p = malloc(n * 1024);
        if (!p){
            printf("Memoria maxima : %lu", (n-1)*1024);
            free(p);
            return 1;
        }
        n++;
        free(p);
    }
    return 0;
}