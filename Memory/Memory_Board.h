#ifndef MEMORY_BOARD_H
#define MEMORY_BOARD_H

#include "BoardGame_Classes.h"
using namespace std;

class Memory_Board : public Board<char> {
private:
	char blank_symbol = '.';
	char realBoard[3][3];

public:
	Memory_Board();
	virtual ~Memory_Board();

	bool update_board(Move<char>* move) override;
	bool is_win(Player<char>* player) override { return false; }
	bool is_lose(Player<char>* player) override { return false; }
	bool is_draw(Player<char>* player) override;
	bool game_is_over(Player<char>* player) override;
	bool check_winner(char sym);
};

#endif