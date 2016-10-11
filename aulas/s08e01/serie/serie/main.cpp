//8 8 8 3 3 3 3 9 9 9 9 9 4 4 1 1 1
// numero = 3

//num_atual = 3
//cont = 1
//maior_serie = 3
#include <iostream>

using namespace std;

struct serie{
    int num;
    int qtd;
};

int main(){
    serie maior;
    maior.qtd = 0;
    serie atual;
    int qtd;//qtd de elementos
    int num;//numero que acabei de ler
    cin >> qtd >> num;
    atual.num = num;
    atual.qtd = 1;
    for(int i = 0; i < (qtd - 1); i++){
        cin >> num;
        if(num == atual.num){
            atual.qtd++;
        }else{
            if(atual.qtd > maior.qtd)
                maior = atual;
            atual.num = num;
            atual.qtd = 1;
        }
    }
    if(atual.qtd > maior.qtd)
        maior = atual;

    cout << maior.num << endl;
    cout << maior.qtd << endl;


    return 0;
}

