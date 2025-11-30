#include <iostream>
#include <string>
#include "Framework/BoardGame_Classes.h"
#include "XO/XO_Classes.h"
#include "Numerical9/Numerical_Board.h"
#include "Numerical9/Numerical_UI.h"
#include "XO4x4/XO4x4_Board.h"
#include "XO4x4/XO4x4_UI.h"
#include "Obstacles/obstacles_Board.h"
#include "Obstacles/obstacles_UI.h"
#include "Pyramid/Pyramid_Board.h"
#include "Pyramid/Pyramid_UI.h"

using namespace std;



/*------------------------------------------------------ XO Game --------------------------------------------------------------*/
void run_XO() {
	UI<char>* game_ui = new XO_UI();
	Board<char>* xo_board = new X_O_Board();
	Player<char>** players = game_ui->setup_players();
	GameManager<char> x_o_game(xo_board, players, game_ui);
	x_o_game.run();
	delete xo_board;
	for (int i = 0; i < 2; ++i) {
		delete players[i];
	}
	delete[] players;
}
/*-----------------------------------------------------------------------------------------------------------------------------*/


/*----------------------------------------------- Numerical Tic-Tac-Toe Game ---------------------------------------------*/
void run_Numerical9() {
	UI<int>* game_ui = new NumericalUI();
	Board<int>* game_board = new NumericBoard();
	Player<int>** players = game_ui->setup_players();
	GameManager<int> numerical_game(game_board, players, game_ui);
	numerical_game.run();
	delete game_board;
	for (int i = 0; i < 2; ++i) {
		delete players[i];
	}
	delete[] players;
}
/*-----------------------------------------------------------------------------------------------------------------------------*/


/*----------------------------------------------- 4x4 XO Tic-Tac-Toe Game ---------------------------------------------*/
void run_XO4x4() {
	UI<char>* game_ui = new XO4x4_UI();
	Board<char>* board = new XO4x4_Board();
	Player<char>** players = game_ui->setup_players();

	GameManager<char> game(board, players, game_ui);
	game.run();

	delete board;
	for (int i = 0; i < 2; i++)
		delete players[i];
	delete[] players;
}
/*-----------------------------------------------------------------------------------------------------------------------------*/


/*----------------------------------------------- Obstacles Tic-Tac-Toe Game ---------------------------------------------*/
void run_Obstacles() {
	UI<char>* game_ui = new ObstaclesUI();
	Board<char>* board = new ObstaclesBoard();
	Player<char>** players = game_ui->setup_players();

	GameManager<char> game(board, players, game_ui);
	game.run();

	delete board;
	for (int i = 0; i < 2; i++)
		delete players[i];
	delete[] players;
}

/*----------------------------------------------- Pyramid Tic-Tac-Toe Game ---------------------------------------------*/
void run_Pyramid() {
	UI<char>* game_ui = new PyramidUI();
	Board<char>* board = new Pyramid_Board();
	Player<char>** players = game_ui->setup_players();

	GameManager<char> game(board, players, game_ui);
	game.run();

	delete board;
	for (int i = 0; i < 2; i++)
		delete players[i];
	delete[] players;
}


/*------------------------------------------------------Main Menu--------------------------------------------------------------*/
int main() {

	srand(static_cast<unsigned int>(time(0)));

	while (true) {
		cout << "\n=============================\n";
		cout << "\n       GAMES ARENA\n";
		cout << "\n=============================\n\n";
		cout << "1) XO Game\n";
		cout << "2) Numerical Tic-Tac-Toe\n";
		cout << "3) 4x4 XO Tic-Tac-Toe\n";
		cout << "4) Obstacles Tic-Tac-Toe\n";
		cout << "5) Pyramid Tic-Tac-Toe\n";
		cout << "6) Exit\n";
		cout << "\nEnter the Game Number to play: ";

		int choice;
		cin >> choice;

		switch (choice) {

		case 1:
			run_XO();
			break;
	
		case 2:
			run_Numerical9();
			break;

		case 3:
			run_XO4x4();
			break;

		case 4:
			run_Obstacles();
			break;

		case 5:
			run_Pyramid();
			break;
		case 6:
			cout << "\nGoodbye\nReturn to the Arena ASAP!!\n";
			return 0;

		default:
			cout << "Invalid choice. Try Again\n";
		}
		
	}
	return 0;
}