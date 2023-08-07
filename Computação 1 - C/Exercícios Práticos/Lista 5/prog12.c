#include <stdio.h>

int main(){
    int i, j, k=12;
    float M[12][12], s = 0;
    char O;

    O = getchar();

    for (i = 0; i < 12; i++){
        for (j = 0; j < 12; j++){
            scanf("%f", &M[i][j]);
        }
    }

    for (i = 0; i < 12; i++){

        if (i < 6) k -= 1;
        if (i > 6) k += 1;

        for (j = 0; j < 12; j++){
            if (j > k){
                s = s + M[i][j];
            }
        }
    }

    if (O == 'S') printf("%.1f\n", s);
    else if (O =='M') printf("%.1f\n", s/30);
    return 0;
}