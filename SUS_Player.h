#ifndef SUS_PLAYER_H
#define SUS_PLAYER_H

#include <string>
using namespace std;

class SUS_Player {
private:
    string name;
    char letter; // 'S' or 'U'

public:
    SUS_Player(string n, char l);

    string getName() const;
    char getLetter() const;
};

#endif
