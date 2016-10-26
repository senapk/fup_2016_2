#include <iostream>
#include <sstream> //stringstream

using namespace std;

int carregar_valores(int argc, char *argv[],
                      float &num1, char &op, float &num2){
    if(argc != 4){
        cerr << "Use o programa com op +-x/ \n"
             << "./calc 5 op 4" << endl;
        for(int i = 0; i < argc; i++)
            cout << argv[i] << endl;
        return 1;
    }


    stringstream arg1(argv[1]);
    arg1 >> num1;
    stringstream arg3(argv[3]);
    arg3 >> num2;
    if(!arg1 || !arg3){
        cerr << "argumento invalido" << endl;
        return 2;
    }

    stringstream (argv[2]) >> op;
    if(!(op == '+' || op == '-' || op == '/' || op == 'x')){
        cerr << "operacao invalida" << endl;
        return 3;
    }

    return 0;
}

float calcular(float num1, char op, float num2){
    if(op == '+')
        return num1 + num2;
    if(op == '-')
        return num1 - num2;
    if(op == 'x')
        return num1 * num2;
    if(op == '/')
        return num1 / num2;
    return 0.0;
}

//contruir uma calculadora utilizando argumentos
//Ex:
//./calc 5 + 4
//Resultado: 9
//Erros: 1 -> paramentros insuficientes
//       2 -> argumento invalido
//       3 -> operacao invalida
int main(int argc, char *argv[]){
    float num1, num2;
    char op;
    int result = carregar_valores(argc, argv, num1, op, num2);
    if(result != 0)
        return result;

    float resultado = calcular(num1, op, num2);

    cout << num1 << " " << op << " " << num2 << " = "
         << resultado << endl;
    return 0;
}




