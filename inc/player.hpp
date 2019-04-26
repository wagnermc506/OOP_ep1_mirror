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

};

#endif