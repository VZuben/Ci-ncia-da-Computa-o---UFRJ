#Questão 1
def matriz_elemento(matriz, elemento):
    contador=0
    for i in range(len(matriz)):
        for j in range(len(matriz[0])):
            if elemento == matriz[i][j]:
                contador+=1
    return contador


#Questão 2
def matriz_transposta(matriz):
    transposta = []
    for j in range(len(matriz[0])):
        linha = []
        for i in range(len(matriz)):
            list.append(linha, matriz[i][j])
        list.append(transposta, linha)
    return transposta


#Questão 3        
def matriz_media(matriz):
    soma = 0
    elementos = len(matriz[0]) * len(matriz)
    for i in range(len(matriz)):
        for j in range(len(matriz[0])):
            soma += matriz[i][j]
    return float(soma)/elementos


#Questão 4
def melhor_volta(matriz):
    melhor_tempo = 999
    melhor_corredor = 0
    melhor_volta = 0
    for i in range(len(matriz)):
        for j in range(len(matriz[0])):
            if melhor_tempo > matriz[i][j]:
                melhor_tempo = matriz[i][j]
                melhor_corredor = i + 1
                melhor_volta = j + 1
    return "O melhor corredor e o " + str(melhor_corredor) + "o" + ", o melhor tempo e " + str(melhor_tempo) + " segundos, a melhor volta e a" + str(melhor_volta) + "o"


#Questão 5
def buscarSetor(matriz, setor):
    lista_setor = []
    for i in range(len(matriz)):
        if matriz[i][2] == setor:
            linha = matriz[i]
            del linha[2]
            lista_setor.append(linha)
    if len(lista_setor) == 0:
        return "Nenhum registro encontrado"
    return lista_setor
