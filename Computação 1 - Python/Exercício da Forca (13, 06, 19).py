def forca():
    palavra = input("Jogador 1, entre com a sua palavra!")
    chances = 8
    mostra_antigo = "-" * len(palavra)
    while True:
        letra = input("Jogador 2, digite uma letra!")
        mostra_novo = ""
        acertou = False
        contador = 0
        for l in palavra:
            if l == letra:
                mostra_novo += letra
                acertou = True
            else:
                mostra_novo += mostra_antigo[contador]
            contador += 1
        print "Palavra Atual: " + mostra_novo
        if acertou == False:
            chances -= 1
            print "Voce errou, ainda restam mais " + str(chances) + " chances."
            if chances == 0:
                print "Game Over!"
                break
        elif "-" not in mostra_novo:
            print "You Won!"
            break
        mostra_antigo = mostra_novo   
            
