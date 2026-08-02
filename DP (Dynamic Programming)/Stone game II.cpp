#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool stoneGame(vector<int> &piles)
    {
        return true;
    }
};
class Solution
{
public:
    bool stoneGame(vector<int> &piles)
    {
        int n = piles.size();

        vector<vector<int>> dp(n, vector<int>(n, 0));

        // Base case
        for (int i = 0; i < n; i++)
            dp[i][i] = piles[i];

        // Fill by increasing length
        for (int len = 2; len <= n; len++)
        {
            for (int i = 0; i + len - 1 < n; i++)
            {
                int j = i + len - 1;

                int takeFirst = piles[i] - dp[i + 1][j];
                int takeLast = piles[j] - dp[i][j - 1];

                dp[i][j] = max(takeFirst, takeLast);
            }
        }

        return dp[0][n - 1] > 0;
    }
};
class Solution
{
public:
    vector<vector<int>> dp;

    int solve(vector<int> &piles, int i, int j)
    {
        if (i == j)
            return piles[i];

        if (dp[i][j] != -1)
            return dp[i][j];

        int takeFirst = piles[i] - solve(piles, i + 1, j);
        int takeLast = piles[j] - solve(piles, i, j - 1);

        return dp[i][j] = max(takeFirst, takeLast);
    }

    bool stoneGame(vector<int> &piles)
    {
        int n = piles.size();
        dp.assign(n, vector<int>(n, -1));

        return solve(piles, 0, n - 1) > 0;
    }
};

class Solution
{
public:
    int solve(vector<int> &piles, int i, int j)
    {
        if (i == j)
            return piles[i];

        int takeFirst = piles[i] - solve(piles, i + 1, j);
        int takeLast = piles[j] - solve(piles, i, j - 1);

        return max(takeFirst, takeLast);
    }

    bool stoneGame(vector<int> &piles)
    {
        return solve(piles, 0, piles.size() - 1) > 0;
    }
};
