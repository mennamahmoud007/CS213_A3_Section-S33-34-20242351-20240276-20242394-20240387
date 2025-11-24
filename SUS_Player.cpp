#include "SUS_Player.h"

SUS_Player::SUS_Player(string n, char l) {
    name = n;
    letter = l;
}

string SUS_Player::getName() const {
    return name;
}

char SUS_Player::getLetter() const {
    return letter;
}
