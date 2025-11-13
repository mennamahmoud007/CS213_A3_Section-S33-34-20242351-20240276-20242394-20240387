#include "PlayerManagement.h"

PlayerManager::PlayerManager() {
    srand(time(0)); // Seed random number generator
}

void PlayerManager::recordWin(int playerNumber) {
    if (playerNumber == 1)
        p1Wins++;
    else if (playerNumber == 2)
        p2Wins++;
}

void PlayerManager::recordDraw() {
    draws++;
}

void PlayerManager::showStats() const {
    cout << "\n===== Game Statistics =====\n";
    cout << "Player 1 Wins: " << p1Wins << endl;
    cout << "Player 2 Wins: " << p2Wins << endl;
    cout << "Draws: " << draws << endl;
    cout << "===========================\n";
}

// Pick a random number from available numbers
int PlayerManager::getRandomMove(const vector<int>& availableNumbers) {
    if (availableNumbers.empty()) return -1;
    int index = rand() % availableNumbers.size();
    return availableNumbers[index];
}
