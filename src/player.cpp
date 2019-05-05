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

int Player::chuta_linha(){
	cout << "--> " << get_nome() << endl;
	int linha;
	bool validacao;
	do{
		cout << "Insira a linha de ataque: ";
		cin >> linha;
		validacao = validar_input(linha);
	}while(validacao == false);
	return linha;
}

int Player::chuta_coluna(){
	int coluna;
	bool validacao;
	do{
		cout << "Insira a coluna de ataque: ";
		cin >> coluna;
		cout << endl;
		validacao = validar_input(coluna);
	}while(validacao == false);
	return coluna;
}

bool Player::validar_input(int input){
	if(input < 0 || input >= 13){
		cout << "Fora do campo de ataque, insira novamente" << endl;
		return false;
	}
	else{
		return true;
	}
}

void Player::win_message(){
	cout << nome << " Venceu!" << endl;
}