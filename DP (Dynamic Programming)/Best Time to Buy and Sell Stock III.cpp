#include <bits/stdc++.h>
using namespace std;

// RECURSIVE
// T.C => exponential
// S.C => O(N)
class Solution
{
public:
    int f(int ind, int buy, int n, int cap, vector<int> &prices)
    {
        if (cap == 0)
            return 0;
        if (ind == n)
            return 0;

        if (buy)
            return max(-prices[ind] + f(ind + 1, 0, n, cap, prices),
                       0 + f(ind + 1, 1, n, cap, prices));
        else
            return max(prices[ind] + f(ind + 1, 1, n, cap - 1, prices),
                       0 + f(ind + 1, 0, n, cap, prices));
    }

    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();

        return f(0, 1, n, 2, prices);
    }
};

// RECURSIVE -II
// T.C => exponential
// S.C => O(N)
class Solution
{
public:
    int f(int ind, int trans, int n, vector<int> &prices)
    {
        if (ind == n || trans == 4)
            return 0;
        if (trans % 2 == 0) // buy
            return max(-prices[ind] + f(ind + 1, trans + 1, n, prices),
                       0 + f(ind + 1, trans, n, prices));
        else // sell
            return max(prices[ind] + f(ind + 1, trans + 1, n, prices),
                       0 + f(ind + 1, trans, n, prices));
    }

    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        return f(0, 0, n, prices);
    }
};

// RECURSIVE + MEMOIZATION
// T.C => O(N*2*3)
// S.C => O(N*2*3) +O(N)
class Solution
{
public:
    int f(int ind, int buy, int n, int cap, vector<int> &prices,
          vector<vector<vector<int>>> &dp)
    {
        if (cap == 0)
            return 0;
        if (ind == n)
            return 0;

        if (dp[ind][buy][cap] != -1)
            return dp[ind][buy][cap];

        if (buy)
            return dp[ind][buy][cap] =
                       max(-prices[ind] + f(ind + 1, 0, n, cap, prices, dp),
                           0 + f(ind + 1, 1, n, cap, prices, dp));
        else
            return dp[ind][buy][cap] =
                       max(prices[ind] + f(ind + 1, 1, n, cap - 1, prices, dp),
                           0 + f(ind + 1, 0, n, cap, prices, dp));
    }

    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        vector<vector<vector<int>>> dp(
            n, vector<vector<int>>(2, vector<int>(3, -1)));

        return f(0, 1, n, 2, prices, dp);
    }
};

// RECURSIVE + MEMOIZATION
// T.C => O(N*4)
// S.C => O(N*4) + O(N)
class Solution
{
public:
    int f(int ind, int trans, int n, vector<int> &prices,
          vector<vector<int>> &dp)
    {
        if (ind == n || trans == 4)
            return 0;

        if (dp[ind][trans] != -1)
            return dp[ind][trans];

        if (trans % 2 == 0) // buy
            return dp[ind][trans] =
                       max(-prices[ind] + f(ind + 1, trans + 1, n, prices, dp),
                           0 + f(ind + 1, trans, n, prices, dp));
        else // sell
            return dp[ind][trans] =
                       max(prices[ind] + f(ind + 1, trans + 1, n, prices, dp),
                           0 + f(ind + 1, trans, n, prices, dp));
    }

    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(4, -1));
        return f(0, 0, n, prices, dp);
    }
};

// Tabulation
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        vector<vector<vector<int>>> dp(
            n + 1, vector<vector<int>>(2, vector<int>(3, 0)));

        for (int ind = n - 1; ind >= 0; ind--)
        {
            for (int buy = 0; buy <= 1; buy++)
            {
                for (int cap = 1; cap <= 2; cap++)
                {
                    if (buy)
                        dp[ind][buy][cap] =
                            max(-prices[ind] +
                                    dp[ind + 1][0][cap],
                                0 + dp[ind + 1][1][cap]);
                    else
                        dp[ind][buy][cap] =
                            max(prices[ind] + dp[ind + 1][1][cap - 1],
                                0 + dp[ind + 1][0][cap]);
                }
            }
        }

        return dp[0][1][2];
    }
};

// Space optimized
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        vector<vector<int>> after(2, vector<int>(3, 0));
        vector<vector<int>> cur(2, vector<int>(3, 0));

        for (int ind = n - 1; ind >= 0; ind--)
        {
            for (int buy = 0; buy <= 1; buy++)
            {
                for (int cap = 1; cap <= 2; cap++)
                {
                    if (buy)
                        cur[buy][cap] =
                            max(-prices[ind] +
                                    after[0][cap],
                                0 + after[1][cap]);
                    else
                        cur[buy][cap] =
                            max(prices[ind] + after[1][cap - 1],
                                0 + after[0][cap]);
                }
            }
            after = cur;
        }

        return after[1][2];
    }
};