#Exercício 1
######## JOGO DA FORCA #########

def inicio(p):
    return '_ ' * len(p)

def palpitecerto(p,l,s):
    L = str.split(s)
    for i in range(len(L)):
        if p[i] == l:
            L[i] = l       
    return str.join(' ',L)+' '

def main():
    p = str.upper(raw_input('Digite a palavra a ser adivinhada: '))
    s = inicio(p)
    print ' \n '
    c = 8
    while c > 0:
        if not '_' in s:
            break
        print ' '
        print s
        print 'Erros restantes: ' + str(c)
        l = str.upper(raw_input('Escolha uma letra: '))
        if l == 'DESISTIR':
            c = 0
        elif l in p:
            s = palpitecerto(p,l,s)
        else:
            c -= 1
    print ' '
    if c <= 0:
        print 'Você foi enforcado!!!'
        print 'A palavra era: ' + p
    else:
        print s
        print '\n Parabéms!! Você acertou'
    
if __name__ == "__main__":
    main()
