#include <bits/stdc++.h>
using namespace std;

//RECURSION
class Solution {
public:
    int LEFT = 0;
    int UP = 1;
    int m;
    int n;
    int mod = 1e9 + 7;

    int solve(int i, int j, vector<vector<int>>& grid, int cameFrom) {
        if (i == m - 1 && j == n - 1)
            return 1;
        if (i >= m || j >= n)
            return 0;

        if()

        if (grid[i][j] == 1) {
            if (cameFrom == LEFT) {
                return solve(i + 1, j, grid, UP);
            } else {
                return solve(i, j + 1, grid, LEFT);
            }
        } // mirror

        int totalPath = 0;
        totalPath += solve(i + 1, j, grid, UP) % mod;
        totalPath += solve(i, j + 1, grid, LEFT) % mod;

        return totalPath % mod;
    }

    int uniquePaths(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        return solve(0, 0, grid, 0);
    }
};

//MEMOIZATION
class Solution {
public:
    int LEFT = 0;
    int UP = 1;
    int m;
    int n;
    int mod = 1e9 + 7;

    // Memoization dp[i][j] = {-1,-1} //left and right
    int solve(int i, int j, vector<vector<int>>& grid, int cameFrom,
              vector<vector<array<int, 2>>>& dp) {
        if (i == m - 1 && j == n - 1)
            return 1;
        if (i >= m || j >= n)
            return 0;

        if(dp[i][j][cameFrom] != -1){
            return dp[i][j][cameFrom];
        }

        if (grid[i][j] == 1) {
            if (cameFrom == LEFT) {
                return dp[i][j][cameFrom] = solve(i + 1, j, grid, UP, dp);
            } else {
                return  dp[i][j][cameFrom] = solve(i, j + 1, grid, LEFT, dp);
            }
        } // mirror

        int totalPath = 0;
        totalPath += solve(i + 1, j, grid, UP, dp) % mod;
        totalPath += solve(i, j + 1, grid, LEFT, dp) % mod;

        return dp[i][j][cameFrom] = totalPath % mod;
    }

    int uniquePaths(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        vector<vector<array<int, 2>>> dp(m + 1,
                                         vector<array<int, 2>>(n, {-1, -1}));
        return solve(0, 0, grid, 0, dp);
    }
};

//TABULATION
class Solution {
public:
    int LEFT = 0;
    int UP   = 1;
    int MOD = 1e9 + 7;
    int m, n;

    int uniquePaths(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        // t[row][col][LEFT] = ways to reach this cell by entering from the left
        // t[row][col][UP]   = ways to reach this cell by entering from above
        vector<vector<array<int, 2>>> t(m, vector<array<int, 2>>(n, {0, 0}));

        // Start cell: one way to be here (start is never a mirror, slot is arbitrary)
        t[0][0][LEFT] = 1;

        // Prefill 0th row: one way to reach each cell, until the first mirror
        for (int col = 1; col < n; col++) {
            t[0][col][LEFT] = 1;
            if (grid[0][col] == 1)
                break;          // deflected down, cells beyond stay 0
        }

        // Prefill 0th column: one way to reach each cell, until the first mirror
        for (int row = 1; row < m; row++) {
            t[row][0][UP] = 1;
            if (grid[row][0] == 1)
                break;          // deflected right, cells below stay 0
        }

        // Fill the rest
        for (int row = 1; row < m; row++) {
            for (int col = 1; col < n; col++) {

                // Entering from the left neighbour (row, col-1)
                if (grid[row][col - 1] == 1)
                    t[row][col][LEFT] = t[row][col - 1][UP];       // mirror: only UP-entrants turn right
                else
                    t[row][col][LEFT] = (t[row][col - 1][LEFT] + t[row][col - 1][UP]) % MOD;

                // Entering from the top neighbour (row-1, col)
                if (grid[row - 1][col] == 1)
                    t[row][col][UP] = t[row - 1][col][LEFT];       // mirror: only LEFT-entrants turn down
                else
                    t[row][col][UP] = (t[row - 1][col][LEFT] + t[row - 1][col][UP]) % MOD;
            }
        }

        // Destination is always empty: every arrival counts, from either side
        return (t[m - 1][n - 1][LEFT] + t[m - 1][n - 1][UP]) % MOD;
    }
};

class Solution {
    int LEFT = 0;
    int UP = 1;
    int MOD = 1_000_000_007;
    int m, n;

    public int uniquePaths(int[][] grid) {
        m = grid.length;
        n = grid[0].length;

        // t[row][col][LEFT] = ways to reach this cell by entering from the left
        // t[row][col][UP]   = ways to reach this cell by entering from above
        int[][][] t = new int[m][n][2]; // Java initializes to 0

        // Start cell: one way to be here (start is never a mirror, slot is arbitrary)
        t[0][0][LEFT] = 1;

        // Prefill 0th row: one way to reach each cell, until the first mirror
        for (int col = 1; col < n; col++) {
            t[0][col][LEFT] = 1;
            if (grid[0][col] == 1)
                break; // deflected down, cells beyond stay 0
        }

        // Prefill 0th column: one way to reach each cell, until the first mirror
        for (int row = 1; row < m; row++) {
            t[row][0][UP] = 1;
            if (grid[row][0] == 1)
                break; // deflected right, cells below stay 0
        }

        // Fill the rest
        for (int row = 1; row < m; row++) {
            for (int col = 1; col < n; col++) {

                // Entering from the left neighbour (row, col-1)
                if (grid[row][col - 1] == 1)
                    t[row][col][LEFT] = t[row][col - 1][UP]; // mirror: only UP-entrants turn right
                else
                    t[row][col][LEFT] = (t[row][col - 1][LEFT] + t[row][col - 1][UP]) % MOD;

                // Entering from the top neighbour (row-1, col)
                if (grid[row - 1][col] == 1)
                    t[row][col][UP] = t[row - 1][col][LEFT]; // mirror: only LEFT-entrants turn down
                else
                    t[row][col][UP] = (t[row - 1][col][LEFT] + t[row - 1][col][UP]) % MOD;
            }
        }

        // Destination is always empty: every arrival counts, from either side
        return (t[m - 1][n - 1][LEFT] + t[m - 1][n - 1][UP]) % MOD;
    }
};