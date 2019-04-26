#include <iostream>
#include <string>
#include "../inc/player.hpp"

Player::Player(){
}

Player::~Player(){
}

void Player::set_nome(int player_id){
	if(player_id == 0){
		cout << "Insira o nome do primeiro player: ";
	}
	else if(player_id == 1){
		cout << "Insira o nome do segundo player: ";
	}
	string nome;
	cin >> nome;
	this -> nome = nome;
}

string Player::get_nome(){
	return nome;
}