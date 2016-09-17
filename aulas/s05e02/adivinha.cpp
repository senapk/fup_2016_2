#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void imprimir_mensagem(int n_chutes){
    if(n_chutes == 4)
        cout << "Chuck Noris" << endl;
    else if(n_chutes < 10)
        cout << "Ninja" << endl;
    else if(n_chutes < 15)
        cout << "da pro gasto" << endl;
    else
        cout << "Muito muito muito lesado" << endl;
}

void imprimir_dica(int chute, int numero){
    if(chute == numero)
        cout << "Acertou" << endl;
    else if(chute > numero)
        cout << "Eh menor" << endl;
    else
        cout << "Eh maior" << endl;
}
int pegar_chute() {
    int chute = 0;
    bool deu_certo = false;
    while(!deu_certo){
        cout << "Digite seu chute" << endl;
        cin >> chute;
        if(!cin){
            cin.clear();//desquebra a entrada que quebrou
            cin.ignore(1000, '\n');//limpa o que estava escrito
        }
        else if(chute < 0 || chute > 100){
            cout << "Eh de 0 a 100 abestado!" << endl;
        }else{
            deu_certo = true;
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
