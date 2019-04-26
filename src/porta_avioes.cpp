#include <iostream>
#include "../inc/porta_avioes.hpp"

using namespace std;

PortaAvioes::PortaAvioes(){
    set_hitPoints(1);
    set_type(3);
    set_partsNumber(4);
    //hitPoints = 1;
    //type = 3;
    //partsNumber = 4;
    //cout << "Porta-Aviões criado" << endl;
}

PortaAvioes::~PortaAvioes(){
    //cout << "Porta-Aviões destruído" << endl;
}


