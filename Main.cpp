#include <iostream>
#include <cstdlib>

#include "Numerical_game9/Numerical_PlayManagement.h"
#include "XO_game/XO_Classes.h"
#include "SUS_game/SUS_UI.h"
#include "SUS_game/SUS_PlayManagement.h"
#include "SUS_game/SUS_Player.h"

using namespace std;

void playNumericalTTT();
void playXOGame();
void playSUSGame();
void displayMainMenu();
void clearScreen();

int main() {
    srand(time(0));
    int choice;

    do {
        displayMainMenu();
        cout << "Enter your choice (0-3): ";
        cin >> choice;

        switch (choice) {
        case 1:
            clearScreen();
            playXOGame();
            break;

        case 2:
            clearScreen();
            playNumericalTTT();
            break;

        case 3:
            clearScreen();
            playSUSGame();
            break;

        case 0:
            cout << "\n Thanks for playing! Goodbye!\n";
            break;

        default:
            cout << " Invalid choice! Please enter 0, 1, 2, or 3.\n";
        }

        if (choice != 0) {
            cout << "\nPress Enter to continue...";
            cin.ignore();
            cin.get();
            clearScreen();
        }
    } while (choice != 0);

    return 0;
}

void displayMainMenu() {
    cout << "=========================================\n";
    cout << "                GAME MENU                \n";
    cout << "=========================================\n";
    cout << "  1.  X-O Game (Classic Tic-Tac-Toe)     \n";
    cout << "  2.  Numerical Tic-Tac-Toe              \n";
    cout << "  3.  SUS Game                           \n";
    cout << "  0.  Exit                               \n";
    cout << "=========================================\n";
}

void clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void playNumericalTTT() {
    NumericalPlayManagement game;
    game.run();
}

void playXOGame() {
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

void playSUSGame() {
    SUS_UI ui;
    SUS_PlayManagement manager(&ui);
    manager.run();
}
