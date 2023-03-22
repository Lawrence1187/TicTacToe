#include <iostream>
#include <string>
#include "Board.h"
#include <unordered_map>
#include <limits>

using namespace std;

int main()
{
    Board myBoard;
    cout << "Player 1 (X) - Player 2 (O)" << endl;
    myBoard.displayBoardPositions();
    string state[9] = { " ", " ", " ", " ", " ", " ", " ", " ", " " };
    bool slotIsPlayed[9] = { false, false, false, false, false, false, false, false, false };
    int size = sizeof(slotIsPlayed) / sizeof(slotIsPlayed[0]);
    myBoard.displayBoardState(state);

    bool gameOver = false;
    bool nextTurn = false;
    string winner;
    unordered_map<int, string> players;
    players[1] = "X";
    players[2] = "O";
    int currentPlayer = 1;
    while (gameOver != true)
    {
        while (nextTurn == false)
        {
            int position;
            cout << "Player " << currentPlayer << ", choose a position number to play (1-9): ";
            cin >> position;
            if (cin.fail())
            {
                cout << "Invalid input!" << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            else
            {
                if (position >= 1 && position <= 9)
                {
                    if (slotIsPlayed[position - 1] == false)
                    {
                        state[position - 1] = players.at(currentPlayer);
                        slotIsPlayed[position - 1] = true;
                        gameOver = myBoard.checkForGameOver(state) == "continue" ? false : true;
                        winner = myBoard.checkForGameOver(state) != "continue" ? myBoard.checkForGameOver(state) : winner;
                        nextTurn = true;
                    }
                    else
                    {
                        cout << "Position has already been played!" << endl;
                    }
                }
                else
                {
                    cout << "Invalid input!" << endl;
                }
            }
        }

        myBoard.displayBoardState(state);

        if (myBoard.checkForTie(slotIsPlayed, size) == true)
        {
            cout << "Game is tied!" << endl;
            return 0;
        }

        if (gameOver == true)
        {
            cout << "Winner is Player " << (winner == "X" ? 1 : 2) << "!";
        }
        else
        {
            currentPlayer = currentPlayer == 1 ? 2 : 1;
            nextTurn = false;
        }
    }

    return 0;
}
