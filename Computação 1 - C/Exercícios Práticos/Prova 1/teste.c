#include <stdio.h>

int main(){
    int i,j,k;
    for (i=0, j=1, k=2; i<k;i++){
        k=k+i%2;
    }


    printf("%d,%d,%d", i, j, k);






    return 0;
}


