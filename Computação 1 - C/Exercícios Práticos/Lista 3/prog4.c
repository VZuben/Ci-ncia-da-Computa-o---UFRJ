/* Este programa recebe 2 números e retorna sua média.
*/

#include <stdio.h>

int main (void){

    double A, B, media;

    scanf("%lf %lf", &A, &B);

    media = ((A * 3.5) + (B * 7.5))/11;

    printf("MEDIA = %.5lf\n", media);
    
    return 0;
}