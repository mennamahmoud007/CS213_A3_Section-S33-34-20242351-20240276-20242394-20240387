#ifndef SUS_BOARD_H
#define SUS_BOARD_H

#include "BoardGame_Classes.h"
using namespace std;

class SUS_Board : public Board<char> {
private:
	char blank_symbol = '.';
	int count_SUS_sequences(int r, int c, char sym);

public:
	SUS_Board();
	virtual ~SUS_Board();

	bool update_board(Move<char>* move) override;
	bool is_win(Player<char>* player) override;
	bool is_lose(Player<char>* player) override { return false; }
	bool is_draw(Player<char>* player) override;
	bool game_is_over(Player<char>* player) override;

	int score_S = 0;
	int score_U = 0;
};











#endif