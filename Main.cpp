#include <iostream>
#include <string>
#include "Framework/BoardGame_Classes.h"
#include "XO/XO_Classes.h"
#include "Numerical9/Numerical_Board.h"
#include "Numerical9/Numerical_UI.h"
#include "Misere/Misere_Board.h"
#include "Misere/Misere_UI.h"
#include "SUS/SUS_Board.h"
#include "SUS/SUS_UI.h"

using namespace std;

/*------------------------------------------------------ XO Game --------------------------------------------------------------*/
void run_XO() {
	cout << "\nWelcome to X-O Game...\n";

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

/*----------------------------------------------- Misère Tic-Tac-Toe Game ---------------------------------------------*/
void run_Misere() {
	cout << "\nWelcome to Misère Tic-Tac-Toe Game...\n";

	UI<char>* game_ui = new Misere_UI();
	Board<char>* game_board = new Misere_Board();
	Player<char>** players = game_ui->setup_players();
	GameManager<char> Misere_game(game_board, players, game_ui);
	Misere_game.run();
	delete game_board;
	for (int i = 0; i < 2; ++i) {
		delete players[i];
	}
	delete[] players;
}
/*-----------------------------------------------------------------------------------------------------------------------------*/


/*----------------------------------------------- Numerical Tic-Tac-Toe Game ---------------------------------------------*/
void run_Numerical9() {
	cout << "\nWelcome to Numerical Tic-Tac-Toe Game...\n";

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

/*------------------------------------------------------ SUS Game --------------------------------------------------------------*/
void run_SUS() {
	cout << "\nWelcome to SUS Game...\n";
	UI<char>* game_ui = new SUS_UI();
	Board<char>* game_board = new SUS_Board();
	Player<char>** players = game_ui->setup_players();
	GameManager<char> sus_game(game_board, players, game_ui);
	sus_game.run();
	delete game_board;
	for (int i = 0; i < 2; ++i) {
		delete players[i];
	}
	delete[] players;
	delete game_ui;
}

/*------------------------------------------------------Main Menu--------------------------------------------------------------*/
int main() {

	int main() {
		srand(static_cast<unsigned int>(time(0)));
		while (true) {
			cout << "\n=============================\n";
			cout << "\n       GAMES ARENA\n";
			cout << "\n=============================\n";
			cout << "1) XO Game\n";
			cout << "2) Numerical Tic-Tac-Toe\n";
			cout << "3) Misere Tic-Tac-Toe\n";
			cout << "4) SUS Game\n";
			cout << "5) Exit\n";
			cout << "\nEnter the Game Number to play\n";
			int choice;
			cin >> choice;
			switch (choice) {
			case 1: run_XO(); break;
			case 2: run_Numerical9(); break;
			case 3: run_Misere(); break;
			case 4: run_SUS(); break;
			case 5:
				cout << "Goodbye\nReturn to the Arena ASAP!!\n";
				return 0;
			default:
				cout << "Invalid choice. Try Again\n";
			}
		}
		return 0;
	}
	/*-----------------------------------------------------------------------------------------------------------------------------*/