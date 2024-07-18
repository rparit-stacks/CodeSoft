#include <windows.h>

#include <algorithm>
#include <climits>
#include <cmath>
#include <iostream>
#include <limits>
#include <string>
#include <vector>

using namespace std;
void pleaseWait() {
    cout << "Please wait.";
    Sleep(1000);
    cout << ".";
    Sleep(1000);
    cout << ".";
    Sleep(1000);
    cout << ".";
}

class Players {
public:
    string playerName;
    char playerSign;
};

class Game {
public:
    Players* playerA;
    Players* playerB;

    vector<vector<char>> gameBoard;
    void displayBoard();
    bool updateBoard(Players* player, int position);
    bool checkWinner();
    void gameStart();
    void resetVector();
    ~Game() {
        delete playerA;
        delete playerB;
        cout << "thank You!";
    }
};

bool Game::checkWinner() {
    for (int i = 0; i < 3; i++) {
        if (gameBoard[i][0] == gameBoard[i][1] &&
                gameBoard[i][1] == gameBoard[i][2] ||
            gameBoard[i][0] == gameBoard[i][1] &&
                gameBoard[i][1] == gameBoard[i][2])
            return true;
    }
    for (int i = 0; i < 3; i++) {
        if (gameBoard[0][i] == gameBoard[1][i] &&
                gameBoard[1][i] == gameBoard[2][i] ||
            gameBoard[0][i] == gameBoard[1][i] &&
                gameBoard[1][i] == gameBoard[2][i])
            return true;
    }
    if (gameBoard[0][0] == gameBoard[1][1] &&
            gameBoard[1][1] == gameBoard[2][2] ||
        gameBoard[0][2] == gameBoard[1][1] &&
            gameBoard[1][1] == gameBoard[2][0])
        return true;

    return false;
}

void Game::resetVector() {
    gameBoard = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
}

bool Game::updateBoard(Players* player, int position) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (gameBoard[i][j] == '0' + position) {
                if (gameBoard[i][j] != 'X' && gameBoard[i][j] != 'O') {
                    gameBoard[i][j] = player->playerSign;
                    return true;
                } else {
                    cout << "This position is already taken by another player!!"
                         << endl;
                    return false;
                }
            }
        }
    }
    cout << "Please Enter a valid Number" << endl;
    return false;
}

void Game::gameStart() {
    playerA = new Players();
    playerB = new Players();
    playerA->playerName = "Player A";
    playerB->playerName = "Player B";

    playerA->playerSign = 'X';
    playerB->playerSign = 'O';
    resetVector();

    displayBoard();
    for (int i = 0; i < 9; i++) {
        int temp;
        Players* currentPlayer = (i % 2 == 0) ? playerA : playerB;
        cout << currentPlayer->playerName
             << " Please Enter the number where you want to put "
             << currentPlayer->playerSign << " : ";
        cin >> temp;

        while (!updateBoard(currentPlayer, temp)) {
            cout << currentPlayer->playerName
                 << " Please Enter a valid number: ";
            cin >> temp;
        }
        displayBoard();
        if (checkWinner()) {
            pleaseWait();
            cout << "\n******************************\n";
            cout << "*  Congratulations " << currentPlayer->playerName
                 << "! You win!  *\n";
            cout << "******************************\n";
            return;
        }
    }
    cout << "It's a draw! Resetting the board...\n";
    pleaseWait();
    resetVector();
    displayBoard();
}

void Game::displayBoard() {
    cout << endl;
    cout << "-------------\n";
    for (int i = 0; i < 3; i++) {
        cout << "| " << gameBoard[i][0] << " | " << gameBoard[i][1] << " | "
             << gameBoard[i][2] << " |\n";
        cout << "-------------\n";
    }
    cout << endl;
}

int main() {
    Game ticTacToe;
    ticTacToe.gameStart();
    cout << endl;
    cout << "Press Enter to Continue...\n";
    getchar();
    pleaseWait();
    ticTacToe.gameStart();

    return 0;
}