#include <iostream>
#include <fstream>
#include <sstream>
#include "../inc/posicao.hpp"
#include "../inc/submarino.hpp"

using namespace std;

Posicao::Posicao(){
    //cout << "Matriz posicao criada" << endl;
}

Posicao::~Posicao(){
    //cout << "Matriz posicao destruida" << endl;
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

void Posicao::setar_matriz(int posicao[][13], int line, int column, int tipo, string orientation, int partsNumber){
    for(int i = 0; i < partsNumber; i++){
        if(orientation == "esquerda"){
            posicao[line][column - i] = tipo;
        }
        else if(orientation == "direita"){
            posicao[line][column + i] = tipo;
        }
        else if(orientation == "baixo"){
            posicao[line + i][column] = tipo;
        }
        else if(orientation == "cima"){
            posicao[line - i][column] = tipo;
        }
        else if(orientation == "nada"){
            posicao[line][column] = tipo;
        }
    }
}

/*void Posicao::ler_arquivo(Submarino submarino){
    ifstream readFile;
    readFile.open("../doc/map_1.txt");
    string line, type, orientation;
    int linha, coluna;

    while(getline(readFile, line)){
        if(line[0] == '#' || line.empty()){continue;}

        istringstream file;
        file.str(line);
        file >> linha >> coluna >> type >> orientation;
        submarino.set_line();

    }
    readFile.close();
}*/