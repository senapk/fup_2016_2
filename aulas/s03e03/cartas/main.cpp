#include <iostream>

using namespace std;

int main2()
{
    string nome;
    int idade;
    float peso;

    char opcao = ' ';

    while(opcao != 's' && opcao != 'n'){
        cout << "Voce quer participar da pesquisa(s/n)" << endl;
        cin >> opcao;
        cin.ignore(1000, '\n');
    }

    cout << "Digite seu nome" << endl;
    cin >> nome;
    cout << "Digite sua idade" << endl;
    cin >> idade;
    cout << "digite seu peso" << endl;
    cin >> peso;
    cout << "Voce eh " << nome << " com idade de "
         << idade << endl;

    return 0;
}


















