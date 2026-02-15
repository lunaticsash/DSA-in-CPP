#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    unordered_map<int, bool> rowCheck;
    unordered_map<int, bool> upperDiag;
    unordered_map<int, bool> lowerDiag;

    void addSolution(vector<vector<string>>& ans,
                     vector<vector<int>>& board, int n) {

        vector<string> temp;
        for (int i = 0; i < n; i++) {
            string row = "";
            for (int j = 0; j < n; j++) {
                row += (board[i][j] == 1) ? 'Q' : '.';
            }
            temp.push_back(row);
        }
        ans.push_back(temp);
    }

    void solve(int col,
               vector<vector<string>>& ans,
               vector<vector<int>>& board, int n) {

        if (col == n) {
            addSolution(ans, board, n);
            return;
        }

        for (int row = 0; row < n; row++) {

            if (!rowCheck[row] &&
                !upperDiag[row - col + n - 1] &&
                !lowerDiag[row + col]) {

                // place queen
                board[row][col] = 1;
                rowCheck[row] = true;
                upperDiag[row - col + n - 1] = true;
                lowerDiag[row + col] = true;

                solve(col + 1, ans, board, n);

                // backtrack
                board[row][col] = 0;
                rowCheck[row] = false;
                upperDiag[row - col + n - 1] = false;
                lowerDiag[row + col] = false;
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<int>> board(n, vector<int>(n, 0));
        vector<vector<string>> ans;

        solve(0, ans, board, n);
        return ans;
    }
};
