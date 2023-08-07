#include <stdio.h>

int main(){
    int C, i, j;
    float M[12][12], s = 0;
    char T;

    scanf("%d", &C); getchar();

    T = getchar();

    for (i = 0; i < 12; i++){
        for (j = 0; j < 12; j++){
            scanf("%f", &M[i][j]);
        }
    }

    for (i = 0; i < 12; i++){
        s += M[i][C];
    }

    if (T == 'S') printf("%.1f\n", s);
    else if (T =='M') printf("%.1f\n", s/12);

    return 0;
}