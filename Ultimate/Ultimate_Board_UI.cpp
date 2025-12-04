#include "Ultimate_Board_UI.h"
#include <iostream>
#include <cstdlib>
#include <iomanip>

using namespace std;

Player<char>* UltimateBoard_UI::create_player(string& name, char symbol, PlayerType type) {
    cout << "Creating " << (type == PlayerType::HUMAN ? "human" : "computer")
        << " player: " << name << " (" << symbol << ")" << endl;
    return new Player<char>(name, symbol, type);
}

Move<char>* UltimateBoard_UI::get_move(Player<char>* player) {
    int x, y;
    char symbol = player->get_symbol();

    if (player->get_type() == PlayerType::HUMAN) {
        UltimateBoard* board = dynamic_cast<UltimateBoard*>(player->get_board_ptr());
        auto next = board->get_next_board();

        if (next.first != -1) {
            cout << "\nYou must play in board (" << next.first << "," << next.second << ")" << endl;
            cout << "Enter row (0-2 within board) and column (0-2 within board): ";
            int local_r, local_c;
            cin >> local_r >> local_c;

            x = next.first * 3 + local_r;
            y = next.second * 3 + local_c;
        }
        else {
            cout << "\nYou can play in any board!" << endl;
            cout << "Enter global row (0-8) and column (0-8): ";
            cin >> x >> y;
        }
    }
    else {
        UltimateBoard* board = dynamic_cast<UltimateBoard*>(player->get_board_ptr());
        auto next = board->get_next_board();

        if (next.first != -1) {
            int local_r = rand() % 3;
            int local_c = rand() % 3;
            x = next.first * 3 + local_r;
            y = next.second * 3 + local_c;
        }
        else {
            x = rand() % 9;
            y = rand() % 9;
        }
    }

    return new Move<char>(x, y, symbol);
}

void UltimateBoard_UI::display_rules() const {
    cout << "\n=== ULTIMATE TIC-TAC-TOE RULES ===" << endl;
    cout << "1. There are 9 small 3x3 boards arranged in a 3x3 grid" << endl;
    cout << "2. First move can be anywhere" << endl;
    cout << "3. Next move must be in the board corresponding to the previous move's position" << endl;
    cout << "4. Win a small board by getting 3 in a row" << endl;
    cout << "5. Win the game by winning 3 small boards in a row on the main grid" << endl;
    cout << "6. If sent to a won/drawn board, you can choose any board" << endl;
    cout << "==================================" << endl;
}

void UltimateBoard_UI::display_ultimate_board(const UltimateBoard& board) const {
    board.display();
}