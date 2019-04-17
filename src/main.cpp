 #include <iostream>
#include <string>
#include <fstream>
#include "../inc/mapa.hpp"

using namespace std;

int main(){

    Mapa mapa1;

    string lineMain[13], lineSub;
    lineMain[0] = mapa1.create_lineMain();
    lineSub = mapa1.create_lineSub();
    for(int i = 0; i < 13; i++){
        lineMain[i] = lineMain[0];
    }
    mapa1.show_map(lineMain, lineSub);

    return 0;
}
