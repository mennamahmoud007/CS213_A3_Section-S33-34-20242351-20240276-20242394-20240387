#ifndef OBSTACLES_BOARD_H
#define OBSTACLES_BOARD_H

#include "BoardGame_Classes.h"
#include <vector>
#include <utility>

using namespace std;

class ObstaclesBoard : public Board<char> {
private:
	char blank_symbol = '.';
	char obstacle = '#';
	int moves_round = 0;

	bool check_4_in_row(char sym) const;
	void add_obstacle(int count);

public:
	ObstaclesBoard();
	virtual ~ObstaclesBoard();

	bool update_board(Move<char>* move) override;
	bool is_win(Player<char>* player) override;
	bool is_lose(Player<char>* player) override { return false; }
	bool is_draw(Player<char>* player) override;
	bool game_is_over(Player<char>* player) override;
};

#endif 
