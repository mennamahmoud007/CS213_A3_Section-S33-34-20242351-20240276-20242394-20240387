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
    bool is_valid_word(const string& word) const;
    string get_word(int r1, int c1, int r2, int c2, int r3, int c3) const;

public:
    WordBoard();
    bool update_board(Move<char>* move) override;
    bool is_win(Player<char>* player) override;
    bool is_lose(Player<char>* player) override { return false; }
    bool is_draw(Player<char>* player) override;
    bool game_is_over(Player<char>* player) override;
};

#endif