#include <iostream>
#include <string>
#include <fstream>
#include "../inc/mapa.hpp"
#include "../inc/posicao.hpp"

using namespace std;

int main(){

    Mapa mapa1;

    //Desenhar Mapa
    string lineMain[13], lineSub;
    mapa1.create_lineMain(lineMain);
    lineSub = mapa1.create_lineSub();
    mapa1.show_map(lineMain, lineSub);

    //Setar posições
    Posicao posicionamento1;
    int position[13][13];
    posicionamento1.criar_matriz(position);
    posicionamento1.mostrar_matriz(position);
    int linha, coluna, tipo;
    cin >> linha >> coluna >> tipo;
    linha--;
    coluna--;
    posicionamento1.editar_matriz(position, linha, coluna, tipo);
    posicionamento1.mostrar_matriz(position);
    mapa1.edit_map(lineMain, linha, coluna);
    mapa1.show_map(lineMain, lineSub);

/*    for (int i = 0; i < 13; i++){
        for(int j = 0; j < 13; j++){
            position[i][j] = 0;
        }
    }
    for (int i = 0; i < 13; i++){
        for(int j = 0; j < 13; j++){
            cout << position[i][j] << " ";
            if(j == 12){
                cout << endl;
            }
        }
    }
*/
    return 0;
}
