#include "Numerical_PlayManagement.h"

NumericalPlayManagement::NumericalPlayManagement() {
    string n1, n2;
    cout << "Enter name for Player 1: ";
    cin >> n1;
    cout << "Enter name for Player 2: ";
    cin >> n2;

    p1 = ui.create_player(n1, 1, PlayerType::HUMAN);
    p2 = ui.create_player(n2, 2, PlayerType::HUMAN);

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

        Move<int>* move = ui.get_move(currentPlayer);
        if (!board.update_board(move)) {
            cout << "Invalid move! Try again.\n";
            delete move;
            continue;
        }
        delete move;

        if (board.is_win(currentPlayer)) break;
        if (board.is_draw(currentPlayer)) break;

        switchPlayer();
    }

    ui.display_board(board);
    ui.print_game_result(board);
}
