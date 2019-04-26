#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "../inc/mapa.hpp"
#include "../inc/posicao.hpp"
#include "../inc/canoa.hpp"
#include "../inc/submarino.hpp"
#include "../inc/porta_avioes.hpp"
#include "../inc/player.hpp"

using namespace std;

int main(){

    Mapa mapa1;

    //Desenhar Mapa
    string lineMain[13], lineSub;
    mapa1.create_lineMain(lineMain);
    lineSub = mapa1.create_lineSub();
    //mapa1.show_map(lineMain, lineSub);

    //Setar posições
    int position1[13][13];
    int position2[13][13];
    Posicao posicionamento[2];

    for(int i = 0; i < 2; i++){
        if(i == 0){
            posicionamento[i].criar_matriz(position1);
            posicionamento[i].mostrar_matriz(position1);
        }
        else{
            posicionamento[i].criar_matriz(position2);
            posicionamento[i].mostrar_matriz(position2);
        }
        //int linha, coluna, tipo;
        //cin >> linha >> coluna >> tipo;
        //linha--;
        //coluna--;
        //posicionamento[i].editar_matriz(position, linha, coluna, tipo);
        //posicionamento[i].mostrar_matriz(position);
        //mapa1.edit_map(lineMain, linha, coluna);
        //mapa1.show_map(lineMain, lineSub);
    }
    Canoa canoa[12];
    Submarino submarino[8];
    PortaAvioes portaAvioes[4];

    //posiciona as embarcações
    ifstream readAndSet;
    readAndSet.open("map2.txt");
    
    if (readAndSet.is_open()){
        int qtde_canoa=0, qtde_porta_avioes=0, qtde_submarino=0; 
        
        while (!readAndSet.eof()){
            
            string linha;
            getline(readAndSet, linha);
            
            if (linha[0] == '#'|| linha == ""){
                continue;
            }

            istringstream linhaAtual {linha};
            string tipo, orientacao;
            //string string_linha, string_coluna
            int line, coluna;

            linhaAtual >> line;
            linhaAtual >> coluna;

            //line = stoi(string_linha);
            //coluna = stoi(string_coluna);

            linhaAtual >> tipo;
            linhaAtual >> orientacao;

            if (tipo == "canoa"){
                if(qtde_canoa < 6){
                    canoa[qtde_canoa].set_line(line);
                    canoa[qtde_canoa].set_column(coluna);
                    canoa[qtde_canoa].set_orientation(orientacao);
                    posicionamento[0].setar_matriz(position1, line, coluna, canoa[qtde_canoa].get_type(), orientacao, 1);
                    qtde_canoa++;
                }
                else{
                    canoa[qtde_canoa].set_line(line);
                    canoa[qtde_canoa].set_column(coluna);
                    canoa[qtde_canoa].set_orientation(orientacao);
                    posicionamento[1].setar_matriz(position2, line, coluna, canoa[qtde_canoa].get_type(), orientacao, 1);
                    qtde_canoa++;
                }
            }
            else if (tipo == "submarino"){
                if(qtde_submarino < 4){
                    submarino[qtde_submarino].set_line(line);
                    submarino[qtde_submarino].set_column(coluna);
                    submarino[qtde_submarino].set_orientation(orientacao);
                    posicionamento[0].setar_matriz(position1, line, coluna, submarino[qtde_submarino].get_type(), orientacao, 2);
                    qtde_submarino++;
                }
                else{
                    submarino[qtde_submarino].set_line(line);
                    submarino[qtde_submarino].set_column(coluna);
                    submarino[qtde_submarino].set_orientation(orientacao);
                    posicionamento[1].setar_matriz(position2, line, coluna, submarino[qtde_submarino].get_type(), orientacao, 2);
                    qtde_submarino++;
                }
            }
            else if (tipo == "porta-avioes"){
                if(qtde_porta_avioes < 2){
                    portaAvioes[qtde_porta_avioes].set_line(line);
                    portaAvioes[qtde_porta_avioes].set_column(coluna);
                    portaAvioes[qtde_porta_avioes].set_orientation(orientacao);
                    posicionamento[0].setar_matriz(position1, line, coluna, portaAvioes[qtde_porta_avioes].get_type(), orientacao, 4);
                    //set_porta_avioes(line, coluna, orientacao, qtde_porta_avioes);
                    qtde_porta_avioes++;
                }
                else{
                    portaAvioes[qtde_porta_avioes].set_line(line);
                    portaAvioes[qtde_porta_avioes].set_column(coluna);
                    portaAvioes[qtde_porta_avioes].set_orientation(orientacao);
                    posicionamento[1].setar_matriz(position2, line, coluna, portaAvioes[qtde_porta_avioes].get_type(), orientacao, 4);
                    //set_porta_avioes(line, coluna, orientacao, qtde_porta_avioes);
                    qtde_porta_avioes++;
                }
            }

        }
        readAndSet.close();
    }

    else {
        readAndSet.close();
        cout << "Problemas ao ler o Mapa" << endl;
        
    }

    /*cout << endl;
    posicionamento[0].mostrar_matriz(position1);
    cout << endl;
    posicionamento[1].mostrar_matriz(position2);
    */

    

    while(true){

    }

    return 0;
}