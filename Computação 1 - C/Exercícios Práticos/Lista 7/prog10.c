#include <stdlib.h>
#include <stdio.h>

int main (void) {
    int i, n , *pvetor, trocou, temp, tamanho;
    float media;

    /* Define um valor para n , scanf ou n = */
    scanf("%d", &n);

    /* aloca espaco na memoria */
    pvetor = (int *) malloc (n * sizeof(int));
    if(!pvetor) {
        puts ("Sem memória.");
        return 1;
    }
    
    /* aqui uso pvetor , vamos ler um vetor */
    for (i = 0; i < n; i++) {
        scanf ("%d", pvetor + i);
    }

    /* faco alguma coisa */
    media = 0.0;
    for (i = 0; i < n; i++) {
        media += *(pvetor + i);
    }
    printf ("Media: %f\n", media/n) ;

    do {
        trocou = 0;
        tamanho = n;
        for (i = 0; i < tamanho - 1; i++){
            if (*(pvetor + i) > *(pvetor + i + 1)){
                temp = *(pvetor+ i);
                *(pvetor + i) = *(pvetor + i + 1);
                *(pvetor + i + 1) = temp;
                trocou = 1;
            }
        }
        tamanho--;
    } while (trocou == 1);

    for (i = 0; i < n; i++) {
        printf("Numero[%d]: %d\n", i, *(pvetor + i));
    }

    /* aqui nao preciso mais de pvetor */
    free (pvetor);
    
    return 0;
}