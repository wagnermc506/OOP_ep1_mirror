#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "../inc/posicao.hpp"

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
            cout << " " << posicao[i][j];
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
11 - Canoa destruída
2 - Submarino
21 - Submarino tomou dano
22 - Submarino destruído
3 - Porta_Avioes
31 - Porta_Avioes atacado, mas com o tiro interceptado
32 - Porta_Avioes destruído
5 - Local já acertado
*/

void Posicao::testar_tiro(int position[][13], int line, int column, string player_name){
    //Se a posição já foi atacada
    if(position[line][column] == 5){
        cout << "Você já atirou neste local" << endl;
    }
    //Se o alvo for uma Canoa
    else if(position[line][column] == 11){
        cout << "Canoa já foi destruída" << endl;
    }
    else if(position[line][column] == 1){
        cout << player_name << " destriu uma Canoa!" << endl;
        position[line][column] = 11;
    }
    //Se o alvo for um Submarino
    else if(position[line][column] == 22){
        cout << "Parte de submarino já destruído" << endl;
    }
    else if(position[line][column] == 21){
        cout << player_name << "destruiu uma parte de um Submarino!" << endl;
        position[line][column] = 22;
    }
    else if(position[line][column] == 2){
        cout << player_name << "Acertou um Submarino!" << endl;
        position[line][column] = 21;
    }
    //Se o alvo for um Porta-Aviões
    else if(position[line][column] == 3 || position[line][column] == 31){
        srand(time(0));
        int sorteio = (rand() % 2);
        if(sorteio == 0){
            cout << player_name << "Destruiu uma parte de um Porta-Aviões!" << endl;
            position[line][column] = 32;
        }
        else if(sorteio == 1){
            cout << "Porta-Avioes encontrado! Mas o tiro foi interceptado" << endl;
            position[line][column] = 31;
        }
    }
    //Se não tiver nada na posição
    else if(position[line][column] == 0){
        cout << player_name << " atirou na água" << endl;
        position[line][column] = 5; 
    }
    cout << endl;
}

bool Posicao::navios_em_jogo(int position[][13]){
    int cont = 0;
    for(int i = 0; i < 13; i++){
        for(int j = 0; j < 13; j++){
            if(position[i][j] == 1 || position[i][j] == 2 || position[i][j] == 21 || position[i][j] == 3 || position[i][j] == 31){
                cont++;
            }
        }
    }
    if(cont > 0){
        return true;
    }
    else{
        return false;
    }
    return true;
}
