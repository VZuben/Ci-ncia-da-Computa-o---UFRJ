#include <stdio.h>

int main(){
    int i, j;
    float M[12][12], s = 0;
    char O;

    O = getchar();

    for (i = 0; i < 12; i++){
        for (j = 0; j < 12; j++){
            scanf("%f", &M[i][j]);
        }
    }

    for (i = 0; i < 12; i++){
        for (j = 0; j < 12; j++){
            if (j > i) s += M[i][j];
        }
    }

    if (O == 'S') printf("%.1f\n", s);
    else if (O =='M') printf("%.1f\n", s/66);

    return 0;
}