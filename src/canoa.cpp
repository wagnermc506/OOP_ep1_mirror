#include <iostream>
#include "../inc/canoa.hpp"

using namespace std;

Canoa::Canoa(){
    set_hitPoints(1);
    set_type(1);
    set_partsNumber(1);
    //hitPoints = 1;
    //type = 1;
    //partsNumber = 1;
    //cout << "Canoa criada" << endl;
}

Canoa::~Canoa(){
    //cout << "Canoa destruída" << endl;
}

