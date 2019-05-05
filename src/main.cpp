#include <iostream>
#include <string>
#include "../inc/game.hpp"

using namespace std;

int main(){

    int position1[13][13], position2[13][13];
    string lineMain1[13], lineMain2[13];

    Game game;
    game.set_game(position1, position2, lineMain1, lineMain2);
    game.start_game(position1, position2, lineMain1, lineMain2);

    return 0;
}