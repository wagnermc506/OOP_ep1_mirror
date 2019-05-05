#ifndef GAME_HPP
#define GAME_HPP

#include <string>
using namespace std;

class Game{
public:
	Game();
	~Game();
	void set_game(int position1[][13], int position2[][13], string lineMain1[], string lineMain2[]);
	void start_game(int position1[][13], int position2[][13], string lineMain1[], string lineMain2[]);
};


#endif