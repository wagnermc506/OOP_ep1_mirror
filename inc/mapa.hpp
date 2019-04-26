#ifndef MAPA_HPP
#define MAPA_HPP

#include <string>

using namespace std;

class Mapa{

    private:
        int posicao;
    public:
        Mapa();
        ~Mapa();
        //string create_lineMain();
        void create_lineMain(string lineMain[]);
        string create_lineSub();
        void show_map(string lineMain[], string lineSub);
        void edit_map(string lineMain[], int line, int column);
};

#endif