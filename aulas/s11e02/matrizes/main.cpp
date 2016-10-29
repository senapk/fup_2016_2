#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;
const int LINHAS = 10;
const int COLUNAS = 10;

struct Par{
    int l, c;
};

Par find(int mat[LINHAS][COLUNAS], int valor){
    for(int l = 0; l < LINHAS; l++)
        for(int c = 0; c < COLUNAS; c++)
            if(mat[l][c] == valor){
                Par par;
                par.l = l;
                par.c = c;
                return par;
            }
    return Par{-1, -1};
}

void zerar(int mat[LINHAS][COLUNAS]){
    for(int l = 0; l < LINHAS; l++){
        for(int c = 0; c < COLUNAS; c++){
            mat[l][c] = 0;
        }
    }
}

void mostrar(int mat[LINHAS][COLUNAS]){
    for(int l = 0; l < LINHAS; l++){
        for(int c = 0; c < COLUNAS; c++){
            cout << mat[l][c] << " ";
        }
        cout << endl;
    }
    for(int c = 0; c < COLUNAS; c++){
        cout << "##";
    }
    cout << endl;
}

int contar(int mat[LINHAS][COLUNAS], int valor){
    int cont = 0;
    for(int l = 0; l < LINHAS; l++)
        for(int c = 0; c < COLUNAS; c++)
            if(valor == mat[l][c])
                cont++;
    return cont;
}

void random(int mat[LINHAS][COLUNAS], int limite){
    for(int l = 0; l < LINHAS; l++)
        for(int c = 0; c < COLUNAS; c++)
           mat[l][c] = rand() % limite;
}

int somar(int mat[LINHAS][COLUNAS]){
    int somatorio = 0;
    for(int l = 0; l < LINHAS; l++)
        for(int c = 0; c < COLUNAS; c++)
           somatorio += mat[l][c];
    return somatorio;
}

bool esta_dentro(int lin, int col){
    if(lin < 0 || lin >= LINHAS)
        return false;
    if(col < 0 || col >= COLUNAS)
        return false;
    return true;
}

void contaminar(int mat[LINHAS][COLUNAS], int linha, int col){
    for(int l = linha - 1; l <= linha + 1; l++)
        for(int c = col - 1; c <= col + 1; c++)
            if(esta_dentro(l, c))
                mat[l][c] = 1;
}

void atualizar(int mat[LINHAS][COLUNAS]){
    int nova[LINHAS][COLUNAS];
    zerar(nova);
    for(int l = 0; l < LINHAS; l++)
        for(int c = 0; c < COLUNAS; c++)
            if(mat[l][c] == 1)
                contaminar(nova, l, c);
    for(int l = 0; l < LINHAS; l++)
        for(int c = 0; c < COLUNAS; c++)
            mat[l][c] = nova[l][c];
}

void inicializacao(int mat[LINHAS][COLUNAS], int num_doentes){
    for(int l = 0; l < num_doentes; l++)
        mat[rand() % LINHAS][rand() % COLUNAS] = 1;

}

int main(){
    srand(time(NULL));
    int mat[LINHAS][COLUNAS];
    int cont = 0;
    int num_doentes = 3;
    zerar(mat);
    inicializacao(mat, num_doentes);
    mostrar(mat);
    while (find(mat, 0).l != -1){
        cont++;
        atualizar(mat);
        mostrar(mat);
    }

    cout << "Os individuos sobreviveram " << cont << " geracoes" << endl;


    return 0;
}




