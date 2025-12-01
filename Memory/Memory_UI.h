#ifndef MEMORY_UI_H
#define MEMORY_UI_H

#include "BoardGame_Classes.h"
using namespace std;

class Memory_UI : public UI<char> {
public:
	Memory_UI();
	Player<char>* create_player(string& name, char symbol, PlayerType type) override;
	Move<char>* get_move(Player<char>* player) override;
};




#endif