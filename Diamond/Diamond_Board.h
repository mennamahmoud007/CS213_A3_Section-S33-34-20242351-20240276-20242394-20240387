#ifndef DIAMOND_BOARD_H
#define DIAMOND_BOARD_H

#include "BoardGame_Classes.h"
#include <vector>

using namespace std;

class Diamond_Board : public Board<char> {
private:
    char blank = '.';
    char invalid = ' '; 
    int center = 4;     

    bool valid_cell(int r, int c) const;
    vector<int> find_line_directions(char sym, int length) const;

public:
    Diamond_Board();
    virtual ~Diamond_Board();

    bool update_board(Move<char>* move) override;
    bool is_win(Player<char>* player) override;
    bool is_lose(Player<char>* player) override;
    bool is_draw(Player<char>* player) override;
    bool game_is_over(Player<char>* player) override;
    void display_board();

    char get_cell(int r, int c) const { return board[r][c]; }
    void apply_move(int r, int c, char sym);
    void undo_move(int r, int c);
    vector<pair<int, int>> get_empty_cells() const;
};

#endif 
