#include "Diamond_Board.h"
#include <iostream>
#include <cmath>
#include <set>

using namespace std;

//  0 = horiz, 1 = vert, 2 = diag \, 3 = diag /
static const int dr[4] = { 0, 1, 1, 1 };
static const int dc[4] = { 1, 0, 1, -1 };

Diamond_Board::Diamond_Board() : Board<char>(9, 9) {
    
    for (int r = 0; r < rows; ++r) {
        for (int c = 0; c < columns; ++c) {
            if (abs(r - center) + abs(c - center) <= 4)
                board[r][c] = blank;
            else
                board[r][c] = invalid;
        }
    }
    n_moves = 0;
}

Diamond_Board::~Diamond_Board() {}

bool Diamond_Board::valid_cell(int r, int c) const {
    if (r < 0 || r >= rows || c < 0 || c >= columns) return false;
    return (abs(r - center) + abs(c - center) <= 4);
}

vector<int> Diamond_Board::find_line_directions(char sym, int length) const {
    set<int> dirs_set;

    for (int r = 0; r < rows; ++r) {
        for (int c = 0; c < columns; ++c) {
            if (!valid_cell(r, c)) continue;
            if (board[r][c] != sym) continue;

            for (int d = 0; d < 4; ++d) {
                bool ok = true;
                for (int k = 0; k < length; ++k) {
                    int nr = r + dr[d] * k;
                    int nc = c + dc[d] * k;
                    if (!valid_cell(nr, nc) || board[nr][nc] != sym) { ok = false; break; }
                }
                if (!ok) continue;

               
                int pr = r - dr[d];
                int pc = c - dc[d];
                if (valid_cell(pr, pc) && board[pr][pc] == sym) continue;

                dirs_set.insert(d);
            }
        }
    }

    return vector<int>(dirs_set.begin(), dirs_set.end());
}

bool Diamond_Board::update_board(Move<char>* move) {
    if (!move) return false;
    int x = move->get_x();
    int y = move->get_y();
    char sym = move->get_symbol();

    if (!valid_cell(x, y)) {
        cout << "Invalid position (not inside diamond). Try again.\n";
        return false;
    }
    if (board[x][y] != blank) {
        cout << "Cell is not empty.\n";
        return false;
    }

    board[x][y] = sym;
    ++n_moves;
    return true;
}

bool Diamond_Board::is_win(Player<char>* player) {
    if (!player) return false;
    char sym = player->get_symbol();

    vector<int> dirs3 = find_line_directions(sym, 3);
    vector<int> dirs4 = find_line_directions(sym, 4);

    for (int d3 : dirs3)
        for (int d4 : dirs4)
            if (d3 != d4) return true;

    return false;
}

bool Diamond_Board::is_lose(Player<char>* player) {
    
    return false;
}

bool Diamond_Board::is_draw(Player<char>* /*player*/) {
    
    for (int r = 0; r < rows; ++r)
        for (int c = 0; c < columns; ++c)
            if (valid_cell(r, c) && board[r][c] == blank) return false;
    return true;
}

bool Diamond_Board::game_is_over(Player<char>* player) {
    return is_win(player) || is_draw(player);
}

void Diamond_Board::display_board() {
    cout << "\nDiamond Board:\n";
    for (int r = 0; r < rows; ++r) {
        int indent = abs(center - r);
        for (int s = 0; s < indent; ++s) cout << "  ";
        for (int c = 0; c < columns; ++c) {
            if (!valid_cell(r, c)) cout << "  ";
            else cout << board[r][c] << " ";
        }
        cout << "\n";
    }
}

void Diamond_Board::apply_move(int r, int c, char sym) {
    board[r][c] = sym; 
    n_moves++;
}

void Diamond_Board::undo_move(int r, int c) {
    board[r][c] = blank; 
    n_moves--;
}

vector<pair<int, int>> Diamond_Board::get_empty_cells() const {
    vector<pair<int, int>> empties;
    for (int r = 0; r < rows; ++r){
        for (int c = 0; c < columns; ++c){
            if (valid_cell(r, c) && board[r][c] == blank){
                empties.push_back({ r, c });
            }
        }
    }
    return empties;
}