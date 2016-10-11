#include <iostream>

using namespace std;

//conta quantas vezes 'valor' aparece no 'vetor'
int contar(int vet[], int qtd, int valor){
    int cont = 0;
    for(int i = 0; i < qtd; i++){
        if(vet[i] == valor)
            cont += 1;
    }
    return cont;
}
//retorna a primeira posicao que encontrou o elemento
//retorna -1 se não encontrar o elemento
int find(int vet[], int qtd, int valor){
    for(int i = 0; i < qtd; i++)
        if(vet[i] == valor)
            return i;
    return -1;
}

bool eh_primeira_aparicao(int vet[], int qtd, int ind){
    for(int i = 0; i < ind; i++)
        if(vet[i] == vet[ind])
            return false;
    return true;
}

int main(){
    int qtd;
    cin >> qtd;
    int vet[qtd];
    for(int i = 0; i < qtd; i++)
        cin >> vet[i];
    int cont = 0;
    for(int i = 0; i < qtd; i++)
        if(eh_primeira_aparicao(vet, qtd, i))
            if(contar(vet, qtd, vet[i]) >= 3)
                cout << vet[i] << " ";
    cout << cont;
}

