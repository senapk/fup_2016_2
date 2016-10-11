#include <iostream>
#include <fstream>
using namespace std;

struct Produto{
    string nome;
    int qtd;
    float preco;
};

ifstream produtos("../io/produtos.txt");
ofstream caixa("../io/caixa.txt");

void mostrar_prod(Produto prod){
    caixa << "Nome: " << prod.nome << ", qtd: " << prod.qtd;
    caixa <<", preco: " << prod.preco << endl;
}




int main(){

    string lixo;
    int qtd;
    produtos >> qtd;
    produtos.ignore(100, '\n');

    Produto estoque[qtd];

    for(int i = 0; i < qtd; i++){
        getline(produtos, estoque[i].nome, ';');
        produtos >> estoque[i].qtd >> lixo >> estoque[i].preco;
        getline(produtos, lixo);
    }
    produtos.close();

    float total = 0.0;
    for(int i = 0; i < qtd; i++){
        mostrar_prod(estoque[i]);
        total += estoque[i].qtd * estoque[i].preco;
    }
    caixa << "Valor do estoque " << total << endl;
    caixa.close();
    return 0;
}





