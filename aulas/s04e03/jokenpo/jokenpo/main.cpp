#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;

const int PEDRA = 0;
const int PAPEL = 1;
const int TESOURA = 2;

const int JOGADOR = 0;
const int MAQUINA = 1;
const int EMPATE  = 2;

struct Placar{
    int n_vit {0};
    int n_emp {0};
    int n_der = 0;
};

void mostrar_placar(Placar placar){
    cout << "Vit " << placar.n_vit << endl;
    cout << "Emp " << placar.n_emp << endl;
    cout << "Der " << placar.n_der << endl;
}

void atualizar_placar(Placar &placar, int resultado){
    if(resultado == JOGADOR)
        placar.n_vit++;
    else if(resultado == MAQUINA)
        placar.n_der++;
    else
     placar.n_emp++;
}

vector<string> nome_resultado {"Jogador", "Maquina", "Empate"};

string nome_opcao(int op){
    if(op == PEDRA)
        return "Pedra";
    if(op == PAPEL)
        return "Papel";
    if(op == TESOURA)
        return "Tesoura";
    return "VALOR INVALIDO";
}

int pegar_opcao_jogador(){
    int opcao;

    while(true){
        cout << "Escolha 0-Pedra, 1-Papel, 2-Tesoura" << endl;
        cin >> opcao;

        if(!cin){
            cin.clear();
            cin.ignore(1000, '\n');
        }else if(opcao >=0 && opcao <=2)
            break;

    }

    cout << "Voce escolheu " << nome_opcao(opcao) << endl;
    return opcao;
}

int pegar_opcao_maquina(){
    int op_maq = rand() % 3;
    cout << "Maquina escolheu " << nome_opcao(op_maq) << endl;
    return op_maq;
}

//retorna JOGADOR se jogador ganhou
//retorna MAQUINA se maquina ganhou
//retorna EMPATE se empatou
int decidir_ganhador(int op_jog, int op_maq){
    if(op_jog == op_maq)
        return EMPATE;
    if((op_jog == PEDRA && op_maq == TESOURA) ||
       (op_jog == TESOURA && op_maq == PAPEL) ||
       (op_jog == PAPEL && op_maq == PEDRA))
        return JOGADOR;
    return MAQUINA;
}

void mostrar_resultado(int resultado){
    if(resultado == EMPATE)
        cout << "Empate";
    else
        cout << nome_resultado[resultado] << " ganhou" << endl;
}



int main(){
    srand(time(NULL));
    Placar placar;

    while(true){
        mostrar_placar(placar);
        int op_jog = pegar_opcao_jogador();
        int op_maq = pegar_opcao_maquina();
        int ganhador = decidir_ganhador(op_jog, op_maq);
        mostrar_resultado(ganhador);
        atualizar_placar(placar, ganhador);
    }
    cout << "Hello World!" << endl;
    return 0;
}

