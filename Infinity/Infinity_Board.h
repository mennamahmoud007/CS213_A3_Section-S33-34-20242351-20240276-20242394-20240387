#ifndef INFINITY_BOARD_H
#define INFINITY_BOARD_H

#include "BoardGame_Classes.h"
#include <queue>
using namespace std;

class Infinity_Board : public Board<char> {
private:
    char blank = '.';
    queue<pair<int, int>> moves; // track oldest moves

    bool three_in_row(char sym) const;

public:
    Infinity_Board();
    virtual ~Infinity_Board();

    bool update_board(Move<char>* move) override;
    void remove_oldest(); // remove oldest after every 3 moves
    bool is_win(Player<char>* player) override;
    bool is_lose(Player<char>* player) override;
    bool is_draw(Player<char>* player) override;
    bool game_is_over(Player<char>* player) override;
    void display_board();
};

#endif
