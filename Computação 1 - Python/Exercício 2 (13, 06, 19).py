def estatistica_dado():
    dic = {}
    contador = 0
    for i in range(0, 15):
        valor = input("Valor da Face: ")
        if valor not in dic:
            dic[valor] = 1
        else:
            dic[valor] += 1
    for key in dic:
        if dic[key] > 1:
            contador +=1
    return contador
    
