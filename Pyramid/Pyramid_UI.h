#ifndef PYRAMID_UI_H
#define PYRAMID_UI_H

#include "BoardGame_Classes.h"
#include "Pyramid_Board.h"


class PyramidUI : public UI<char> {
public:
	PyramidUI();
	Player<char>* create_player(string& name, char symbol, PlayerType type) override;
	Move<char>* get_move(Player<char>* player) override;
	void display_rules();
};



#endif