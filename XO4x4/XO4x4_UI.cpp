#include "XO4x4_UI.h"
#include <iostream>
using namespace std;

XO4x4_UI::XO4x4_UI() : UI<char>("Welcome to 4x4 Moving XO Game", 3) {}

Player<char>* XO4x4_UI::create_player(string& name, char symbol, PlayerType type) {
    cout << "Creating " << (type == PlayerType::HUMAN ? "human" : "computer")
        << " player: " << name << " (" << symbol << ")\n";
    return new Player<char>(name, symbol, type);
}

Move<char>* XO4x4_UI::get_move(Player<char>* player) {
    /*int x, y;*/

    int x = 0, y = 0, nx = 0, ny = 0;
    Board<char>* b = player->get_board_ptr();
    XO4x4_Board* xb = static_cast<XO4x4_Board*>(b);


    if (player->get_type() == PlayerType::HUMAN) {
        
        cout << "\nEnter the position of the token you want to move (row(0-3) , col(0-3)): ";
        cin >> x >> y;

        cout << "Enter the new position (row(0-3) , col(0-3)): ";
        cin >> nx >> ny;

    }
    else {
        char mySym = player->get_symbol();
        char oppSym = (mySym == 'X' ? 'O' : 'X');
        bool foundMove = false;

        auto moves = xb->get_legal_moves(mySym);
        for (auto& m : moves) {
            int from_x, from_y, to_x, to_y;
            tie(from_x, from_y, to_x, to_y) = m;

            xb->apply_move(from_x, from_y, to_x, to_y, mySym);
            bool win = xb->check_three_in_row(mySym);
            xb->undo_move(from_x, from_y, to_x, to_y, mySym);

            if (win) {
                x = from_x;
                y = from_y;
                nx = to_x;
                ny = to_y;
                foundMove = true;
                break;
            }
        }

        if (!foundMove) {
            auto oppMoves = xb->get_legal_moves(oppSym);
            for (auto& m : oppMoves) {
                int from_x, from_y, to_x, to_y;
                tie(from_x, from_y, to_x, to_y) = m;

                xb->apply_move(from_x, from_y, to_x, to_y, oppSym);
                bool oppWin = xb->check_three_in_row(oppSym);
                xb->undo_move(from_x, from_y, to_x, to_y, oppSym);

                if (oppWin) {
                    for (auto& mm : moves) {
                        int fx, fy, tx, ty;
                        tie(fx, fy, tx, ty) = mm;

                        if (tx == to_x && ty == to_y) {
                            x = fx;
                            y = fy;
                            nx = tx;
                            ny = ty;
                            foundMove = true;
                            break;
                        }
                    }
                }
                if (foundMove) break;
            }
        }

        if (!foundMove) {
            for (auto& m : moves) {
                int fx, fy, tx, ty;
                tie(fx, fy, tx, ty) = m;

                if ((tx == 1 || tx == 2) && (ty == 1 || ty == 2)) {
                    x = fx; y = fy;
                    nx = tx; ny = ty;
                    foundMove = true;
                    break;
                }
            }
        }

        if (!foundMove) {
            if (!moves.empty()) {
                int fx, fy, tx, ty;
                tie(fx, fy, tx, ty) = moves[0];

                x = fx;   y = fy;
                nx = tx;  ny = ty;
                foundMove = true;
            }
        }
    }

    xb->next_nx = nx;
    xb->next_ny = ny;

    return new Move<char>(x, y, player->get_symbol());
}


void XO4x4_UI::display_rules() {
    cout << "\n=== 4x4 MOVING TIC-TAC-TOE RULES ===" << endl;
    cout << "1. Board is 4x4" << endl;
    cout << "2. Each player has 4 tokens" << endl;
    cout << "3. After all tokens are placed, players move them" << endl;
    cout << "4. Moves allowed only to adjacent cells" << endl;
    cout << "5. First to make 3 in a row wins" << endl;
    cout << "======================================" << endl;
}




//x = rand() % b->get_rows();
//y = rand() % b->get_columns();
//
//
//nx = rand() % b->get_rows();
//ny = rand() % b->get_columns();