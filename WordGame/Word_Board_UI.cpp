#include "Word_Board_UI.h"
#include "Word_Board.h"
#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

Player<char>* WordUI::create_player(string& name, char symbol, PlayerType type) {
    cout << "Creating " << (type == PlayerType::HUMAN ? "human" : "computer")
        << " player: " << name << endl;
    return new Player<char>(name, symbol, type);
}

/**
 * @brief Get smart AI move using dictionary-based strategy
 */
Move<char>* WordUI::get_smart_ai_move(WordBoard* wb) {
    auto empties = wb->get_empty_cells();
    if (empties.empty()) return new Move<char>(0, 0, 'A');

    vector<pair<int, int>> positions;
    vector<char> letters;

    for (const auto& pos : empties) {
        int x = pos.first;
        int y = pos.second;

        for (char letter = 'A'; letter <= 'Z'; letter++) {
            if (wb->test_move(x, y, letter)) {
                cout << "[AI] Winning move found: '" << letter
                    << "' at (" << x << "," << y << ")" << endl;
                return new Move<char>(x, y, letter);
            }
        }
    }

    // Strategy 2: Find moves that create promising partial words
    vector<pair<int, int>> promising_positions;

    for (const auto& pos : empties) {
        int x = pos.first;
        int y = pos.second;

        vector<pair<int, int>> neighbors = {
            {x - 1, y}, {x + 1, y}, {x, y - 1}, {x, y + 1},
            {x - 1, y - 1}, {x - 1, y + 1}, {x + 1, y - 1}, {x + 1, y + 1}
        };

        for (const auto& neighbor : neighbors) {
            int nx = neighbor.first;
            int ny = neighbor.second;
            if (nx >= 0 && nx < 3 && ny >= 0 && ny < 3) {
                if (wb->get_cell(nx, ny) != '.') {
                    promising_positions.push_back(pos);
                    break;
                }
            }
        }
    }

    vector<pair<int, int>> prioritized_positions;

    // 1. Center
    if (find(empties.begin(), empties.end(), make_pair(1, 1)) != empties.end()) {
        prioritized_positions.push_back({ 1, 1 });
    }

    // 2. Corners
    vector<pair<int, int>> corners = { {0,0}, {0,2}, {2,0}, {2,2} };
    for (const auto& corner : corners) {
        if (find(empties.begin(), empties.end(), corner) != empties.end()) {
            prioritized_positions.push_back(corner);
        }
    }

    // 3. Edges
    vector<pair<int, int>> edges = { {0,1}, {1,0}, {1,2}, {2,1} };
    for (const auto& edge : edges) {
        if (find(empties.begin(), empties.end(), edge) != empties.end()) {
            prioritized_positions.push_back(edge);
        }
    }

    // Choose position
    int x, y;
    if (!prioritized_positions.empty()) {
        int idx = rand() % prioritized_positions.size();
        x = prioritized_positions[idx].first;
        y = prioritized_positions[idx].second;
    }
    else if (!promising_positions.empty()) {
        int idx = rand() % promising_positions.size();
        x = promising_positions[idx].first;
        y = promising_positions[idx].second;
    }
    else {
        int idx = rand() % empties.size();
        x = empties[idx].first;
        y = empties[idx].second;
    }

    // Choose smart letter based on position
    char letter;
    vector<char> vowels = { 'A', 'E', 'I', 'O', 'U' };
    vector<char> common_consonants = { 'R', 'T', 'N', 'S', 'L', 'C', 'D', 'M', 'P' };

    // If center or corner, use vowel (helps form words)
    if ((x == 1 && y == 1) ||
        (x == 0 && y == 0) || (x == 0 && y == 2) ||
        (x == 2 && y == 0) || (x == 2 && y == 2)) {
        letter = vowels[rand() % vowels.size()];
    }
    else {
        if (rand() % 10 < 6) {
            letter = vowels[rand() % vowels.size()];
        }
        else {
            letter = common_consonants[rand() % common_consonants.size()];
        }
    }

    cout << "[AI] Smart move: '" << letter << "' at (" << x << "," << y << ")" << endl;
    return new Move<char>(x, y, letter);
}

/**
 * @brief Get move from player (human or AI)
 */
Move<char>* WordUI::get_move(Player<char>* player) {
    if (player->get_type() == PlayerType::HUMAN) {
        int x, y;
        char letter;
        cout << "\nEnter row (0-2), column (0-2), and letter: ";
        cin >> x >> y >> letter;
        return new Move<char>(x, y, letter);
    }
    else {
        WordBoard* wb = static_cast<WordBoard*>(player->get_board_ptr());
        return get_smart_ai_move(wb);
    }
}

void WordUI::display_rules() {
    cout << "\n=== WORD TIC-TAC-TOE RULES ===" << endl;
    cout << "1. Place letters (A-Z) on 3x3 board" << endl;
    cout << "2. First player to complete a valid 3-letter word wins!" << endl;
    cout << "3. Words must exist in dictionary" << endl;
    cout << "4. AI uses smart strategy based on dictionary" << endl;
    cout << "===============================" << endl;
}