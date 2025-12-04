#include "Word_Board_UI.h"
#include <iostream>
#include <cstdlib>

using namespace std;

Player<char>* WordUI::create_player(string& name, char symbol, PlayerType type) {
    cout << "Creating " << (type == PlayerType::HUMAN ? "human" : "computer")
        << " player: " << name << " (letters)" << endl;
    return new Player<char>(name, symbol, type);
}

Move<char>* WordUI::get_move(Player<char>* player) {
    int x, y;
    char letter;

    if (player->get_type() == PlayerType::HUMAN) {
        cout << "\nEnter row (0-2), column (0-2), and letter: ";
        cin >> x >> y >> letter;
    }
    else {
        x = rand() % 3;
        y = rand() % 3;
        letter = 'A' + (rand() % 26);
    }
    return new Move<char>(x, y, letter);
}

void WordUI::display_word_rules() {
    cout << "\n=== WORD TIC-TAC-TOE RULES ===" << endl;
    cout << "1. Place letters to form 3-letter words" << endl;
    cout << "2. Words can be horizontal, vertical, or diagonal" << endl;
    cout << "3. First player to form a valid word wins!" << endl;
    cout << "===============================" << endl;
}