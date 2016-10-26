#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;
const int linhas = 10;
const int colunas = 10;

bool existe(int lin, int col){
    if(lin < 0 || lin >= linhas)
        return false;
    if(col < 0 || col >= colunas)
        return false;
    return true;
}

int somadosnove(int mat[linhas][colunas], int lin, int col){
    int total = 0;
    for(int l = lin - 1; l <= lin + 1; l++)
        for(int c = col - 1; c <= col + 1; c++)
            if(existe(l, c))
                total += mat[l][c];
    return total;
}

int main(){
    srand(time(NULL));

    int mat[linhas][colunas];

    int minas[linhas][colunas];

    int num_minas = 10;

    for(int l = 0; l < linhas; l++)
        for(int c = 0; c < colunas; c++){
            mat[l][c] = 0;
            minas[l][c] = 0;
        }

    for(int i = 0; i < num_minas; i++)
        mat[rand() % linhas][rand() % colunas] = 1;


    for(int l = 0; l < linhas; l++)
        for(int c = 0; c < colunas; c++)
            minas[l][c] = somadosnove(mat, l, c);


    for(int l = 0; l < linhas; l++){
        for(int c = 0; c < colunas; c++)
            cout << mat[l][c] << " ";
        cout << endl;
    }

    cout << "------------------\n";
    for(int l = 0; l < linhas; l++){
        for(int c = 0; c < colunas; c++)
            cout << minas[l][c] << " ";
        cout << endl;
    }


    return 0;
}




