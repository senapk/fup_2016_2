#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;

struct Gremlin{
    string nome;
    bool eh_do_bem;
    int vida;
    int forca;
};

Gremlin gerar_gremlin(){
    string vogais = "aeiou";
    string consoantes = "bcdfghjklmnpqrstvwxyz";

    Gremlin g;
    g.eh_do_bem = rand() % 2;
    g.vida = rand() % 90 + 10;
    g.forca = rand() % 30 + 20;
    int silabas = rand() % 3 + 1;
    for(int i = 0; i < silabas; i++){
        g.nome += consoantes[rand() % consoantes.size()];
        g.nome += vogais[rand() % vogais.size()];
    }
    return g;
}

void show(Gremlin g){
    cout << g.nome << ", f = " << g.forca << ", v = "
         << g.vida;
    if(g.eh_do_bem)
        cout << " Good" << endl;
    else
        cout << " Bad" << endl;
}

void lutar(Gremlin * one, Gremlin * two){
    cout << "## Lutando " << one->nome << " e " << two->nome << endl;
    if(one->vida > 0)
        two->vida -= one->forca;
    else
        cout << one->nome << " esta morto" << endl;
    if(two->vida > 0)
        one->vida -= two->forca;
    else
        cout << two->nome << " esta morto" << endl;
}

int main(){
    srand(time(NULL));
    vector<Gremlin> soldados;
    for(int i = 0; i < 10; i++)
        soldados.push_back(gerar_gremlin());

    while(soldados.size() > 1){
        for(auto &s : soldados)
            lutar(&s, &soldados[rand() % soldados.size()]);
        for(int i = soldados.size() - 1; i >= 0; i--){
            if(soldados[i].vida <= 0){
                cout << "==Removendo morto " << soldados[i].nome << endl;
                soldados.erase(soldados.begin() + i);
            }
        }
        cout << "--- Terminou Round" << endl;
    }
    cout << "Venceu " << soldados[0].nome << endl;
    return 0;
}










