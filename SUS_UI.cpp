#include "SUS_UI.h"
#include <iostream>

using namespace std;

void SUS_UI::runDemo() {
    cout << "==== SUS Game Simulation ====\n";

    string name1, name2;
    cout << "Enter Player 1 name: ";
    cin >> name1;

    cout << "Enter Player 2 name: ";
    cin >> name2;

    SUS_Player p1(name1, 'S');
    SUS_Player p2(name2, 'U');

    SUS_PlayManagement manager(p1, p2);

    cout << "Simulating all possible games...\n";
    manager.simulateGame();

    manager.printBest();
}
