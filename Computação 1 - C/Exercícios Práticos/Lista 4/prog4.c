#include <stdio.h>
 
int main (void){
    int a, b, c;

    scanf("%d %d %d", &a, &b, &c);
    if (a>b && b>c){
        printf("%d\n%d\n%d", c, b, a);
        printf("\n\n");
        printf("%d\n%d\n%d\n", a, b, c);
    }
    else if (a>c && c>b){
        printf("%d\n%d\n%d",b, c, a);
        printf("\n\n");
        printf("%d\n%d\n%d\n", a, b, c);
    }
    else if (b>a && a>c){
        printf("%d\n%d\n%d", c, a, b);
        printf("\n\n");
        printf("%d\n%d\n%d\n", a, b, c);
    }
    else if (c>a && a>b){
        printf("%d\n%d\n%d", b, a, c);
        printf("\n\n");
        printf("%d\n%d\n%d\n", a, b, c);
    }
    else if (b>c && c>a){
        printf("%d\n%d\n%d", a, c, b);
        printf("\n\n");
        printf("%d\n%d\n%d\n", a, b, c);
    }
    else if (c>b && b>a){
        printf("%d\n%d\n%d", a, b, c);
        printf("\n\n");
        printf("%d\n%d\n%d\n", a, b, c);
    }
    return 0;
}