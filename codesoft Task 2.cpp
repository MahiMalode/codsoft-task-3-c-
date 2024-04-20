#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Function prototypes
void initializeBoard(vector<vector<char>>& board);
void displayBoard(const vector<vector<char>>& board);
bool makeMove(vector<vector<char>>& board, char player, int row, int col);
bool checkWin(const vector<vector<char>>& board, char player);
bool checkDraw(const vector<vector<char>>& board);
void switchPlayer(char& currentPlayer);

int main() {
    char playAgain = 'Y';
    
    while (playAgain == 'Y' || playAgain == 'y') {
        vector<vector<char>> board(3, vector<char>(3, ' ')); // Initialize the game board
        char currentPlayer = 'X';
        bool gameWon = false;
        bool gameDraw = false;
        
        cout << "Let's play Tic-Tac-Toe!\n";
        
        while (!gameWon && !gameDraw) {
            displayBoard(board);
            int row, col;
            cout << "Player " << currentPlayer << ", enter your move (row and column): ";
            cin >> row >> col;
            
            if (makeMove(board, currentPlayer, row, col)) {
                gameWon = checkWin(board, currentPlayer);
                gameDraw = checkDraw(board);
                switchPlayer(currentPlayer);
            } else {
                cout << "Invalid move. Try again.\n";
            }
        }
        
        displayBoard(board);
        
        if (gameWon) {
            cout << "Player " << currentPlayer << " wins!\n";
        } else if (gameDraw) {
            cout << "It's a draw!\n";
        }
        
        cout << "Do you want to play again? (Y/N): ";
        cin >> playAgain;
    }
    
    cout << "Thanks for playing!\n";
    
    return 0;
}

// Function to initialize the game board
void initializeBoard(vector<vector<char>>& board) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            board[i][j] = ' ';
        }
    }
}

// Function to display the game board
void displayBoard(const vector<vector<char>>& board) {
    cout << "-------------\n";
    for (int i = 0; i < 3; ++i) {
        cout << "| ";
        for (int j = 0; j < 3; ++j) {
            cout << board[i][j] << " | ";
        }
        cout << "\n-------------\n";
    }
}

// Function to make a move
bool makeMove(vector<vector<char>>& board, char player, int row, int col) {
    if (row < 0 || row >= 3 || col < 0 || col >= 3 || board[row][col] != ' ') {
        return false;
    }
    board[row][col] = player;
    return true;
}

// Function to check if a player has won
bool checkWin(const vector<vector<char>>& board, char player) {
    // Check rows, columns, and diagonals for three in a row
    for (int i = 0; i < 3; ++i) {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
            (board[0][i] == player && board[1][i] == player && board[2][i] == player)) {
            return true;
        }
    }
    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player)) {
        return true;
    }
    return false;
}

// Function to check for a draw
bool checkDraw(const vector<vector<char>>& board) {
    // If no empty cells left, it's a draw
    for (const auto& row : board) {
        for (char cell : row) {
            if (cell == ' ') {
                return false;
            }
        }
    }
    return true;
}

// Function to switch players
void switchPlayer(char& currentPlayer) {
    if (currentPlayer == 'X') {
        currentPlayer = 'O';
    } else {
        currentPlayer = 'X';
    }
}
