#include "PlayerManagement.h"
#include <algorithm>

PlayerManager::PlayerManager() : draws(0) {
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
}

PlayerManager::~PlayerManager() {
    clear();
}

Player<int>* PlayerManager::addPlayer(const string& name, int sym, PlayerType type, bool oddAllowed) {
    // create a NumericalPlayer (we include Numerical_Player.h above)
    NumericalPlayer* p = new NumericalPlayer(name, sym, type, oddAllowed);
    players.push_back(p);
    wins[p] = 0;
    return p;
}

Move<int>* PlayerManager::getRandomMove(NumericBoard& board, Player<int>* player) {
    if (!player) return nullptr;

    // If player is NumericalPlayer, use its parity rule
    NumericalPlayer* np = dynamic_cast<NumericalPlayer*>(player);

    auto cells = board.available_cells();
    auto nums_all = board.available_nums();

    // filter numbers by parity if possible
    vector<int> nums;
    if (np) {
        for (int v : nums_all) if (np->number_allowed(v)) nums.push_back(v);
    } else {
        nums = nums_all;
    }

    if (cells.empty() || nums.empty()) return nullptr;

    auto c = cells[std::rand() % cells.size()];
    int val = nums[std::rand() % nums.size()];

    return new Move<int>(c.first, c.second, val);
}

void PlayerManager::recordWin(Player<int>* p) {
    if (!p) return;
    wins[p] += 1;
}

void PlayerManager::recordDraw() {
    draws++;
}

void PlayerManager::showAllPlayers() const {
    cout << "\n=== Players & Stats ===\n";
    for (auto pl : players) {
        cout << "Player: " << pl->get_name();
        cout << " | Type: " << (pl->get_type() == PlayerType::HUMAN ? "Human" : "Computer");
        cout << " | Wins: " << wins.at(pl) << "\n";
    }
    cout << "Draws: " << draws << "\n";
    cout << "=======================\n";
}

void PlayerManager::clear() {
    for (auto p : players) delete p;
    players.clear();
    wins.clear();
}
