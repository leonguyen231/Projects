#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Define a type alias for simplifying nested vector declaration
using Board = vector<vector<char> >;

// Function prototypes
void printBoard(const Board& board);
bool isMoveValid(const Board& board, int row, int col);
bool checkForWin(const Board& board, char player);
bool isBoardFull(const Board& board);

int main() {
    Board board(3, vector<char>(3, ' ')); // Initialize an empty 3x3 board
    bool player1Turn = true; // Player 1 starts first
    int row, col;
    bool gameover = false;

    cout << "Welcome to Tic-Tac-Toe!" << endl;
    cout << "Player 1 (X) - Player 2 (O)" << endl << endl;

    while (!gameover) {
        // Print the current board
        printBoard(board);

        // Determine current player
        char currentPlayer = (player1Turn) ? 'X' : 'O';
        cout << "Player " << ((player1Turn) ? "1" : "2") << " (" << currentPlayer << ") - Enter your move (row and column): ";
        cin >> row >> col;

        // Adjust for zero-indexed board
        row--;
        col--;

        // Check if the move is valid
        if (isMoveValid(board, row, col)) {
            // Make the move
            board[row][col] = currentPlayer;

            // Check if the current player wins
            if (checkForWin(board, currentPlayer)) {
                printBoard(board);
                cout << "Player " << ((player1Turn) ? "1" : "2") << " wins! Congratulations!" << endl;
                gameover = true;
            } else if (isBoardFull(board)) {
                // Check if the board is full (tie)
                printBoard(board);
                cout << "It's a tie!" << endl;
                gameover = true;
            } else {
                // Switch turns
                player1Turn = !player1Turn;
            }
        } else {
            cout << "Invalid move! Please try again." << endl;
        }
    }

    return 0;
}

// Function to print the current board
void printBoard(const Board& board) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cout << board[i][j];
            if (j < 2) cout << " | ";
        }
        cout << endl;
        if (i < 2) cout << "---------" << endl;
    }
    cout << endl;
}

// Function to check if a move is valid
bool isMoveValid(const Board& board, int row, int col) {
    // Check if the chosen cell is empty
    return (board[row][col] == ' ');
}

// Function to check if a player has won
bool checkForWin(const Board& board, char player) {
    // Check rows and columns
    for (int i = 0; i < 3; ++i) {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
            (board[0][i] == player && board[1][i] == player && board[2][i] == player)) {
            return true;
        }
    }

    // Check diagonals
    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player)) {
        return true;
    }

    return false;
}

// Function to check if the board is full
bool isBoardFull(const Board& board) {
    // Check if there are any empty cells left
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (board[i][j] == ' ') {
                return false;
            }
        }
    }
    return true;
}