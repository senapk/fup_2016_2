#include <iostream>

using namespace std;

int main(){
    int qtd = 6;
    int vet[qtd];
    for(int i = 0; i < qtd; i++)
        cin >> vet[i];

    for(int i = 0; i < qtd - 2; i++){
        for(int j = i + 1; j < qtd - 1; j++){
            for(int k = j + 1; k < qtd; k++)
                if(vet[i] + vet[j] + vet[k] == 15){
                    cout << vet[i] << vet[j] << vet[k] << endl;
                }
        }
    }
    return 0;
}
