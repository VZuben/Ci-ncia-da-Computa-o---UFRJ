#Quest�o 1:
def intercalados(lista1, lista2):
    lista_resultante = []
    for n in range(len(lista1)):
        lista_resultante.append(lista1[n])
        lista_resultante.append(lista2[n])
    return lista_resultante
#(com for)

def intercalados2(lista1, lista2):
    contador = 0
    lista_resultante = []
    while contador < len(lista1):
        lista_resultante.append(lista1[contador])
        lista_resultante.append(lista2[contador])
        contador += 1
    return lista_resultante
#(com while)
#Fun��o que intercala duas listas com o mesmo tamanho.


#Quest�o 2:
def dicionario():
    dic = {}
    contador = 0
    while True:
        numero = input("Por favor, insira um numero ")
        if numero == 0:
            break
        contador += 1
        dic[contador] = numero
    print dic
#Fun��o que recebe valores num�ricos e p�e eles num dicion�rio com chaves em ordem crescente.


#Quest�o 3:
def inverte_tupla(tupla):
    lista = []
    for n in range(len(tupla)):
        lista.append(tupla[n])
    lista_invertida = lista[-1::-1]
    return tuple(lista_invertida)
#Fun��o que inverte tuplas


#Quest�o 4:
def ultimos_elementos(lista):
        if len(lista) < 3:
            return lista
        else:
            return lista[-3::]
#Fun��o que retorna os 3 ultimos elementos de uma lista.


#Quest�o 5:
def Bandex6000():
    cardapio = input("Digite o cardapio: ")
    lista_horas = []
    while True:
        horario = input("Digite um horario disponivel ou digite 0 para finalizar: ")
        if horario == 0:
            break
        else:
            lista_horas.append(horario)
    opcao = 0
    while opcao != 4:
        print "[1]: Agendar um bandeijao"
        print "[2]: Ver cardapio"
        print "[3]: Ver horarios"
        print "[4]: Encerrar programa"
        opcao = input("Selecione uma opcao: ")
        if opcao == 1:
            hora = input("Digite a hora desejada: ")
            if hora in lista_horas:
                lista_horas.remove(hora)
                print "Parabens, seu almoco foi agendado"
            else:
                print "Que triste, a hora escolhida nao esta disponivel"
        if opcao == 2:
            print cardapio
        if opcao == 3:
            print lista_horas

    

