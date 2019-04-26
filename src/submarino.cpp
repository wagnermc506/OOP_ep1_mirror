#include <iostream>
#include "../inc/submarino.hpp"

using namespace std;

Submarino::Submarino(){
    set_hitPoints(2);
    set_type(2);
    set_partsNumber(2);
    //set_orientation("Esquerda");
    //hitPoints = 2;
    //type = 2;
    //partsNumber = 2;
    //cout << "Submarino criado" << endl;
}

Submarino::~Submarino(){
    //cout << "Submarino destruído" << endl;
}
