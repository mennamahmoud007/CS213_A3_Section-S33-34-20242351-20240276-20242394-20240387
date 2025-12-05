#ifndef WORD_BOARD_H
#define WORD_BOARD_H

#include "../Framework/BoardGame_Classes.h"
#include <vector>
#include <string>
#include <fstream>

using namespace std;

/**
 * @class WordBoard
 * @brief A Tic-Tac-Toe style board where players place letters and win by forming valid words.
 */
class WordBoard : public Board<char> {
private:
    /** Dictionary of valid words loaded from file */
    vector<string> dictionary;

    /** Symbol used to represent an empty cell */
    char blank_symbol = '.';

    /**
     * @brief Load dictionary file into memory.
     */
    void load_dictionary();

    /**
     * @brief Extract a 3-letter word based on 3 cell coordinates.
     * @return Constructed string in reading order.
     */
    string get_word(int r1, int c1, int r2, int c2, int r3, int c3) const;

public:
    /** Constructor */
    WordBoard();

    /**
     * @brief Check if a given 3-letter string exists in the dictionary.
     * @param word Word to verify.
     * @return True if it is a valid dictionary word.
     */
    bool is_valid_word(const string& word) const;

    /**
     * @brief Apply the move: place a letter in the chosen cell.
     * @return True if move was applied.
     */
    bool update_board(Move<char>* move) override;

    /**
     * @brief Check if the player created a valid 3-letter word on the board.
     * @return True if the player wins.
     */
    bool is_win(Player<char>* player) override;

    /** No losing mechanic in this game */
    bool is_lose(Player<char>* player) override { return false; }

    /**
     * @brief Check if the board is full and no valid word was formed.
     * @return True if draw.
     */
    bool is_draw(Player<char>* player) override;

    /**
     * @brief Check if game ended by win or draw.
     */
    bool game_is_over(Player<char>* player) override;

    /** @return Symbol at (r, c). */
    char get_cell(int r, int c) const { return board[r][c]; }

    /** @brief Place letter directly (used for AI simulation). */
    void apply_move(int r, int c, char letter);

    /** @brief Undo letter placement. */
    void undo_move(int r, int c);

    /**
     * @brief Get all currently empty cells for the AI.
     * @return Vector of free board positions.
     */
    vector<pair<int, int>> get_empty_cells() const;
};

#endif
