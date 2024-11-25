#include <iostream>
#include <vector>
using namespace std;

bool isSafe(int row, int col, vector<vector<int>> &board, int n) {
    // check current cell [i][j] par queen rakh sakta hoon
    int i = row, j = col;

    // Check row on left
    while (j >= 0) {
        if (board[i][j] == 1) return false;
        j--;
    }

    // Check upper left diagonal
    i = row, j = col;
    while (i >= 0 && j >= 0) {
        if (board[i][j] == 1) return false;
        i--;
        j--;
    }

    // Check lower left diagonal
    i = row, j = col;
    while (i < n && j >= 0) {
        if (board[i][j] == 1) return false;
        i++;
        j--;
    }

    return true;
}

void printSolution(vector<vector<int>> &board, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            // cout << board[i][j] << " ";
            cout << (board[i][j] == 1 ? "Q " : ". ");
        }
        cout << endl;
    }
    cout << endl;
}

void solve(vector<vector<int>> &board, int col, int n) {
    // Base case
    if (col >= n) {
        printSolution(board, n);
        return;
    }

    // Place queen in each row of the current column
    for (int row = 0; row < n; row++) {
        if (isSafe(row, col, board, n)) {
            board[row][col] = 1;  // Place queen
            solve(board, col + 1, n); // Recur for next column
            board[row][col] = 0;  // Backtrack
        }
    }
}

int main() {
    int n = 4;  // n*n board size
    vector<vector<int>> board(n, vector<int>(n, 0));

    solve(board, 0, n);

    return 0;
}
