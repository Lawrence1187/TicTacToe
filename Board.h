#pragma once
#include <string>

using namespace std;

class Board {
public:
    Board();
    void displayBoardPositions() const;
    void displayBoardState(string state[]) const;
    string checkForGameOver(string state[]) const;
    bool checkForTie(bool slotIsPlayed[], int size);
};
