#ifndef SUS_BOARD_H
#define SUS_BOARD_H

#include <vector>
#include <string>
using namespace std;

class SUS_Board {
private:
    vector<vector<char>> grid;

public:
    SUS_Board();
    bool isFull();
    bool isEmpty(int r, int c);
    void place(int r, int c, char ch);
    void removeCell(int r, int c);
    int countSUS();
    void print();
};

#endif
