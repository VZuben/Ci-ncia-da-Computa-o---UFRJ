/* Este programa recebe o número de um funcionário, seu numero de horas trabalhadas 
e o valor que recebe por hora e retorna o salário desse funcionário junto de seu número.
*/

#include <stdio.h>

int main (void){

    int number, qnt_horas;
    double valor_hora, salary;

    scanf("%d %d %lf", &number, &qnt_horas, &valor_hora);

    salary = qnt_horas * valor_hora;

    printf("NUMBER = %d\n", number);
    printf("SALARY = U$ %.2lf\n", salary);
    
    return 0;
}