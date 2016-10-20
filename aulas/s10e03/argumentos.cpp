#include <iostream>
#include <sstream> //stringbuffer
using namespace std;
#include <cmath> // sqrt(valor)

bool eh_primo(int valor){
    for(int num = 2; num <= sqrt(valor); num++)
        if(valor % num == 0)
            return false;
    return true;
}

//./eh_primo 6
int main(int argc, char ** argv){
    if(argc < 2){
        cout << "use o programa como ./eh_primo numero";
        return 0;
    }
    int numero;
    stringstream(argv[1]) >> numero;

    cout << "O numero " << numero;
    if(eh_primo(numero))
        cout << " eh primo!" << endl;
    else
        cout << " nao eh primo!" << endl;
    return 0;
}
