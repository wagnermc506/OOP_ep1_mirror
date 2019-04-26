#include <iostream>
#include <string>
#include "../inc/navio.hpp"

using namespace std;

Navio::Navio(){
    //cout << "Navio criado" << endl;
}

Navio::~Navio(){
    //cout << "Navio destruído" << endl;
}

void Navio::set_hitPoints(int hitPoints){
    this -> hitPoints = hitPoints;
}

int Navio::get_hitPoints(){
    return hitPoints;
}

void Navio::set_line(int line){
    this -> line = line;
}

int Navio::get_line(){
    return line;
}

void Navio::set_column(int column){
    this -> column = column;
}

int Navio::get_column(){
    return column;
}

void Navio::set_type(int type){
    this -> type = type;
}

int Navio::get_type(){
    return type;
}

void Navio::set_partsNumber(int partsNumber){
    this -> partsNumber = partsNumber;
}

int Navio::get_partsNumber(){
    return partsNumber;
}

void Navio::set_orientation(string orientation){
    this -> orientation = orientation;
}

string Navio::get_orientation(){
    return orientation;
}

void Navio::recebe_dano(){
    this -> hitPoints--; 
}
