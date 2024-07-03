class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> solutions;
        vector<string> board(n, string(n, '.'));
        solve(board, 0, n, solutions);
        return solutions;
    }
private:
    bool isSafe(vector<string>& board, int row, int col, int n) {
        // Check this row on the left side
        for (int j = col; j >= 0; j--) {
            if (board[row][j] == 'Q') {
                return false;
            }
        }
        // Check upper diagonal on the left side
        for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
            if (board[i][j] == 'Q') {
                return false;
            }
        }
        // Check lower diagonal on the left side
        for (int i = row, j = col; i < n && j >= 0; i++, j--) {
            if (board[i][j] == 'Q') {
                return false;
            }
        }
        return true;
    }

    void solve(vector<string>& board, int col, int n, vector<vector<string>>& solutions) {
        // Base case: If all queens are placed
        if (col == n) {
            solutions.push_back(board);
            return;
        }
        // Try placing this queen in all rows one by one
        for (int row = 0; row < n; row++) {
            if (isSafe(board, row, col, n)) {
                board[row][col] = 'Q'; // Place this queen in board[row][col]
                solve(board, col + 1, n, solutions); // Recur to place the rest of the queens
                board[row][col] = '.'; // Backtrack
            }
        }
    }
};
