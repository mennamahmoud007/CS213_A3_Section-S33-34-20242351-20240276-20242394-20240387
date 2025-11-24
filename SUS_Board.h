#pragma once
#include "BoardGame_Classes.h"
#include "SUS_Move.h"
#include <vector>

class SUS_Board : public Board<char> {
public:
    SUS_Board();
    virtual ~SUS_Board() = default;

    std::vector<std::vector<char>> get_board_matrix() override;
    bool update_board(Move<char>* m) override;
    bool game_is_over(Player<char>* p) override;
    bool is_win(Player<char>* p) override;
    bool is_draw(Player<char>* p) override;

    int get_score(int playerIndex) const;
    void reset_board();

private:
    static const int ROWS = 3;
    static const int COLS = 3;
    std::vector<std::vector<char>> board;
    int scores[2];

    bool in_bounds(int r, int c) const;
    int count_new_sus_sequences(int r, int c) const;
    bool board_full() const;
};
