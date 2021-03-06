#ifndef POSICAO_HPP
#define POSICAO_HPP

#include <iostream>
#include <string>

using namespace std;

class Posicao{
    private:

    public:
        Posicao();
        ~Posicao();
        
        void criar_matriz(int posicao[][13]);
        void mostrar_matriz(int posicao[][13]);
        void setar_matriz(int posicao[][13], int line, int column, int tipo, string orientation, int partsNumber);
        void testar_tiro(int posicao[][13], int line, int column, string player_name);
        bool navios_em_jogo(int posicao[][13]);
};

#endif