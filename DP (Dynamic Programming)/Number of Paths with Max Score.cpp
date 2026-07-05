#include<bits/stdc++.h>
using namespace std;

//Recursion
class Solution {
public:
    const int NEG = -1e9;
    const int MOD = 1e9 + 7;

    int n;

    pair<int, int> f(int i, int j, vector<string>& board) {

        // Out of bounds
        if (i >= n || j >= n)
            return {NEG, 0};

        // Obstacle
        if (board[i][j] == 'X')
            return {NEG, 0};

        // Reached destination
        if (board[i][j] == 'S')
            return {0, 1};

        auto down = f(i + 1, j, board);
        auto right = f(i, j + 1, board);
        auto diag = f(i + 1, j + 1, board);

        int best = max({down.first, right.first, diag.first});

        if (best == NEG)
            return {NEG, 0};

        int ways = 0;

        if (down.first == best)
            ways = (ways + down.second) % MOD;

        if (right.first == best)
            ways = (ways + right.second) % MOD;

        if (diag.first == best)
            ways = (ways + diag.second) % MOD;

        int value = 0;

        if (board[i][j] != 'E')
            value = board[i][j] - '0';

        return {best + value, ways};
    }

    vector<int> pathsWithMaxScore(vector<string>& board) {

        n = board.size();

        pair<int, int> ans = f(0, 0, board);

        if (ans.first == NEG)
            return {0, 0};

        return {ans.first, ans.second};
    }
};

//Memoization
class Solution {
public:
    const int NEG = -1e9;
    const int MOD = 1e9 + 7;

    int n;
    vector<vector<pair<int,int>>> dp;

    pair<int, int> f(int i, int j, vector<string>& board) {

        // Out of bounds
        if (i >= n || j >= n)
            return {NEG, 0};

        // Obstacle
        if (board[i][j] == 'X')
            return {NEG, 0};

        // Reached destination
        if (board[i][j] == 'S')
            return {0, 1};

        // Memoization
        if (dp[i][j].second != -1)
            return dp[i][j];

        auto down = f(i + 1, j, board);
        auto right = f(i, j + 1, board);
        auto diag = f(i + 1, j + 1, board);

        int best = max({down.first, right.first, diag.first});

        if (best == NEG)
            return dp[i][j] = {NEG, 0};

        int ways = 0;

        if (down.first == best)
            ways = (ways + down.second) % MOD;

        if (right.first == best)
            ways = (ways + right.second) % MOD;

        if (diag.first == best)
            ways = (ways + diag.second) % MOD;

        int value = (board[i][j] == 'E') ? 0 : board[i][j] - '0';

        return dp[i][j] = {best + value, ways};
    }

    vector<int> pathsWithMaxScore(vector<string>& board) {

        n = board.size();
        dp.assign(n, vector<pair<int,int>>(n, {INT_MIN, -1}));

        auto ans = f(0, 0, board);

        if (ans.first == NEG)
            return {0, 0};

        return {ans.first, ans.second};
    }
};

//Tabulation
class Solution {
public:
    const int NEG = -1e9;
    const int MOD = 1e9 + 7;

    vector<int> pathsWithMaxScore(vector<string>& board) {

        int n = board.size();

        vector<vector<int>> score(n, vector<int>(n, NEG));
        vector<vector<int>> ways(n, vector<int>(n, 0));

        score[n - 1][n - 1] = 0;
        ways[n - 1][n - 1] = 1;

        for (int i = n - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {

                if (board[i][j] == 'X')
                    continue;

                if (board[i][j] == 'S')
                    continue;

                int best = NEG;

                if (i + 1 < n)
                    best = max(best, score[i + 1][j]);

                if (j + 1 < n)
                    best = max(best, score[i][j + 1]);

                if (i + 1 < n && j + 1 < n)
                    best = max(best, score[i + 1][j + 1]);

                if (best == NEG)
                    continue;

                int cnt = 0;

                if (i + 1 < n && score[i + 1][j] == best)
                    cnt = (cnt + ways[i + 1][j]) % MOD;

                if (j + 1 < n && score[i][j + 1] == best)
                    cnt = (cnt + ways[i][j + 1]) % MOD;

                if (i + 1 < n && j + 1 < n && score[i + 1][j + 1] == best)
                    cnt = (cnt + ways[i + 1][j + 1]) % MOD;

                int value = (board[i][j] == 'E') ? 0 : board[i][j] - '0';

                score[i][j] = best + value;
                ways[i][j] = cnt;
            }
        }

        if (score[0][0] == NEG)
            return {0, 0};

        return {score[0][0], ways[0][0]};
    }
};