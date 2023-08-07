#include <stdio.h>

int main (void){
    int T, i,  PA, PB, ANOS=0;
    double G1, G2;

    scanf("%d",&T);

    for (i = 1; i <= T; i++){
        scanf("%d %d %lf %lf",&PA, &PB, &G1, &G2);
        ANOS = 0;
        while (PA <= PB){
            PA += PA * (G1 /100);
            PB += PB * (G2 /100);
            ANOS++;
            if (ANOS > 100){
                printf("Mais de 1 seculo\n");
                break;
            }
        }
        if (ANOS <= 100){
            printf("%d anos.\n", ANOS);
        }
    }
    return 0;
}