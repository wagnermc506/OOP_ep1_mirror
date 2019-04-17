#include "../inc/mapa.hpp"
#include <iostream>
#include <string>

Mapa::Mapa(){
    cout << "Mapa criado" << endl;
}

Mapa::~Mapa(){
    cout << "Mapa destruído" << endl;
}

string Mapa::create_lineMain(){
    string lineMain;
    lineMain = "|-  ||-  ||-  ||-  ||-  ||-  ||-  ||-  ||-  ||-  ||-  ||-  ||-  |\n";
    return lineMain;
}

string Mapa::create_lineSub(){
    string lineSub;
    lineSub = "|___||___||___||___||___||___||___||___||___||___||___||___||___|\n";
    return lineSub;
}

void Mapa::show_map(string lineMain[], string lineSub){
    cout << "    _01  _02  _03  _04  _05  _06  _07  _08  _09  _10  _11  _12  _13 " << endl;
    for(int i = 0; i < 13; i++){
        if(i < 10){
            cout << "0" << i << " " << lineMain[i];
        }
        else{
            cout << i << " " << lineMain[i];
        }
        cout << "   " << lineSub;
    }
}

