#include <iostream>
#include <cstdlib>//rand e srand
#include <ctime> //time
#include <algorithm>
using namespace std;

int ind_menor(int vet[], int inicio, int fim){
    int menor = inicio;
    for(int i = inicio; i < fim; i++)
        if(vet[i] < vet[menor])
            menor = i;
    return menor;
}

void selection_sort(int vet[], int qtd){
    for(int i = 0; i < qtd; i++)
        std::swap(vet[i], vet[ind_menor(vet, i, qtd)]);
}

int main(){
    int vet[20];
    for(int i = 0; i < 20; i++)
        vet[i] = rand() % 100;
    for(int i = 0; i < 20; i++)
        cout << vet[i] << " " ;
    cout << "\n";






    for(int i = 0; i < 20; i++)
        cout << vet[i] << " " ;
    cout << "\n";
    return 0;
}
