#include <stdio.h>

unsigned long int fat (unsigned long int num ) {
    if (num == 0) 
        return 1;
    else 
        return num * fat ( num -1) ;
    }

int main(){
    printf("%d", fat(4));




    return 0;
}