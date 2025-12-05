#ifndef OBSTACLES_UI_H
#define OBSTACLES_UI_H

#include "BoardGame_Classes.h"
#include "obstacles_Board.h"

class ObstaclesUI : public UI<char> {
public:
	ObstaclesUI();
	Player<char>* create_player(string& name, char symbol, PlayerType type) override;
	Move<char>* get_move(Player<char>* player) override;
	void display_rules();
};

#endif 
