/* Este programa recebe o nome de um vendedor, seu salário fixo, o total de vendas
 efetuadas por ele e entrega o total recebido pelo mesmo no final do mês.
*/

#include <stdio.h>

#define COMISSAO 0.15

int main (void){

    char nome [256];
    double salario_fixo, total_vendas, total;
    
    scanf("%s %lf %lf", nome, &salario_fixo, &total_vendas);

    total = total_vendas * COMISSAO + salario_fixo;

    printf("TOTAL = R$ %.2lf\n", total);
    
    return 0;
}