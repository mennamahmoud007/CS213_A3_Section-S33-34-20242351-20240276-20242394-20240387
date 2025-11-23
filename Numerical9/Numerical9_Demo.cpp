
#include <iostream>
#include <string>
#include <ctime>

#include "BoardGame_Classes.h"
#include "Numerical_UI.h"
#include "Numerical_Board.h"

using namespace std;

int main()
{
    srand(static_cast<unsigned int>(time(0)));  // Seed RNG

    // Create the Numerical Game UI
    UI<int>* game_ui = new NumericalUI();

    // Create the numerical 3×3 board
    Board<int>* game_board = new NumericBoard();

    // UI creates 2 players (EVEN & ODD based on your modifications)
    Player<int>** players = game_ui->setup_players();

    // Create the game manager
    GameManager<int> numerical_game(game_board, players, game_ui);

    // Start the game loop
    numerical_game.run();

    // ---- Cleanup ----
    delete game_board;

    for (int i = 0; i < 2; ++i)
        delete players[i];

    delete[] players;

    // Program ended successfully
    return 0;
}