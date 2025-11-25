#include "SUS_Board.h"
#include "SUS_UI.h"
#include "BoardGame_Classes.h"

int main() {
    SUS_Board board;
    SUS_UI ui;

    string name1 = "Player1";
    string name2 = "Player2";

    Player<char>* p1 = ui.create_player(name1, 'S', PlayerType::HUMAN);
    Player<char>* p2 = ui.create_player(name2, 'U', PlayerType::HUMAN);

    p1->set_board_ptr(&board);
    p2->set_board_ptr(&board);

    Player<char>* current = p1;

    while (!board.game_is_over(current)) {
        ui.display_board_matrix(board.get_board_matrix());
        Move<char>* mv = ui.get_move(current);
        board.update_board(mv);
        delete mv;

        current = (current == p1 ? p2 : p1);
    }

    ui.display_board_matrix(board.get_board_matrix());
    std::cout << "Game over!\n";
}
