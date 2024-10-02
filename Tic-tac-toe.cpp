#include <iostream>
using namespace std;

char board[3][3] = {{'1','2','3'}, {'4','5','6'}, {'7','8','9'}};

void showBoard(){
    for(int i = 0; i < 3; i ++){
        for(int j = 0; j < 3; j++){
            cout << board[i][j] << " | ";
        }
        cout << endl;
        if (i < 2){
            cout << "------------" << endl;
        }
    }
}

bool checkWin(char player) {
    //rows
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) {
            return true;
        }
    }

    //columns
    for (int j = 0; j < 3; j++) {
        if (board[0][j] == player && board[1][j] == player && board[2][j] == player) {
            return true;
        }
    }

    //diagonals
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
        return true;
    }
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) {
        return true;
    }

    return false;
}

bool boardFull() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == '1' || board[i][j] == '2' || board[i][j] == '3' || board[i][j] == '4' || board[i][j] == '5' || board[i][j] == '6' || board[i][j] == '7' || board[i][j] == '8' || board[i][j] == '9') {
                return false;
            }
        }
    }
    return true;
}

int main(){
    cout << "\n\tTic Tac Toe" << endl; 
    char playerOne = 'X';
    char playerTwo = 'O';
    int turn = 0;
    cout << "Player 1 (X)  -  Player 2 (O)\n" << endl;
    int choice;
    while (true)
    {
        showBoard();
        if(turn == 0){
            cout << "\nPlayer 1, enter a number: ";
            cin >> choice;
            cout << endl;
            int row = (choice - 1) / 3;
            int col = (choice - 1) % 3;
            board[row][col] = playerOne;
            turn++;
        }
        else{
            cout << "\nPlayer 2, enter a number: ";
            cin >> choice;
            cout << endl;
            int row = (choice - 1) / 3;
            int col = (choice - 1) % 3;
            board[row][col] = playerTwo;
            turn--;
        }
        if(checkWin(playerOne)){
            showBoard();
            cout << "\n==> Player 1 wins!" << endl;
            break;
        }
        else if(checkWin(playerTwo)) {
            showBoard();
            cout << "\n==> Player 2 wins!" << endl;
            break;
        }
        else if(boardFull()){
            showBoard();
            cout << "\nIt's a draw!" << endl;
            break;
        }
        system("clear");
    }
    

    return 0;
}