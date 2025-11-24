#include "SUS_UI.h"
#include "SUS_Board.h"
#include <limits>

SUS_UI::SUS_UI(bool fixedLetterMode_) : fixedLetterMode(fixedLetterMode_) {
    playerLetterMap[0] = playerLetterMap[1] = ' ';
}

void SUS_UI::display_board_matrix(const std::vector<std::vector<char>>& matrix) {
    std::cout << "\n  0 1 2\n";
    for (size_t r = 0; r < matrix.size(); ++r) {
        std::cout << r << ' ';
        for (size_t c = 0; c < matrix[r].size(); ++c) {
            char ch = matrix[r][c];
            if (ch == ' ') std::cout << ".";
            else std::cout << ch;
            if (c < matrix[r].size() - 1) std::cout << ' ';
        }
        std::cout << '\n';
    }
}

void SUS_UI::display_message(const std::string& msg) {
    std::cout << msg << std::endl;
}

void SUS_UI::ask_players_for_letters(Player<char>* p1, Player<char>* p2) {
    // Try to read player indexes from Player (if framework has method get_index or symbol).
    // As a fallback ask interactively and map to 0 and 1 in input order.
    std::cout << "\nChoose letter for Player 1 (S or U): ";
    char ch;
    while (true) {
        std::cin >> ch;
        ch = toupper(ch);
        if (ch == 'S' || ch == 'U') break;
        std::cout << "Invalid. Enter S or U: ";
    }
    playerLetterMap[0] = ch;

    std::cout << "Choose letter for Player 2 (S or U): ";
    while (true) {
        std::cin >> ch;
        ch = toupper(ch);
        if (ch == 'S' || ch == 'U') break;
        std::cout << "Invalid. Enter S or U: ";
    }
    playerLetterMap[1] = ch;
}

Move<char>* SUS_UI::get_move(Player<char>* p) {
    // We assume Player has a method get_name() and possibly an index.
    // If your Player stores type (HUMAN/COMPUTER) use it to decide input vs AI.
    std::string pname = p->get_name();
    int pidx = p->get_id(); // **ADAPT**: If framework does not have get_id(), remove and set mapping externally.

    char letterToPlace = playerLetterMap[pidx];
    if (letterToPlace == ' ') {
        // fallback: ask user for letter each turn (if not fixed)
        std::cout << pname << " - choose letter (S or U): ";
        char ch;
        while (true) {
            std::cin >> ch;
            ch = toupper(ch);
            if (ch == 'S' || ch == 'U') break;
            std::cout << "Invalid input. Enter S or U: ";
        }
        letterToPlace = ch;
    }

    int r, c;
    std::cout << pname << " - enter row (0..2): ";
    while (!(std::cin >> r) || r < 0 || r > 2) {
        std::cout << "Invalid. Enter row 0..2: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    std::cout << pname << " - enter col (0..2): ";
    while (!(std::cin >> c) || c < 0 || c > 2) {
        std::cout << "Invalid. Enter col 0..2: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    SUS_Move* mv = new SUS_Move(r, c, letterToPlace, pidx);
    return mv;
}
