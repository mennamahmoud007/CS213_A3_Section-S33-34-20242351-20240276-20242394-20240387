#include "Numerical_PlayManagement.h"
#include <iostream>
using namespace std;

NumericalPlayManagement::NumericalPlayManagement() {
    string n1, n2;
    char typeChoice;

    cout << "Enter name for Player 1: ";
    cin >> n1;
    cout << "Is " << n1 << " a Computer? (y/n): ";
    cin >> typeChoice;
    PlayerType t1 = (typeChoice == 'y' || typeChoice == 'Y') ? PlayerType::COMPUTER : PlayerType::HUMAN;

    cout << "Enter name for Player 2: ";
    cin >> n2;
    cout << "Is " << n2 << " a Computer? (y/n): ";
    cin >> typeChoice;
    PlayerType t2 = (typeChoice == 'y' || typeChoice == 'Y') ? PlayerType::COMPUTER : PlayerType::HUMAN;

    // Add players using the manager
    p1 = playerManager.addPlayer(n1, 1, t1);
    p2 = playerManager.addPlayer(n2, 2, t2);

    // Connect board to players
    p1->set_board(&board);
    p2->set_board(&board);

    currentPlayer = p1;
}

void NumericalPlayManagement::switchPlayer() {
    currentPlayer = (currentPlayer == p1) ? p2 : p1;
}

void NumericalPlayManagement::run() {
    while (!board.game_is_over(currentPlayer)) {
        ui.display_board(board);

        Move<int>* move = nullptr;

        // Get move depending on player type
        if (currentPlayer->get_type() == PlayerType::HUMAN) {
            move = ui.get_move(currentPlayer);
        }
        else {
            move = playerManager.getRandomMove(board, currentPlayer);
        }

        if (!move) {
            cout << "Invalid move.\n";
            continue;
        }

        if (!board.update_board(move)) {
            cout << "Invalid move! Try again.\n";
            delete move;
            continue;
        }
        delete move;

        if (board.is_win(currentPlayer)) {
            cout << "\n" << currentPlayer->getName() << " wins!\n";
            currentPlayer->addWin();
            (currentPlayer == p1 ? p2 : p1)->addLoss();
            break;
        }

        if (board.is_draw(currentPlayer)) {
            cout << "\nThe game is a draw.\n";
            p1->addDraw();
            p2->addDraw();
            break;
        }

        switchPlayer();
    }

    cout << "\nFinal Board:\n";
    ui.display_board(board);

    cout << "\nPlayer Statistics:\n";
    playerManager.showAllPlayers();
}

