#include <iostream>
#include <string>
#include "Framework/BoardGame_Classes.h"
#include "XO/XO_Classes.h"
#include "Numerical9/Numerical_Board.h"
#include "Numerical9/Numerical_UI.h"
#include "Misere/Misere_Board.h"
#include "Misere/Misere_UI.h"
#include "Obstacles/Obstacles_Board.h"
#include "Obstacles/Obstacles_UI.h"
#include "XO4x4/XO4x4_Board.h"
#include "XO4x4/XO4x4_UI.h"
#include "FiveByFive/FiveByFive_Board.h"
#include "FiveByFive/FiveByFive_UI.h"
#include "Infinity/Infinity_Board.h"
#include "Infinity/Infinity_UI.h"
#include "SUS/SUS_Board.h"
#include "SUS/SUS_UI.h"
#include "WordGame/Word_Board.h"
#include "WordGame/Word_Board_UI.h"
#include "Ultimate/Ultimate_Board.h"
#include "Ultimate/Ultimate_Board_UI.h"


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


/*------------------------------------------------------ SUS Game --------------------------------------------------------------*/
void run_SUS() {
	UI<char>* game_ui = new SUS_UI();
	Board<char>* game_board = new SUS_Board();
	Player<char>** players = game_ui->setup_players();
	GameManager<char> sus_game(game_board, players, game_ui);
	sus_game.run();

	SUS_Board* _board = dynamic_cast<SUS_Board*>(game_board);
	if (_board) {
		int s_score = _board->score_S;
		int u_score = _board->score_U;

		cout << "\n=== FINAL SCORE ===" << endl;
		    cout << "Player 1 (S) score: " << s_score << "\n";
		    cout << "Player 2 (U) score: " << u_score << "\n";

		if (s_score > u_score) {
			cout << "Winner: Player 1 (S)\n";
		}
		else if (u_score > s_score) {
			cout << "Winner: Player 2 (U)\n";
		}
		else {
			cout << "It\'s a DRAW!\n";
		}
	}

	delete game_board;
	for (int i = 0; i < 2; ++i) {
		delete players[i];
	}
	delete[] players;
	delete game_ui;
}
/*-----------------------------------------------------------------------------------------------------------------------------*/


/*------------------------------------------------------ FiveByFive Game --------------------------------------------------------------*/
void run_FiveByFive() {
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


/*----------------------------------------------- Misère Tic-Tac-Toe Game ---------------------------------------------*/
void run_Misere() {
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
/*-----------------------------------------------------------------------------------------------------------------------------*/


/*----------------------------------------------- Infinity Tic-Tac-Toe Game ---------------------------------------------*/
void run_Infinity() {
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


/*----------------------------------------------------------- WordGame --------------------------------------------------------*/
void run_WordGame() {

	WordUI* word_ui = new WordUI();
	WordBoard* word_board = new WordBoard();

	word_ui->display_word_rules();

	Player<char>** players = word_ui->setup_players();
	GameManager<char> word_game(word_board, players, word_ui);
	word_game.run();

	delete word_board;
	for (int i = 0; i < 2; ++i) {
		delete players[i];
	}
	delete[] players;
	delete word_ui;
}
/*-----------------------------------------------------------------------------------------------------------------------------*/


/*------------------------------------------------------ Ultimate Tic-Tac-Toe --------------------------------------------------------------*/
void run_Ultimate() {
	UltimateBoard_UI* ultimate_ui = new UltimateBoard_UI();
	UltimateBoard* ultimate_board = new UltimateBoard();
	ultimate_ui->display_rules();
	Player<char>** players = ultimate_ui->setup_players();
	GameManager<char> ultimate_game(ultimate_board, players, ultimate_ui);
	ultimate_game.run();
	delete ultimate_board;
	for (int i = 0; i < 2; ++i) {
		delete players[i];
	}
	delete[] players;
	delete ultimate_ui;
}

/*------------------------------------------------------Main Menu--------------------------------------------------------------*/

	int main() {
		srand(static_cast<unsigned int>(time(0)));
		while (true) {
			cout << "\n=============================\n";
			cout << "\n       GAMES ARENA\n";
			cout << "\n=============================\n";
			cout << "1) XO Game\n";
			cout << "2) 5x5 Tic-Tac-Toe\n";
			cout << "3) Misere Tic-Tac-Toe\n";
			cout << "4) 4x4 XO Tic-Tac-Toe\n";
			cout << "5) SUS Tic-Tac-Toe\n";
			cout << "6) Numerical Tic-Tac-Toe\n";
			cout << "7) Obstacles Tic-Tac-Toe\n";
			cout << "8) Infinity Tic-Tac-Toe\n";
			cout << "11) Word Tic-Tac-Toe\n";
			cout << "12) Ultimate Tic-Tac-Toe\n";
			
			cout << "9) Exit\n";
			cout << "\nEnter the Game Number to play: ";
			int choice;
			cin >> choice;
			switch (choice) {
			case 1: run_XO(); break;
			case 2: run_FiveByFive(); break;
			case 3: run_Misere(); break;
			case 4: run_XO4x4(); break;
			case 5: run_SUS(); break;
			case 6: run_Numerical9(); break;
			case 7: run_Obstacles(); break;
			case 8: run_Infinity(); break;
			case 11: run_WordGame(); break;
			case 12: run_Ultimate(); break;
			case 9:
				cout << "Goodbye\nReturn to the Arena ASAP!!\n";
				return 0;
			default:
				cout << "Invalid choice. Try Again\n";
			}
		}
		return 0;
	}


