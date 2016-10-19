#include <iostream>
#include <cstdlib>//rand e srand
#include <ctime> //time
#include <sstream>

using namespace std;

const int MAX = 100;

int ind_menor(int vet[], int qtd){
	int ind_min = 0;//indice do primeiro elemento
    for(int i = 1; i < qtd; i++){
        if(vet[i] < vet[ind_min])
            ind_min = i;
    }
    return ind_min;
}

string pegar_posicoes(int vet[], int qtd, int valor){
	stringstream posicoes;
    for(int i = 0; i < qtd; i++){
        if(vet[i] == valor){
            posicoes << i << " ";
        }
    }
    return posicoes.str();
}

int main(){
    srand(time(NULL));
    int lim = 10;
	int qtd = 20;
    
	int vet[qtd];
    for(int i = 0; i < qtd; i++)
        vet[i] = rand() % lim;

    for(int i = 0; i < qtd; i++){
        cout << vet[i] << " ";
    }
    cout << endl;

    int ind_min = ind_menor(vet, qtd);
    string posicoes = pegar_posicoes(vet, qtd, vet[ind_min]);
    cout << posicoes << endl;

    cout << endl;


    return 0;
}







