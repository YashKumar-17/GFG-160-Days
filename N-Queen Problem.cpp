Approach & Intuition
Backtracking Approach:

Try placing a queen in each column recursively.
If placing a queen at a certain position is safe, proceed to the next column.
If all queens are placed successfully, store the solution.
Safety Check (isSafe function):

Ensures no two queens attack each other.
Checks for conflicts in the same row and diagonals.
Recursive Exploration (solve function):

Iterates over all rows for the current column.
Places a queen if it's safe and moves to the next column.
Backtracks if no valid position is found.
Result Storage:

Each valid board configuration is stored in result.
The board is represented as a 1D array where index = column and value = row.

vector<vector<int>> nQueen(int n) {
       
        vector<vector<int>> result;
        vector<int> board(n, 0);
        solve(0, n, board, result);
        return result;
    }

private:
    void solve(int col, int n, vector<int>& board, vector<vector<int>>& result) {
        if (col == n) {
            result.push_back(board);
            return;
        }
        
        for (int row = 0; row < n; row++) {
            if (isSafe(board, col, row)) {
                board[col] = row + 1;
                solve(col + 1, n, board, result);
            }
        }
    }
    
    bool isSafe(vector<int>& board, int col, int row) {
        for (int i = 0; i < col; i++) {
            int placedRow = board[i] - 1;
            if (placedRow == row || abs(placedRow - row) == abs(i - col)) {
                return false;
            }
        }
        return true;
    }
