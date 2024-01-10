#include <iostream>
#include <vector>

using namespace std;

// Function to check if placing a queen at (row, col) is safe
bool isSafe(vector<vector<int>>& board, int row, int col, int N) {
    // Check left side of the current row
    for (int i = 0; i < col; ++i)
        if (board[row][i] == 1)
            return false;

    // Check upper diagonal on the left side
    for (int i = row, j = col; i >= 0 && j >= 0; --i, --j)
        if (board[i][j] == 1)
            return false;

    // Check lower diagonal on the left side
    for (int i = row, j = col; i < N && j >= 0; ++i, --j)
        if (board[i][j] == 1)
            return false;

    return true;
}

// Function to solve N-Queens problem using backtracking
bool solveNQueensUtil(vector<vector<int>>& board, int col, int N) {
    // Base case: If all queens are placed, return true
    if (col >= N)
        return true;

    // Try placing a queen in each row of the current column
    for (int i = 0; i < N; ++i) {
        if (isSafe(board, i, col, N)) {
            // Place the queen
            board[i][col] = 1;

            // Recur to place queens in the next columns
            if (solveNQueensUtil(board, col + 1, N))
                return true;

            // If placing queen in the current position doesn't lead to a solution, backtrack
            board[i][col] = 0;
        }
    }

    // If no row worked in the current column, return false
    return false;
}

// Function to solve N-Queens problem and print the solution
void solveNQueens(int N) {
    // Create a matrix of 0s of size N
    vector<vector<int>> board(N, vector<int>(N, 0));

    // Call util function to place the queens on the board
    // If we get true, print the solution
    if (solveNQueensUtil(board, 0, N)) {
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j)
                cout << board[i][j] << " ";
            cout << "\n";
        }
    }
    // If we get false, there is no solution
    else {
        cout << "Solution does not exist.\n";
    }
}

int main() {
    // Set N as the number of queens
    int N;
    cout << "Enter the number of queens (N): ";
    cin >> N;

    solveNQueens(N);

    return 0;
}
