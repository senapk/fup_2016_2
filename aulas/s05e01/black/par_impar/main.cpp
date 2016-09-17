#include <iostream>
#include <vector>
#include <cstdlib>
#include <time.h>
using namespace std;

const int PAR = 0;
const int IMPAR = 1;

bool jogador_ganhou(int opcao_jog, int valor_jog, int valor_maq){
    if((valor_jog + valor_maq) % 2 == opcao_jog)
        return true;
    return false;
}

int pegar_opcao_jogador(){

}

int pegar_opcao_maquina(){

}

int main(){
    srand(time(NULL));

    int opcao;
    int valor_jog;
    int valor_maq;
    cout << "Digite 0 para Par e 1 para impar" << endl;
    cin >> opcao;
    cout << "Digite seu valor" << endl;
    cin >> valor_jog;
    valor_maq = rand() % 6;//jogando com uma mao
    cout << "Maquina escolheu " << valor_maq << endl;
    bool venceu = jogador_ganhou(opcao, valor_jog, valor_maq);
    if(venceu)
        cout << "Voce eh um tartaruga ninja bombado" << endl;
    else
        cout << "Voce joga pior que um xilito cuspido e pisado" << endl;

    return 0;
}
