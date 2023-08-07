#include <stdio.h>

void Converter (int numeroBase10 ,int numeroBase2[32]);

int main (int argc, char * argv[])
{
    int nb10, nb2[32], i, teste = 1;

    while (1)
    {
        scanf("%d", &nb10);
        if (nb10 < 0) break;

        /*
        * Como a funcao e void nao ha valor retornado
        * e portanto nao posso atribuir a nenhuma variavel
        */

        Converter(nb10, nb2);

        printf("Teste % d\n", teste++) ;
        printf("%d\n", nb10);

     for (i=0; i < 32; i++){
        printf("%d ", *(nb2 + i));
    }
        
        printf ("\n\n");
    }
    return 0;
}


void Converter(int numeroBase10, int numeroBase2[32])
{
    int i=0;

    for (i=0; i < 32; i++){
        *(numeroBase2 + i) = 0;
    }

    i = 31;

    while (numeroBase10 != 0){
        *(numeroBase2 + i) = numeroBase10 % 2;
        i--;
        numeroBase10 = numeroBase10 / 2;
    }

}