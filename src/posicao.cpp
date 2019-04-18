#include <iostream>
#include <fstream>
#include "../inc/posicao.hpp"

using namespace std;

Posicao::Posicao(){
    cout << "Matriz posicao criada" << endl;
}

Posicao::~Posicao(){
    cout << "Matriz posicao destruida" << endl;
}

void Posicao::criar_matriz(int posicao[][13]){
    for(int i = 0; i < 13; i++){
        for(int j = 0; j < 13; j++){
            posicao[i][j] = 0;
        }
    }
}

void Posicao::mostrar_matriz(int posicao[][13]){
    for(int i = 0; i < 13; i++){
        for(int j = 0; j < 13; j++){
            cout << posicao[i][j];
            if(j == 12){
                cout << endl;
            }
        }
    }
}

void Posicao::editar_matriz(int posicao[][13], int line, int column, int tipo){
    posicao[line][column] = tipo;
}

void Posicao::ler_arquivo(){
    ifstream arquivo;
    arquivo.open("../doc/map_1.txt");
    string line[12];
    i = 0;

    while(getline(arquivo, line[i])){
        if(line[i][0] == '0'){continue;}

        
        i++;
    }

    arquivo.close();
}