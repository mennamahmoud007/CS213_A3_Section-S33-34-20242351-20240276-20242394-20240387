#ifndef PYRAMID_BOARD_H
#define PYRAMID_BOARD_H

#include "BoardGame_Classes.h"
#include <vector>
using namespace std;

class Pyramid_Board : public Board<char> {
private:
	/*char blank_symbol = ' . ';*/
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

	// Added Functions for AI Player
	vector<vector<pair<int, int>>> get_win_lines() const { return winLines; }		// getter for possible wins
	char get_cell(int r, int c) const { return board[r][c]; }						// getter for the board cell 
	void apply_move(int r, int c, char sym);										// setter for simulated move
	void undo_move(int r, int c);													// remove the simulated move 
	vector<pair<int, int>> get_empty_cells() const;									// getter for the empty cells
	bool is_win_for_symbol(char sym);												// check if_win for simulated move
};




#endif