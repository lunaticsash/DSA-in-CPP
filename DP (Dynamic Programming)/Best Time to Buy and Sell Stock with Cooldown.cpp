#include <bits/stdc++.h>
using namespace std;

// RECURSIVE + MEMOIZATION

class Solution
{
public:
    int f(int ind, int buy, int n, vector<int> &prices, vector<vector<int>> &dp)
    {
        if (ind >= n)
            return 0;
        if (dp[ind][buy] != -1)
            return dp[ind][buy];
        if (buy)
            return dp[ind][buy] = max(-prices[ind] + f(ind + 1, 0, n, prices, dp),
                                      0 + f(ind + 1, 1, n, prices, dp));
        else
            return dp[ind][buy] = max(prices[ind] + f(ind + 2, 1, n, prices, dp),
                                      0 + f(ind + 1, 0, n, prices, dp));
    }

    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return f(0, 1, n, prices, dp);
    }
};

// Tabulation
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        vector<vector<int>> dp(n + 2, vector<int>(2, 0));

        for (int ind = n - 1; ind >= 0; ind--)
        {
            for (int buy = 0; buy <= 1; buy++)
            {
                if (buy)
                    dp[ind][buy] =
                        max(-prices[ind] + dp[ind + 1][0],
                            0 + dp[ind + 1][1]);
                else
                    dp[ind][buy] =
                        max(prices[ind] + dp[ind + 2][1],
                            0 + dp[ind + 1][0]);
            }
        }

        return dp[0][1];
    }
};
// Tabulation more optimized
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        vector<vector<int>> dp(n + 2, vector<int>(2, 0));

        for (int ind = n - 1; ind >= 0; ind--)
        {

            dp[ind][1] =
                max(-prices[ind] + dp[ind + 1][0],
                    0 + dp[ind + 1][1]);

            dp[ind][0] =
                max(prices[ind] + dp[ind + 2][1],
                    0 + dp[ind + 1][0]);
        }

        return dp[0][1];
    }
};

// 3 varibales approach
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        vector<vector<int>> dp(n + 2, vector<int>(2, 0));

        for (int ind = n - 1; ind >= 0; ind--)
        {

            dp[ind][1] =
                max(-prices[ind] + dp[ind + 1][0],
                    0 + dp[ind + 1][1]);

            dp[ind][0] =
                max(prices[ind] + dp[ind + 2][1],
                    0 + dp[ind + 1][0]);
        }

        return dp[0][1];
    }
};