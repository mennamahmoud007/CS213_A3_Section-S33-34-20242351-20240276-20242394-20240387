#ifndef ULTIMATE_BOARD_H
#define ULTIMATE_BOARD_H

#include "../Framework/BoardGame_Classes.h"
#include <vector>
#include <utility>

using namespace std;

class UltimateBoard : public Board<char> {
private:
    vector<vector<vector<vector<char>>>> small_boards;
    vector<vector<char>> main_board;
    pair<int, int> next_board;
    char blank_symbol = '.';

    bool check_small_board_win(int board_r, int board_c, char symbol) const;
    bool check_small_board_draw(int board_r, int board_c) const;
    void update_main_board_status(int board_r, int board_c, char symbol);
    bool is_small_board_available(int board_r, int board_c) const;

public:
    UltimateBoard();
    bool update_board(Move<char>* move) override;
    bool is_win(Player<char>* player) override;
    bool is_lose(Player<char>* player) override { return false; }
    bool is_draw(Player<char>* player) override;
    bool game_is_over(Player<char>* player) override;

    void display() const;
    pair<int, int> get_next_board() const { return next_board; }
};

#endif