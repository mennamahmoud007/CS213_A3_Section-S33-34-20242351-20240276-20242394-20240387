#pragma once
#include "BoardGame_Classes.h"
#include "SUS_Move.h"
#include <string>
#include <iostream>

/*
 UI must implement:
   virtual Move<T>* get_move(Player<T>* p);
   virtual void display_board_matrix(const std::vector<std::vector<T>>& matrix);
   virtual void display_message(const std::string& msg);
 Adapt names if your UI interface uses different function names.
*/

class SUS_UI : public UI<char> {
public:
    SUS_UI(bool fixedLetterMode = true); // if fixedLetterMode true -> players pick S/U at game start
    ~SUS_UI() = default;

    Move<char>* get_move(Player<char>* p) override;
    void display_board_matrix(const std::vector<std::vector<char>>& matrix) override;
    void display_message(const std::string& msg) override;

    // helper to initialize players' chosen letters (if fixedLetterMode)
    void ask_players_for_letters(Player<char>* p1, Player<char>* p2);

private:
    bool fixedLetterMode;
    char playerLetterMap[2]; // player index -> 'S' or 'U'. If unknown, set to ' '
    // If Player has index stored, you can fill mapping directly; otherwise GameManager must coordinate.
};

inline SUS_UI::SUS_UI(bool fixedLetterMode) : fixedLetterMode(fixedLetterMode) {
    playerLetterMap[0] = ' ';
    playerLetterMap[1] = ' ';
}