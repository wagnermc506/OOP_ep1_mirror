#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <ctime>
#include "../inc/game.hpp"
#include "../inc/canoa.hpp"
#include "../inc/submarino.hpp"
#include "../inc/porta_avioes.hpp"
#include "../inc/mapa.hpp"
#include "../inc/posicao.hpp"
#include "../inc/player.hpp"
#include "../inc/game.hpp"

Game::Game(){	
}

Game::~Game(){
}

void Game::set_game(int position1[][13], int position2[][13], string lineMain1[], string lineMain2[]){
	
	Mapa mapa1;
    Mapa mapa2;

    //Desenhar Mapa
    mapa1.create_lineMain(lineMain1);
    mapa2.create_lineMain(lineMain2);
    //mapa1.show_map(lineMain, lineSub);

	Posicao posicionamento[2];

    for(int i = 0; i < 2; i++){
        if(i == 0){
            posicionamento[i].criar_matriz(position1);
            //posicionamento[i].mostrar_matriz(position1);
        }
        else{
            posicionamento[i].criar_matriz(position2);
            //posicionamento[i].mostrar_matriz(position2);
        }
    }        
    Canoa canoa1[6];
    Canoa canoa2[6];
    Submarino submarino1[4];
    Submarino submarino2[4];
    PortaAvioes portaAvioes1[2];
    PortaAvioes portaAvioes2[2];

    //posiciona as embarcações
    ifstream readAndSet;
    readAndSet.open("./doc/posicoes.txt");
    
    if (readAndSet.is_open()){
        int qtde_canoa = 0, qtde_porta_avioes = 0, qtde_submarino = 0; 
        
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
                    canoa1[qtde_canoa].set_line(line);
                    canoa1[qtde_canoa].set_column(coluna);
                    canoa1[qtde_canoa].set_orientation(orientacao);
                    posicionamento[0].setar_matriz(position1, line, coluna, canoa1[qtde_canoa].get_type(), orientacao, 1);
                    qtde_canoa++;
                }
                else{
                    canoa2[qtde_canoa-6].set_line(line);
                    canoa2[qtde_canoa-6].set_column(coluna);
                    canoa2[qtde_canoa-6].set_orientation(orientacao);
                    posicionamento[1].setar_matriz(position2, line, coluna, canoa2[qtde_canoa-6].get_type(), orientacao, 1);
                    qtde_canoa++;
                }
            }
            else if (tipo == "submarino"){
                if(qtde_submarino < 4){
                    submarino1[qtde_submarino].set_line(line);
                    submarino1[qtde_submarino].set_column(coluna);
                    submarino1[qtde_submarino].set_orientation(orientacao);
                    posicionamento[0].setar_matriz(position1, line, coluna, submarino1[qtde_submarino].get_type(), orientacao, 2);
                    qtde_submarino++;
                }
                else{
                    submarino2[qtde_submarino-4].set_line(line);
                    submarino2[qtde_submarino-4].set_column(coluna);
                    submarino2[qtde_submarino-4].set_orientation(orientacao);
                    posicionamento[1].setar_matriz(position2, line, coluna, submarino2[qtde_submarino-4].get_type(), orientacao, 2);
                    qtde_submarino++;
                }
            }
            else if (tipo == "porta-avioes"){
                if(qtde_porta_avioes < 2){
                    portaAvioes1[qtde_porta_avioes].set_line(line);
                    portaAvioes1[qtde_porta_avioes].set_column(coluna);
                    portaAvioes1[qtde_porta_avioes].set_orientation(orientacao);
                    posicionamento[0].setar_matriz(position1, line, coluna, portaAvioes1[qtde_porta_avioes].get_type(), orientacao, 4);
                    qtde_porta_avioes++;
                }
                else{
                    portaAvioes2[qtde_porta_avioes-2].set_line(line);
                    portaAvioes2[qtde_porta_avioes-2].set_column(coluna);
                    portaAvioes2[qtde_porta_avioes-2].set_orientation(orientacao);
                    posicionamento[1].setar_matriz(position2, line, coluna, portaAvioes2[qtde_porta_avioes-2].get_type(), orientacao, 4);
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

}

void Game::start_game(int position1[][13], int position2[][13], string lineMain1[], string lineMain2[]){

	Mapa mapa1;
    Mapa mapa2;
    Posicao posicionamento[2];

    string lineSub;
    lineSub = mapa1.create_lineSub();

	Player player[2];
    for(int c = 0; c < 2; c++){
        player[c].set_nome(c);
    }
    system("reset");
    srand(time(0));
    int player_time = (rand() % 2);
    //int player_time = 0;
    int iline, icolumn;
    bool player_yet_alive = true;

    while(true){
        //system("reset");
        //Primeiro Player joga
        if(player_time == 0){
            //posicionamento[1].mostrar_matriz(position2);
            mapa2.show_map(lineMain2, lineSub);            
            iline = player[0].chuta_linha();
            icolumn = player[0].chuta_coluna();
            //system("clear");

            posicionamento[1].testar_tiro(position2, iline, icolumn, player[0].get_nome());
            cin.ignore();
            cin.get();
            system("clear");
            player_yet_alive = posicionamento[1].navios_em_jogo(position2);
            if(player_yet_alive == false){
                player[0].win_message();
                break;
            }
            mapa2.edit_map(lineMain2, position2[iline][icolumn], iline, icolumn);
            mapa2.show_map(lineMain2, lineSub);
            cout << "Aperte enter para continuar" << endl;
            cin.get();
            system("clear");
            //posicionamento[1].mostrar_matriz(position2);
            player_time++;
        }
        //Segundo Player joga
        else if(player_time == 1){
            //posicionamento[0].mostrar_matriz(position2);
            mapa1.show_map(lineMain1, lineSub);            
            iline = player[1].chuta_linha();
            icolumn = player[1].chuta_coluna();
            //system("clear");

            posicionamento[0].testar_tiro(position1, iline, icolumn, player[1].get_nome());
            cin.ignore();
            cin.get();
            system("clear");
            player_yet_alive = posicionamento[0].navios_em_jogo(position1);
            if(player_yet_alive == false){
                player[1].win_message();
                break;
            }
            mapa1.edit_map(lineMain1, position1[iline][icolumn], iline, icolumn);
            mapa1.show_map(lineMain1, lineSub);
            cout << "Aperte enter para continuar" << endl;
            cin.get();
            system("clear");
            //posicionamento[0].mostrar_matriz(position2);
            player_time--;
        }
    }
}