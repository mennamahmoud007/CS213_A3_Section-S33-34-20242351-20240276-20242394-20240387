#include "Pyramid_Board.h"
#include <iostream>

Pyramid_Board::Pyramid_Board() : Board(3,5) {
	for (int r = 0; r < rows; r++) {
		for (int c = 0; c < columns; c++) {
			int center = 2;
			if (c >= center - r && c <= center + r) board[r][c] = '.';
			else board[r][c] = ' ';
		}
	}

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

	n_moves = 0;
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

	if (board[r][c] == ' ') {
		cout << "Blocked cell — cannot play here.\nTry again\n";
		return false;
	}

	if (board[r][c] != '.' && (board[r][c] == 'X' || board[r][c] == 'O')) {
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


void Pyramid_Board::apply_move(int r, int c, char sym)
{
	board[r][c] = sym;
	n_moves++;
}


void Pyramid_Board::undo_move(int r, int c)
{
	board[r][c] = '.';
	n_moves--;
}


vector<pair<int, int>> Pyramid_Board::get_empty_cells() const
{
	vector<pair<int, int>> cells;
	for (int r = 0; r < rows; r++) {
		for (int c = 0; c < columns; c++) {
			if (board[r][c] == '.') cells.emplace_back(r, c);
		}
	}
	return cells;
}


bool Pyramid_Board::is_win_for_symbol(char sym)
{
	for (auto &line : winLines) {
		if (board[line[0].first][line[0].second] == sym && board[line[1].first][line[1].second] == sym
			&& board[line[2].first][line[2].second] == sym) {
			return true;
		}
	}
	return false;
}





