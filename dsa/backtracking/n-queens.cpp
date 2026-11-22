// Backtracking: You are given N, for a given NxN chessboard, find a way to place N queens such that no queen can attack any other queen on the chess board.
// Print all such scenarios.

#include<bits/stdc++.h>
using namespace std;

int board[11][11]; // Chessboard representation, 1 indicates a queen is placed, 0 indicates empty.

// Check if it is possible to place a queen at position (row, col) on the board.
bool isPossible(int n, int row, int col) {
    // Check the column for any queen in previous rows.
    for (int i = 0; i < row; i++) {
        if (board[i][col] == 1) return false; // There is already a queen in this column.
    }
    // Check the upper left diagonal for any queen.
    for (int i = row-1, j = col-1; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 1) return false; // There is already a queen in the upper left diagonal.
    }
    // Check the upper right diagonal for any queen.
    for (int i = row-1, j = col+1; i >= 0 && j < n; i--, j++) {
        if (board[i][j] == 1) return false; // There is already a queen in the upper right diagonal.
    }
    return true; // It is safe to place a queen at (row, col).
}

// Helper function to solve the N-Queens problem using backtracking.
void nQueenHelper(int n, int row) {
    // Base case: If all queens are placed, print the board configuration.
    if ( row == n) {
        // Print the current board configuration as a valid solution.
        for( int i =0; i < n; i++) {
            // Print each row of the board.
            for ( int j=0; j < n; j++) {
                cout << board[i][j] << " ";

            }
            cout << endl;
        }
        cout << endl;
        // Return to explore other possible configurations.
        return;
    }    

    // Try placing a queen in each column of the current row.
    for ( int j =0; j < n; j++) {
        // Check if it is safe to place a queen at (row, j).
        if(isPossible(n, row, j)) {
            // Place the queen at (row, j) and move to the next row.
            board[row][j] = 1;
            nQueenHelper(n, row + 1);
            // Backtrack: Remove the queen from (row, j) to explore other possibilities.
            board[row][j] = 0;
        }
    }
}

// Function to initialize the board and start the N-Queens problem solving process.
void placeNQueens(int n) {
    memset(board, 0, 11*11*sizeof(int)); // Initialize the chessboard to be empty.
    nQueenHelper(n,0); // Start solving the N-Queens problem from the first row.
}


int main() {

    placeNQueens(4);

    return 0;
}