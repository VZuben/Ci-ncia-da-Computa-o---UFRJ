def Acerte_os_Numeros():
    lista = []
    erros = 0
    while True:
        numero = input( "Digite um numero: ")
        if numero < 0:
            break
        list.append(lista,numero)
    while True:
        numero = input( "Adivinhe um numero: ")
        if numero in lista:
            lista.remove(numero)
            if len(lista) == 0:
                print "Parabens, voce venceu!"
                break
            print "Acertou, faltam mais " + str(len(lista)) + " acertos."
        else:
            erros+=1
            if erros == 10:
                print "Acabou suas chances!"
                break
            print "Errou, faltam " + str(10 - erros) + " chances."

            
            
        
