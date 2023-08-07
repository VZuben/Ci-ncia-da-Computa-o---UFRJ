#Questão 1:
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
#Função que intercala duas listas com o mesmo tamanho.


#Questão 2:
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
#Função que recebe valores numéricos e põe eles num dicionário com chaves em ordem crescente.


#Questão 3:
def inverte_tupla(tupla):
    lista = []
    for n in range(len(tupla)):
        lista.append(tupla[n])
    lista_invertida = lista[-1::-1]
    return tuple(lista_invertida)
#Função que inverte tuplas


#Questão 4:
def ultimos_elementos(lista):
        if len(lista) < 3:
            return lista
        else:
            return lista[-3::]
#Função que retorna os 3 ultimos elementos de uma lista.
        
    
        
        

