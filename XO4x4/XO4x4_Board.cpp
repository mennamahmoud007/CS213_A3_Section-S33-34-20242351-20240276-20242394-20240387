#include "XO4x4_Board.h"
#include "XO4x4_Board.h"
#include "XO4x4_Board.h"
#include "XO4x4_Board.h"
#include <iostream>
#include <utility>

using namespace std;


XO4x4_Board::XO4x4_Board() : Board(4,4){
	for (int r = 0; r < rows; r++) {
		for (int c = 0; c < columns; c++) {
			board[r][c] = blank_symbol;
		}
	}

	// Starting Positions
	board[0][0] = 'O';
	board[0][1] = 'X';
	board[0][2] = 'O';
	board[0][3] = 'X';

	board[3][0] = 'X';
	board[3][1] = 'O';
	board[3][2] = 'X';
	board[3][3] = 'O';

	n_moves = 0;
}

XO4x4_Board::~XO4x4_Board()
{
}

bool XO4x4_Board::is_adjacent(int x1, int y1, int x2, int y2) const
{
	return (abs(x1 - x2) + abs(y1 - y2) == 1);
}

bool XO4x4_Board::check_three_in_row(char sym) const
{
	// Check for Horizontal
	for (int r = 0; r < 4; r++) {
		for (int c = 0; c <= 1; c++) {
			if (board[r][c] == sym && board[r][c+1] == sym && board[r][c+2] == sym) {
				return true;
			}
		}
	}

	// Check for Vertical
	for (int c = 0; c < 4; c++) {
		for (int r = 0; r <= 1; r++) {
			if (board[r][c] == sym && board[r+1][c] == sym && board[r+2][c] == sym) {
				return true;
			}
		}
	}

	// Check for diagonals
	if (board[0][0] == sym && board[1][1] == sym && board[2][2] == sym) return true;
	if (board[1][1] == sym && board[2][2] == sym && board[3][3] == sym) return true;

	if (board[0][2] == sym && board[1][1] == sym && board[2][0] == sym) return true;
	if (board[1][3] == sym && board[2][2] == sym && board[3][1] == sym) return true;

	return false;
}

bool XO4x4_Board::update_board(Move<char>* move) {
	int x = move->get_x();
	int y = move->get_y();
	char sym = move->get_symbol();

	
	int nx, ny;

	if (board[x][y] != sym) {
		cout << "You must move your own token " << sym << endl;
		return false;
	}

	cout << "Enter the new position for the token (row(0-3) , column(0-3)): ";
	cin >> nx >> ny;

	if (x < 0 || x >= 4 || y < 0 || y >= 4) return false;
	if (nx < 0 || nx >= 4 || ny < 0 || ny >= 4) return false;


	if (board[nx][ny] != blank_symbol) {
		cout << "Destination is not empty.\n";
		return false;
	}

	if (!is_adjacent(x, y, nx, ny)) {
		cout << "You can move only 1 step horizontally or vertically.\n";
		return false;
	}

	
	board[x][y] = blank_symbol;
	board[nx][ny] = sym;

	n_moves++;
	return true;
}

bool XO4x4_Board::is_win(Player<char>* player) {
	return check_three_in_row(player->get_symbol());
}


bool XO4x4_Board::is_draw(Player<char>*) {
	return false;
}


bool XO4x4_Board::game_is_over(Player<char>* p) {
	return is_win(p);
}



