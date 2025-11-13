#include <iostream>
#include <cstdlib>
#include <ctime>

// ===== Include both games here =====
#include "Numerical_game9/Numerical_PlayManagement.h"
#include "XO_game/XO_Classes.h"

using namespace std;

// Function declarations
void playNumericalTTT();
void playXOGame();

int main() {
    srand(static_cast<unsigned>(time(0)));
    int choice;

    do {
        cout << "==============================\n";
        cout << "       GAME COLLECTION        \n";
        cout << "==============================\n";
        cout << "1. Play X-O Game\n";
        cout << "2. Play Numerical Tic-Tac-Toe\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            playXOGame();
            break;
        case 2:
            playNumericalTTT();
            break;
        case 0:
            cout << "Thanks for playing! Goodbye!\n";
            break;
        default:
            cout << "Invalid choice! Please try again.\n";
        }

        cout << endl;
    } while (choice != 0);

    return 0;
}

// ================= NUMERICAL TTT =================
void playNumericalTTT() {
    cout << "\n=== Starting Numerical Tic-Tac-Toe ===\n";
    NumericalPlayManagement game;
    game.run();
    cout << "Returning to main menu...\n";
}

// ================= X-O GAME =================
void playXOGame() {
    cout << "\n=== Starting X-O Game ===\n";
    X_O_Board* board = new X_O_Board();
    XO_UI* ui = new XO_UI();
    Player<char>** players = ui->setup_players();

    GameManager<char> gameManager(board, players, ui);
    gameManager.run();

    delete players[0];
    delete players[1];
    delete[] players;
    delete ui;
    delete board;

    cout << "Returning to main menu...\n";
}
