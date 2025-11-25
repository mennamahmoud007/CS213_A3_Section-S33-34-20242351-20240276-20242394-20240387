#include "obstacles_Board.h"
#include <iostream>



ObstaclesBoard::ObstaclesBoard() : Board(6, 6) {
	for (int r = 0; r < rows; r++) {
		for (int c = 0; c < columns; c++) {
			board[r][c] = blank_symbol;
		}
	}
}

ObstaclesBoard::~ObstaclesBoard()
{
}


void ObstaclesBoard::add_obstacle(int count)
{
	for (int i = 0; i < count; i++) {
		int x, y;
		do {
			x = rand() % 6;
			y = rand() % 6;
		} while (board[x][y] != blank_symbol);

		board[x][y] = obstacle;
	}
}

bool ObstaclesBoard::update_board(Move<char>* move)
{
	int x = move->get_x();
	int y = move->get_y();
	char sym = move->get_symbol();

	if (x < 0 || x >= 6 || y < 0 || y >= 6) {
		cout << "Invalid cell: row and column must be between 0-5.\nTry again." << endl;
		return false;
	}

	if (board[x][y] == obstacle) {
		cout << "!! Obstacle Cell\nChoose another empty cell.\n";
		return false;
	}
	else if (board[x][y] != obstacle && board[x][y] != blank_symbol) {
		cout << "This Cell is already taken.\nChoose another empty cell." << endl;
		return false;
	}

	board[x][y] = sym;
	n_moves++;
	moves_round++;

	if (moves_round == 2) {
		add_obstacle(2);
		moves_round = 0;
	}

	return true;
}


bool ObstaclesBoard::check_4_in_row(char sym) const
{
	const int R = rows;
	const int C = columns;

	// Check Horizontal
	for (int r = 0; r < R; r++) {
		for (int c = 0; c < C-4; c++) {
			if (board[r][c] == sym && board[r][c + 1] == sym && board[r][c + 2] == sym && board[r][c + 3] == sym) {
				return true;
			}
		}
	}

	// Check Vertical
	for (int r = 0; r <= R-4; r++) {
		for (int c = 0; c < C; c++) {
			if (board[r][c] == sym && board[r + 1][c] == sym && board[r + 2][c] == sym && board[r + 3][c] == sym) {
				return true;
			}
		}
	}

	// Check Diagonals
	for (int r = 0; r <= R-4; r++) {
		for (int c = 0; c <= C-4; c++) {
			if (board[r][c] == sym && board[r + 1][c + 1] == sym && board[r + 2][c + 2] == sym && board[r + 3][c + 3] == sym) {
				return true;
			}
		}
	}

	for (int r = 0; r <= R-4; r++) {
		for (int c = 3; c < C; c++) {
			if (board[r][c] == sym && board[r + 1][c - 1] == sym && board[r + 2][c - 2] == sym && board[r + 3][c - 3] == sym) {
				return true;
			}
		}
	}

	return false;
}


bool ObstaclesBoard::is_win(Player<char>* player)
{
	return check_4_in_row(player->get_symbol());
}

bool ObstaclesBoard::is_draw(Player<char>* player)
{
	return n_moves >= 36;
}

bool ObstaclesBoard::game_is_over(Player<char>* player)
{
	return is_win(player) || is_draw(player);
}







