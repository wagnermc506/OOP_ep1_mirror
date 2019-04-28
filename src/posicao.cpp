#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstdlib>
#include <ctime>
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

/*
Indice de números da matriz
0 - Nada
1 - Canoa
2 - Submarino
3 - Porta_Avioes
4 - Porta_Avioes atacado, mas com o tiro interceptado
5 - Local já acertado
6 - Submarino acertado uma vez
7 - Embarcação/parte de uma embarcação destruída
*/

void Posicao::testar_tiro(int position[][13], int line, int column, string player_name){
    //Se a posição já foi atacada
    if(position[line][column] == 5){
        cout << "Você já atirou neste local" << endl;
    }
    else if(position[line][column] == 7){
        cout << "Embarcação já destruida neste local" << endl;
    }
    //Se o alvo for uma Canoa
    else if(position[line][column] == 1){
        cout << "Destriu uma Canoa!" << endl;
        position[line][column] = 7;
    }
    //Se o alvo for um Submarino
    else if(position[line][column] == 6){
        cout << "Destruiu uma parte de um Submarino!" << endl;
        position[line][column] = 7;
    }
    else if(position[line][column] == 2){
        cout << "Acertou um Submarino!" << endl;
        position[line][column] = 6;
    }
    //Se o alvo for um Porta-Aviões
    else if(position[line][column] == 3 || position[line][column] == 4){
        srand(time(0));
        int sorteio = (rand() % 2);
        if(sorteio == 0){
            cout << "Destruiu uma parte de um Porta-Aviões!" << endl;
            position[line][column] = 7;
        }
        else if(sorteio == 1){
            cout << "Porta-Avioes encontrado! Mas o tiro foi interceptado" << endl;
            position[line][column] = 4;
        }
    }
    //Se não tiver nada na posição
    else if(position[line][column] == 0){
        cout << player_name << " atirou na água" << endl;
        position[line][column] = 5; 
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