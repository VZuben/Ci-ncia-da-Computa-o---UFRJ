#Questão 4
def buscaSetor(setor_empresa):
    matriz = []
    resp = "s"
    while resp != "n":
            nome      = input("Entre com o Nome: ")
            matricula = input("Entre com a Matricula: ")
            setor     = input("Entre com o Setor: ")
            telefone  = input("Entre com o Telefone: ")
            matriz.append([nome, matricula, setor, telefone])
            resp      = input("Nova entrada?Sim(s) ou Nao(n)?")
    lista_setor = []
    for i in range(len(matriz)):
        if matriz[i][2] == setor_empresa:
            linha = matriz[i]
            print linha
            del linha[2]
            lista_setor.append(linha)
    if len(lista_setor) == 0:
        print "Nenhum registro encontrado"
        return
    print lista_setor



        
