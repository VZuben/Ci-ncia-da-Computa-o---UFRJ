#include <stdio.h>
 
int main(){
    int N, i, j, k, flag_numero_par, profundidade_linha, profundidade_max, M[101][101];


    while(scanf("%d",&N) && N){

        profundidade_max = N/2;
        flag_numero_par = 0;

        if (N % 2 == 0) flag_numero_par = 1;

        for (i = 0; i < N; i++){
           
            if (i <= (profundidade_max - flag_numero_par))
               profundidade_linha = i + 1;
            else                        
               profundidade_linha = profundidade_max + (profundidade_max - i) + 1 - flag_numero_par;                        


            k = 1;
            
            for (j = 0; j < N; j++){
             
                
                if (j <= N/2) {
       
                    M[i][j] = k; 

                
                    if (k < profundidade_linha) k++;

                } else {
                   
                    M[i][j] = M[i][N - j -1];
                }
            }    
        }
        for (i = 0; i < N; i++){
            for (j = 0; j < N; j++){
                if (j == 0)
                    printf ("%3d", M[i][j]);
                else
                    printf (" %3d", M[i][j]);
            }
        printf("\n");
        }
    printf("\n");
    }
    return 0;
}