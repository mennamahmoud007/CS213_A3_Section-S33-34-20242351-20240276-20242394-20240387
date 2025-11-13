#include "Numerical_PlayManagement.h"
#include <iostream>
#include <limits>

using namespace std;

NumericalPlayManagement::NumericalPlayManagement()
    : board(), ui(), p1(nullptr), p2(nullptr), currentPlayer(nullptr) {

    string n1, n2;
    char typeChoice;

    cout << "Enter name for Player 1 (odd numbers 1,3,5,7,9): ";
    getline(cin >> ws, n1);
    cout << "Is " << n1 << " a Computer? (y/n): ";
    cin >> typeChoice;
    PlayerType t1 = (typeChoice == 'y' || typeChoice == 'Y') ? PlayerType::COMPUTER : PlayerType::HUMAN;

    cout << "Enter name for Player 2 (even numbers 2,4,6,8): ";
    cin >> ws;
    getline(cin, n2);
    cout << "Is " << n2 << " a Computer? (y/n): ";
    cin >> typeChoice;
    PlayerType t2 = (typeChoice == 'y' || typeChoice == 'Y') ? PlayerType::COMPUTER : PlayerType::HUMAN;

    // Add players - first player is odd, second is even
    p1 = playerManager.addPlayer(n1.empty() ? "Player1" : n1, 1, t1, true);
    p2 = playerManager.addPlayer(n2.empty() ? "Player2" : n2, 2, t2, false);

    // Set board pointer for players
    p1->set_board_ptr(&board);
    p2->set_board_ptr(&board);

    currentPlayer = p1;
}

NumericalPlayManagement::~NumericalPlayManagement() {
    // PlayerManager owns & deletes players in its destructor
}

void NumericalPlayManagement::switchPlayer() {
    currentPlayer = (currentPlayer == p1) ? p2 : p1;
}

void NumericalPlayManagement::run() {
    bool gameOver = false;

    while (!gameOver) {
        ui.display_board(board);

        Move<int>* move = nullptr;

        if (currentPlayer->get_type() == PlayerType::HUMAN) {
            // Prompt human via UI
            // NumericalUI's get_move will read input directly; re-prompt until update_board accepts it.
            bool got = false;
            while (!got) {
                Move<int>* m = ui.get_move(currentPlayer);
                if (!m) { cout << "Invalid input. Try again.\n"; delete m; continue; }
                if (!board.update_board(m)) {
                    delete m;
                    continue;
                }
                // successful
                delete m; // board.update_board copied/applied, safe to delete
                got = true;
            }
        } else {
            // Computer: ask PlayerManager for a random valid move that respects parity
            move = playerManager.getRandomMove(board, currentPlayer);
            if (!move) {
                cout << "Computer cannot choose a move. Exiting.\n";
                break;
            }
            if (!board.update_board(move)) {
                // If this rarely fails (race/invalid), just delete and try next iteration
                delete move;
                continue;
            }
            delete move;
        }

        // Check win/draw
        if (board.is_win(nullptr)) {
            ui.display_board(board);
            cout << currentPlayer->get_name() << " wins!\n";
            playerManager.recordWin(currentPlayer);
            gameOver = true;
            break;
        }
        if (board.is_draw(nullptr)) {
            ui.display_board(board);
            cout << "Game is a draw.\n";
            playerManager.recordDraw();
            gameOver = true;
            break;
        }

        switchPlayer();
    }

    cout << "\nFinal Board:\n";
    ui.display_board(board);
    playerManager.showAllPlayers();
}
