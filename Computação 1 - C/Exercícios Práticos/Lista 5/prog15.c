#include <stdio.h>
#include <string.h>
 
int main(){
    int N, i, j, k,  right_shift;
    char s[50]; 

    scanf("%d", &N);
 
    for (i = 0; i < N; i++){
        scanf("%s", s);
        scanf("%d", &right_shift);
        for (j = 0; j < strlen(s); j++){
            s[j] -= right_shift;
            if (s[j] < 65) s[j] = s[j] + 26;
        }
        for (k = 0; k < strlen(s); k++){
            printf("%c", s[k]);
        }
    printf("\n");
    }
    return 0;
}