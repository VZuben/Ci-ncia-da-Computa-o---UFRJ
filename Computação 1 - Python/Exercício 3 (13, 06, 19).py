######## CAIXA 1 #########
def area_do_trapezio(a, b, c):
    return (float(a) + b) * c / 2

######## CAIXA 2 #########
def quadrados_3(a, b, c):
    return float(a) * a, float(b) * b, float(c) * c

######## CAIXA 3 #########
def media_aritimetica(a, b, c):
    return (float(a) + b + c) / 3

######## CAIXA 4 #########
def soma_range(a, b, c):
    soma = 0
    for i in range(a, b, c):
        soma += float(i)
    return soma

######## CAIXA MAIN #########
def main():
    print "Qual funcao deseja executar?"
    print "[1] Area do Trapezio"
    print "[2] Quadrado de Tres Numeros"
    print "[3] Media Aritimetica entre Tres Numeros"
    print "[4] Soma dos Inteiros em um Intervalo com Variacao"
    print "[5] SAIR"

    escolhaFuncao = input("Resposta: ")

    while escolhaFuncao != 5:
        if escolhaFuncao == 1:
            a = input("Digite um Valor para a Base Menor do Trapezio: ")
            b = input("Digite um Valor para a Base Maior do Trapezio: ")
            c = input("Digite um Valor para a Altura do Trapezio: ")

            print "A Area do Trapezio = %.2f, Base Menor = %.2f, Base Maior = %.2f, Altura = %.2f" % (area_do_trapezio(a, b, c), a, b, c)

        elif escolhaFuncao == 2:
            a = input("Digite um Valor para O Primeiro Quadrado: ")
            b = input("Digite um Valor para O Segundo Quadrado: ")
            c = input("Digite um Valor para O Terceiro Quadrado: ")

            print "Os Quadrados dos Tres Numeros sao Respectivamente %.2f %.2f %.2f" % quadrados_3(a, b, c)
            print "Primeiro = %.2f, Segundo = %.2f, Terceiro = %.2f" % (a, b, c)
        elif escolhaFuncao == 3:
            a = input("Digite um Valor para o Primeiro Numero: ")
            b = input("Digite um Valor para o Segundo Numero: ")
            c = input("Digite um Valor para o Terceiro Numero: ")

            print "O Resultado da Media Aritimetica destes Tres Numeros e %.2f, Primeiro = %.2f, Segundo = %.2f, Terceiro = %.2f" % (media_aritimetica(a, b, c), a, b, c)

        elif escolhaFuncao == 4:
            a = input("Digite um Valor para o Inicio do Intervalo: ")
            b = input("Digite um Valor para o Final do Intervalo: ")
            c = input("Digite um Valor para a variacao do Intervalo: ")

            print "A Soma dos Inteiros neste Intervalo com Variacao e %d" % soma_range(a, b, c)

        else:
            
            print "Opcao invalida!"

        print "Qual funcao deseja executar?"
        print "[1] Area do Trapezio"
        print "[2] Quadrado de Tres Numeros"
        print "[3] Media Aritimetica entre Tres Numeros"
        print "[4] Soma dos Inteiros em um Intervalo com Variacao"
        print "[5] SAIR"

        escolhaFuncao = input("Resposta: ")

if __name__ == "__main__":
	main()
