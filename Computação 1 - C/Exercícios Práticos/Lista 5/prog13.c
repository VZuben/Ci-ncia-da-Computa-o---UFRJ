#include <stdio.h>
#include <string.h>

int main(){
    char A[1001], B[1001];
    int  N, i, j, k, flag;

    scanf ("%d", &N);
    for (i = 0; i < N; i++){
        flag = 0;
        scanf("%s %s", A, B);
        for (j = strlen(A) - 1, k = strlen(B) - 1; k >= 0; j--, k--){
            if (A[j] != B[k]){
                printf("nao encaixa\n");
                flag = 1;
                break;
            }
        }
        if (flag == 0) printf("encaixa\n");
    }
    return 0;
}