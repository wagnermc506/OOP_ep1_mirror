#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <iostream>
#include <string>

using namespace std;

class Player{
	private:
		string nome;
	public:
		Player();
		~Player();
		void set_nome(int player_id);
		string get_nome();

		int chuta_linha();
		int chuta_coluna();
		bool validar_input(int input);
		void win_message();
};

#endif