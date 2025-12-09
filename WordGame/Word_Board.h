#ifndef WORD_BOARD_H
#define WORD_BOARD_H

#include "../Framework/BoardGame_Classes.h"
#include <vector>
#include <string>
#include <fstream>

using namespace std;

/**
 * @class WordBoard
 * @brief Word Tic-Tac-Toe board where players place letters
 */
class WordBoard : public Board<char> {
private:
    vector<string> dictionary;   ///< Loaded dictionary words
    char blank_symbol = '.';     ///< Empty cell symbol

    /// @brief Load dictionary from dic.txt
    void load_dictionary();

    /// @brief Get word from board positions
    string get_word(int r1, int c1, int r2, int c2, int r3, int c3) const;

public:
    WordBoard();                                 ///< Constructor
    bool is_valid_word(const string& word) const;///< Check if word exists
    bool update_board(Move<char>* move) override;///< Update board with move
    bool is_win(Player<char>* player) override;  ///< Check for winning word
    bool is_lose(Player<char>* player) override { return false; }
    bool is_draw(Player<char>* player) override; ///< Check for draw
    bool game_is_over(Player<char>* player) override;///< Check if game over
    char get_cell(int r, int c) const { return board[r][c]; }

    /// @brief Check if move creates a valid word
    bool test_move(int r, int c, char letter) const;

    void apply_move(int r, int c, char letter);  ///< Direct move for AI
    void undo_move(int r, int c);                ///< Remove move for AI
    vector<pair<int, int>> get_empty_cells() const;///< Get empty cells

    /// @brief Get current dictionary (for AI)
    const vector<string>& get_dictionary() const { return dictionary; }
};

#endif