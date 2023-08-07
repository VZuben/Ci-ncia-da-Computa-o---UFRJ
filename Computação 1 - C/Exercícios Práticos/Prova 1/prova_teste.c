#include <stdio.h>
#include <string.h>

int main(){
    int filme, qnt_ingressos, qnt_meia, i, j, soma_teste, flag_carteira_invalida=0, qnt_bradau, flag_bradau_invalido=0, codigo_bradau[400];
    char carteira_estudante[6], lista_estudante[400][6];

    do {
        printf("Digite o numero de um dos filmes em cartaz:\n");
        printf("Star trek (1), Star wars(2), Tron (3)\n");
        scanf("%d", &filme);
        if (filme > 3 || filme < 1){
            printf("Sala invalida, digite novamente.\n");
        }
    } while (filme > 3 || filme < 1);

    do {
        printf("Digite quantos ingressos deseja comprar.\n");
        scanf("%d", &qnt_ingressos);
        if (qnt_ingressos > 400 || qnt_ingressos < 1){
            printf ("Quantidade invalida, digite novamente.\n");
        }
    } while (qnt_ingressos > 400 || qnt_ingressos < 1);
    
    do {
        printf("Informe a quantidade de ingressos com desconto de meia-entrada.\n");
        scanf("%d", &qnt_meia);
        if (qnt_meia > qnt_ingressos || qnt_meia < 0){
            printf ("Quantidade invalida, digite novamente.\n");
        }
    } while (qnt_meia > qnt_ingressos || qnt_meia < 0);

    for (i = 0; i < qnt_meia; i++){
        do {
            soma_teste = 0;
            fflush(stdin);
            if (flag_carteira_invalida != 1) printf("Digite o codigo de sua carteira de estudante.\n");
            flag_carteira_invalida = 0;
            fgets(carteira_estudante, 6, stdin);
            for (j = 0; j < 4; j++){
                soma_teste += carteira_estudante[j] - 48; /* tabela ASCII*/
            }
            if (soma_teste % 10 != carteira_estudante[4] - 48 && carteira_estudante[0] != '0'){
                printf("Numero invalido, digite novamente ou digite 0 para cancelar.\n");
                flag_carteira_invalida = 1;
            } else {
                for (j = 0; j < qnt_meia; j++){
                    if (strncmp(carteira_estudante, lista_estudante[j], 5) == 0){
                        printf("Carteira repetida, digite novamente ou digite 0 para cancelar.\n");
                        flag_carteira_invalida = 1;
                    }
                }
                strcpy(lista_estudante[i], carteira_estudante);
            }
            if (carteira_estudante[0] == '0') {
                qnt_meia--;
                i--;
            }
        } while(flag_carteira_invalida == 1);
    }

    do {
        printf("Informe a quantidade de ingressos com desconto de cliente Bradau.\n");
        scanf("%d", &qnt_bradau);
        if (qnt_bradau > qnt_ingressos || qnt_bradau < 0){
            printf ("Quantidade invalida, digite novamente.\n");
        }
    } while (qnt_bradau > qnt_ingressos || qnt_bradau < 0);

    for (i = 0; i < qnt_bradau; i++){
        do {
            fflush(stdin);
            if (flag_bradau_invalido != 1) printf("Digite o codigo de cliente bradau.\n");
            flag_bradau_invalido = 0;
            scanf("%d", &codigo_bradau[i]);
            if (codigo_bradau[i] < 0 || codigo_bradau[i] % 237 != 0 || codigo_bradau[i] % 341 != 0){
                printf("codigo invalido, digite novamente ou digite 0 para cancelar.\n");
                flag_bradau_invalido = 1;
            } else{ 
                for (j = 0; j < qnt_bradau; j++){
                    if (codigo_bradau[i] == codigo_bradau[j] && i != j){
                        printf("Codigo bradau repetido, digite novamente ou digite 0 para cancelar.\n");
                        flag_bradau_invalido = 1;
                    }
                }
            }

            if (codigo_bradau[i] == 0) {
                qnt_bradau--;
                i--;
            }
        } while(flag_bradau_invalido == 1);
    }

































    return 0;
}