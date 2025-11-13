#include <iostream>
#include <cstdlib>

using namespace std;

void playNumericalTTT();
void playXOGame();

int main() {
    srand(time(0));
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

void playNumericalTTT() {
#include "Numerical_game9/Numerical_PlayManagement.h"
    NumericalPlayManagement game;
    game.run();
}

void playXOGame() {
#include "XO_game/XO_Classes.h"

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
}
