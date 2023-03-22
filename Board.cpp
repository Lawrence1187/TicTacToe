#include <iostream>
#include "Board.h"

using namespace std;

Board::Board() {}

void Board::displayBoardPositions() const
{
    cout << "       |       |       " << endl;
    cout << "   1   |   2   |   3   " << endl;
    cout << "_______|_______|_______" << endl;
    cout << "       |       |       " << endl;
    cout << "   4   |   5   |   6   " << endl;
    cout << "_______|_______|_______" << endl;
    cout << "       |       |       " << endl;
    cout << "   7   |   8   |   9   " << endl;
    cout << "       |       |       " << endl;
    cout << endl;
}

void Board::displayBoardState(string state[]) const
{
    cout << "       |       |       " << endl;
    cout << "   " << state[0] << "   |   " << state[1] << "   |   " << state[2] << "   " << endl;
    cout << "_______|_______|_______" << endl;
    cout << "       |       |       " << endl;
    cout << "   " << state[3] << "   |   " << state[4] << "   |   " << state[5] << "   " << endl;
    cout << "_______|_______|_______" << endl;
    cout << "       |       |       " << endl;
    cout << "   " << state[6] << "   |   " << state[7] << "   |   " << state[8] << "   " << endl;
    cout << "       |       |       " << endl;
    cout << endl;
}

string Board::checkForGameOver(string state[]) const
{
    // win condition algorithm here
    // win if : -all three elements in a single state are identical
    //          -all three elements in a single column are identical
    //          -all three elements in a diagonal are identical
    // MUST MAKE SURE that the element being compared to is not " " (empty space)
    string result = "continue";
    if ((state[0] == state[1] && state[1] == state[2]) || (state[0] == state[3] && state[3] == state[6]))
    {
        result = state[0] != " " ? state[0] : result;
    }
    if ((state[3] == state[4] && state[4] == state[5]) || (state[1] == state[4] && state[4] == state[7]) ||
        (state[0] == state[4] && state[4] == state[8]) || (state[2] == state[4] && state[4] == state[6]))
    {
        result = state[4] != " " ? state[4] : result;
    }
    if ((state[6] == state[7] && state[7] == state[8]) || (state[2] == state[5] && state[5] == state[8]))
    {
        result = state[8] != " " ? state[8] : result;
    }
    return result;
}

bool Board::checkForTie(bool slotIsPlayed[], int size)
{
    for (int i = 0; i < size; i++) {
        if (slotIsPlayed[i] == false) {
            return false;
        }
    }
    return true;
}
