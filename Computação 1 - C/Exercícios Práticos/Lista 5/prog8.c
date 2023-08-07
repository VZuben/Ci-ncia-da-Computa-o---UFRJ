#include <stdio.h>

int main(){
    int par[5], impar[5], i, j,  number, qntd_par=0, qntd_impar=0;

    for (i = 0; i < 15; i++){
        scanf("%d", &number);
        if (number%2 == 0){
            par[qntd_par] = number;
            qntd_par++;
            if (qntd_par == 5){
                for (j = 0; j < 5; j++){
                    printf("par[%d] = %d\n", j, par[j]);
                    qntd_par = 0;
                }
            }
        }
        else {
            impar[qntd_impar] = number;
            qntd_impar++;
            if (qntd_impar == 5){
                for (j = 0; j < 5; j++){
                    printf("impar[%d] = %d\n", j, impar[j]);
                    qntd_impar = 0;
                }
            }
        }
    }

    for (j = 0; j < qntd_impar; j++){
        printf("impar[%d] = %d\n", j, impar[j]);
    }

  for (j = 0; j < qntd_par; j++){
        printf("par[%d] = %d\n", j, par[j]);
    }

    return 0;
}