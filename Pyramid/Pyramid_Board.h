#ifndef PYRAMID_BOARD_H
#define PYRAMID_BOARD_H

#include "BoardGame_Classes.h"
#include <vector>
using namespace std;

class Pyramid_Board : public Board<char> {
private:
	char blocked_symbol = '#';
	vector<vector<pair<int, int>>> winLines;

public:
	Pyramid_Board();
	virtual ~Pyramid_Board();

	bool update_board(Move<char>* move) override;
	bool is_win(Player<char>* player) override;
	bool is_lose(Player<char>* player) override { return false; }
	bool is_draw(Player<char>* player) override;
	bool game_is_over(Player<char>* player) override;
	void display_board();
};




#endif