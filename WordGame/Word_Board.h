#ifndef WORD_BOARD_H
#define WORD_BOARD_H

#include "../Framework/BoardGame_Classes.h"
#include <vector>
#include <string>
#include <fstream>

using namespace std;

class WordBoard : public Board<char> {
private:
    vector<string> dictionary;
    char blank_symbol = '.';

    void load_dictionary();
    string get_word(int r1, int c1, int r2, int c2, int r3, int c3) const;

public:
    WordBoard();
    bool is_valid_word(const string& word) const;
    bool update_board(Move<char>* move) override;
    bool is_win(Player<char>* player) override;
    bool is_lose(Player<char>* player) override { return false; }
    bool is_draw(Player<char>* player) override;
    bool game_is_over(Player<char>* player) override;

    char get_cell(int r, int c) const { return board[r][c]; }
    void apply_move(int r, int c, char letter);
    void undo_move(int r, int c);
    vector<pair<int, int>> get_empty_cells() const;
};

#endif