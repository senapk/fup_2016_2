import random

def imprimir_mensagem(n_chutes):
    if n_chutes == 4:
        print "Chuck Noris"
    elif n_chutes < 10:
        print "Ninja"
    elif n_chutes < 15:
        print "da pro gasto"
    else:
        print "Muito muito muito lesado"


def imprimir_dica(chute, numero):
    if(chute == numero):
        print "Acertou"
    elif(chute > numero):
        print "Eh menor"
    else:
        print "Eh maior"


def pegar_chute():
    chute = 0
    deu_certo = False
    while(not deu_certo):
        chute = int(input("Digite seu chute: "))
        if(chute < 0 or chute > 100):
            print "Eh de 0 a 100 abestado!"
        else:
            deu_certo = True
    return chute


def main():
    n_chutes = 0;
    numero = random.randint(0, 100)
    chute = -1
    while(chute != numero):
        n_chutes += 1
        chute = pegar_chute()
        imprimir_dica(chute, numero)
    imprimir_mensagem(n_chutes)


main()
