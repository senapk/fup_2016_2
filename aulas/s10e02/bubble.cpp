#include <iostream>
#include <cstdlib>//rand e srand
#include <ctime> //time

using namespace std;

const int MAX = 100;

struct Vetor{
    int vet[MAX];
    int qtd;
};

int ind_menor(Vetor &vetor){
	int ind_min = 0;//indice do primeiro elemento
    for(int i = 1; i < vetor.qtd; i++){
        if(vetor.vet[i] < vetor.vet[ind_min])
            ind_min = i;
    }
    return ind_min;
}

Vetor pegar_posicoes(Vetor &vetor, int valor){
    Vetor posicoes;
    posicoes.qtd = 0;
    for(int i = 0; i < vetor.qtd; i++){
        if(vetor.vet[i] == valor){
            posicoes.vet[posicoes.qtd] = i;
            posicoes.qtd++;
        }
    }
    return posicoes;
}
/*
vector<int> pegar_posicoes(vector<int> vetor, int valor){
    vector<int> posicoes;
    for(int i = 0; i < vetor.size(); i++){
        if(vetor[i] == valor){
            posicoes.push_back(i);
        }
    }
    return posicoes;
}
*/

int main(){
    srand(time(NULL));
    int lim = 10;
    Vetor vetor;
    vetor.qtd = 20;
    for(int i = 0; i < vetor.qtd; i++)
        vetor.vet[i] = rand() % lim;

    for(int i = 0; i < vetor.qtd; i++){
        cout << vetor.vet[i] << " ";
    }
    cout << endl;

    int ind_min = ind_menor(vetor);
    Vetor posicoes = pegar_posicoes(vetor, vetor.vet[ind_min]);
    for(int i = 0; i < posicoes.qtd; i++){
        cout << posicoes.vet[i] << " ";
    }

    cout << endl;


    return 0;
}







