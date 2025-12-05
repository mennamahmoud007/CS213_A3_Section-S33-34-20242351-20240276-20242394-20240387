#include "Numerical_UI.h"
#include <iostream>
#include <iomanip>



Player<int>* NumericalUI::create_player(string& name, int symbol, PlayerType type) {
    cout << "Creating " << (type == PlayerType::HUMAN ? "human" : "computer")
        << " player: " << name;

    if (symbol == 'X')
        cout << " (EVEN numbers player)\n";
    else
        cout << " (ODD numbers player)\n";

    return new Player<int>(name, symbol, type);
}

Move<int>* NumericalUI::get_move(Player<int>* player) {
    int x, y, val;

    //int symbol = 0; /*? EVEN numbers only*/
    //int symbol = 1; /*? ODD numbers only*/
    bool isEvenPlayer = (player->get_symbol() == 'X');

    while (true) {
        if (player->get_type() == PlayerType::HUMAN) {
            cout << "\nEnter row (0-2), column (0-2), and number (1-9): ";
            cin >> x >> y >> val;
        }
        else {
            // Random position
            Board<int>* board = player->get_board_ptr();
            x = rand() % board->get_rows();
            y = rand() % board->get_columns();

            // Random number respecting parity
            if (isEvenPlayer) {
                int evens[] = { 2, 4, 6, 8 };
                val = evens[rand() % 4];
            }
            else {
                int odds[] = { 1, 3, 5, 7, 9 };
                val = odds[rand() % 5];
            }
        }

        // Block wrong parity
        if (isEvenPlayer && val % 2 != 0) {
            cout << "You can only choose EVEN numbers (2,4,6,8).\n";
            continue;
        }
        if (!isEvenPlayer && val % 2 != 1) {
            cout << "You can only choose ODD numbers (1,3,5,7,9).\n";
            continue;
        }

        return new Move<int>(x, y, val);
    }
}

void NumericalUI::display_rules() {
    cout << "\n=== NUMERICAL TIC-TAC-TOE RULES ===" << endl;
    cout << "1. Board is 3x3" << endl;
    cout << "2. Player 1 uses odd numbers" << endl;
    cout << "3. Player 2 uses even numbers" << endl;
    cout << "4. Each number can be used once" << endl;
    cout << "5. Any line summing to 15 wins" << endl;
    cout << "====================================" << endl;
}


//void NumericalUI::print_game_result(NumericBoard& board) {
//    cout << "Game over!\n";
//    if (board.is_draw(nullptr)) cout << "It's a draw!\n";
//    else cout << "We have a winner!\n";
//}
