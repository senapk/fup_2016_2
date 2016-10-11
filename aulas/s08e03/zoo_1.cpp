#include <iostream>
using namespace std;
int main(){
    int qtd;
    cin >> qtd;
    int vet[qtd];
    for(int i = 0; i < qtd; i++){
        cin >> vet[i];
    }

    int total = 0;
    for(int i = 0; i < qtd; i++){
        bool eh_repetido = false;
        for(int j = (i - 1); j >= 0; j--){
            if(vet[i] == vet[j]){
                eh_repetido = true;
                break;
            }
        }
        if(!eh_repetido){
            cout << vet[i] << " ";
            total++;
        }
    }
    return 0;
}
