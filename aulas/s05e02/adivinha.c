#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void imprimir_mensagem(int n_chutes){
    if(n_chutes == 4)
        puts("Chuck Noris");
    else if(n_chutes < 10)
        puts("Ninja");
    else if(n_chutes < 15)
        puts("da pro gasto");
    else
        puts("Muito muito muito lesado");
}

void imprimir_dica(int chute, int numero){
    if(chute == numero)
        puts("Acertou");
    else if(chute > numero)
        puts("Eh menor");
    else
        puts("Eh maior");
}
int pegar_chute() {
    int chute = 0;
    int deu_certo = 0;
    while(!deu_certo){
        puts("Digite seu chute entre 0 e 100");
        scanf("%d", &chute);
        if(chute < 0 || chute > 100){
            puts("Eh de 0 a 100 abestado!");
        }else{
            deu_certo = 1;
        }
    }
    return chute;
}

int main(){
    srand(time(NULL));
    int n_chutes = 0;
    int numero = rand() % 100;
    int chute = -1;
    while(chute != numero){
        n_chutes += 1;
        chute = pegar_chute();
        imprimir_dica(chute, numero);
    }
    imprimir_mensagem(n_chutes);
    return 0;
}
