#include <iostream>
#include <string>
#include "Framework/BoardGame_Classes.h"
#include "XO/XO_Classes.h"
#include "Numerical9/Numerical_Board.h"
#include "Numerical9/Numerical_UI.h"
#include "Misere/Misere_Board.h"
#include "Misere/Misere_UI.h"
#include "FiveByFive/FiveByFive_Board.h"
#include "FiveByFive/FiveByFive_UI.h"
#include "Infinity/Infinity_Board.h"
#include "Infinity/Infinity_UI.h"


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

// ---------------------------------------------- - 5x5 Tic - Tac - Toe Game----------------------------------------------------
void run_FiveByFive() {
	cout << "\nWelcome to 5x5 Tic-Tac-Toe Game...\n";

	UI<char>* game_ui = new FiveByFive_UI();
	Board<char>* game_board = new FiveByFive_Board();
	Player<char>** players = game_ui->setup_players();
	GameManager<char> fivebyfive_game(game_board, players, game_ui);
	fivebyfive_game.run();

	// Determine winner based on three-in-a-row sequences
	FiveByFive_Board* fb_board = dynamic_cast<FiveByFive_Board*>(game_board);
	if (fb_board) {
		int x_score = fb_board->count_three_in_row('X');
		int o_score = fb_board->count_three_in_row('O');

		cout << "\n=== FINAL SCORE ===" << endl;
		cout << "Player X: " << x_score << " three-in-a-row sequences" << endl;
		cout << "Player O: " << o_score << " three-in-a-row sequences" << endl;

		if (x_score > o_score) {
			cout << "Player X wins!" << endl;
		}
		else if (o_score > x_score) {
			cout << "Player O wins!" << endl;
		}
		else {
			cout << "It's a tie!" << endl;
		}
	}

	delete game_board;
	for (int i = 0; i < 2; ++i) {
		delete players[i];
	}
	delete[] players;
}
/*-----------------------------------------------------------------------------------------------------------------------------*/

/*----------------------------------------------- Numerical Tic-Tac-Toe Game ---------------------------------------------*/
void run_Infinity() {
	cout << "\nWelcome to Infinity Tic-Tac-Toe...\n";

	UI<char>* game_ui = new Infinity_UI();
	Board<char>* game_board = new Infinity_Board();
	Player<char>** players = game_ui->setup_players();
	GameManager<char> infinity_game(game_board, players, game_ui);
	infinity_game.run();

	delete game_board;
	for (int i = 0; i < 2; ++i) delete players[i];
	delete[] players;
}
/*-----------------------------------------------------------------------------------------------------------------------------*/


/*------------------------------------------------------Main Menu--------------------------------------------------------------*/
int main() {

	srand(static_cast<unsigned int>(time(0)));

	while (true) {
		cout << "\n=============================\n";
		cout << "\n       GAMES ARENA\n";
		cout << "\n=============================\n";
		cout << "1) XO Game\n";
		cout << "3) 5x5 Tic-Tac-Toe\n";
		cout << "5) Misere Tic-Tac-Toe\n";
		cout << "9) Numerical Tic-Tac-Toe\n";
		cout << "11) Infinity Tic-Tac-Toe\n";
		cout << "14) Exit\n";
		cout << "\nEnter the Game Number to play\n";

		int choice;
		cin >> choice;

		switch (choice) {

		case 1:
			run_XO();
			break;
	
		case 3:
			run_FiveByFive();
			break;

		case 5:
			run_Misere();
			break;

		case 9:
			run_Numerical9();
			break;

		case 11:
			run_Infinity();
			break;

		case 14:
			cout << "Goodbye\nReturn to the Arena ASAP!!\n";
			return 0;

		default:
			cout << "Invalid choice. Try Again\n";
		}
		
	}
	return 0;
}