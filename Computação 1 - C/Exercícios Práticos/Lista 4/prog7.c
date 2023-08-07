#include <stdio.h>

int main (void){
    int N, i;
    
    scanf("%d",&N);

    if (N<10000){
        for (i = 2; i < 10000; i++) {
                if((i%N) == 2){
                    printf("%d\n",i);
                }
        }
    }
    else{
       printf("Numero errado\n");
    }
    return 0;
}