#include "Pyramid_Board.h"
#include <iostream>

Pyramid_Board::Pyramid_Board() : Board(3,5) {
	board[0][0] = blocked_symbol;
	board[0][1] = blocked_symbol;
	board[0][3] = blocked_symbol;
	board[0][4] = blocked_symbol;
	board[1][0] = blocked_symbol;
	board[1][4] = blocked_symbol;

	winLines = {
		// Vertical win
		{{0,2}, {1,2}, {2,2}},

		// Horizontal win
		{{1,1}, {1,2}, {1,3}},
		{{2,0}, {2,1}, {2,2}},
		{{2,1}, {2,2}, {2,3}},
		{{2,2}, {2,3}, {2,4}},

		// Diagonal win
		{{0,2}, {1,1}, {2,0}},
		{{0,2}, {1,3}, {2,4}}
	};
}


Pyramid_Board::~Pyramid_Board()
{
}


bool Pyramid_Board::update_board(Move<char>* move)
{
	int r = move->get_x();
	int c = move->get_y();
	char sym = move->get_symbol();

	if (r < 0 || r >= 3 || c < 0 || c >= 5) {
		return false;
	}

	if (board[r][c] == blocked_symbol) {
		cout << "Blocked cell — cannot play here.\nTry again\n";
		return false;
	}

	if (board[r][c] != blocked_symbol && board[r][c] == 'X' && board[r][c] == 'O') {
		cout << "This cell is already taken\nChoose another empty cell\n";
		return false;
	}

	board[r][c] = sym;
	n_moves++;

	return true;
}

bool Pyramid_Board::is_win(Player<char>* player)
{
	char sym = player->get_symbol();

	for (auto line : winLines) {
		if (board[line[0].first][line[0].second] == sym && board[line[1].first][line[1].second] == sym
			&& board[line[2].first][line[2].second] == sym) {
			return true;
		}
	}

	return false;
}


bool Pyramid_Board::is_draw(Player<char>* player)
{
	return n_moves == 9;
}

bool Pyramid_Board::game_is_over(Player<char>* player)
{
	return is_win(player) || is_draw(player);
}

void Pyramid_Board::display_board() {
	int rows = board.size();
	int cols = board[0].size();

	// Column numbers
	cout << "    ";
	for (int c = 0; c < cols; c++)
		cout << c << "   ";
	cout << "\n";

	// Top border
	cout << "  ";
	for (int c = 0; c < cols * 4 + 1; c++)
		cout << "-";
	cout << "\n";

	// Rows
	for (int r = 0; r < rows; r++) {
		cout << r << " |";
		for (int c = 0; c < cols; c++) {
			char cell = board[r][c];
			if (cell == '\0') cell = ' ';
			cout << " " << cell << " |";
		}
		cout << "\n";

		// Row separator
		cout << "  ";
		for (int c = 0; c < cols * 4 + 1; c++)
			cout << "-";
		cout << "\n";
	}
}



