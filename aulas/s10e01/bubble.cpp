#include <iostream>
#include <cstdlib>//rand e srand
#include <ctime> //time

using namespace std;

void swap(int &a, int &b){
	int c = a;
	a = b;
	b = c;
}

void bubble(int vet[], int qtd){
	for(; qtd > 1; qtd--)
		for(int j = 0; j < (qtd - 1); j++)
			if(vet[j] > vet[j + 1])
				swap(vet[j], vet[j + 1]);
}

//retorna o indice do menor elemento
int imin(int vet[], int inicio, int qtd){
	int indice_menor = inicio;
	for(int i = inicio; i < qtd ; i++)
		if(vet[i] < vet[indice_menor])
			indice_menor = i;	
	return indice_menor;
}




void selection(int vet[], int qtd){
	for(int i = 0; i < qtd; i++){
		int ind_min = imin(vet, i, qtd);
		std::swap(vet[i], vet[ind_min]);
	}
}




int main(){
	srand(time(NULL));
    const int qtd = 20;
    int vet[qtd];
    for(int i = 0; i < qtd; i++)
		vet[i] = rand() % 100;
	selection(vet, qtd);
	cout << "[ ";
	for(int i = 0; i < qtd; i++)
		cout << vet[i] << " ";
	cout << "]\n";
	return 0;
}
