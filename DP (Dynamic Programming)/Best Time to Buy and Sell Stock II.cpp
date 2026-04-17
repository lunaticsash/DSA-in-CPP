#include <bits/stdc++.h>
using namespace std;

// RECURSIVE + MEMOIZATION
// T.C => O(n*2)
// S.C => O(n*2) + O(n)
class Solution
{
public:
    int f(int ind, int buy, vector<int> &prices, int n,
          vector<vector<int>> &dp)
    {
        if (ind == n)
            return 0;
        if (dp[ind][buy] != -1)
            return dp[ind][buy];
        int profit = 0;
        if (buy)
            profit = max(-prices[ind] + f(ind + 1, 0, prices, n, dp),
                         0 + f(ind + 1, 1, prices, n, dp));
        else
            profit = max(prices[ind] + f(ind + 1, 1, prices, n, dp),
                         0 + f(ind + 1, 0, prices, n, dp));

        return dp[ind][buy] = profit;
    }

    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return f(0, 1, prices, n, dp);
    }
};

// Tabulation
//  T.C => O(n*2)
//  S.C => O(n*2)
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        vector<vector<int>> dp(n + 1, vector<int>(2, 0));
        dp[n][0], dp[n][1] = 0;
        for (int ind = n - 1; ind >= 0; ind--)
        {
            for (int buy = 0; buy <= 1; buy++)
            {
                int profit = 0;
                if (buy)
                    profit =
                        max(-prices[ind] + dp[ind + 1][0], 0 + dp[ind + 1][1]);
                else
                    profit =
                        max(prices[ind] + dp[ind + 1][1], 0 + dp[ind + 1][0]);

                dp[ind][buy] = profit;
            }
        }
        return dp[0][1];
    }
};

// Space optimization
//  T.C => O(n*2)
//  S.C => O(n)
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        vector<int> ahead(2, 0);
        vector<int> cur(2, 0);

        ahead[0], ahead[1] = 0;
        for (int ind = n - 1; ind >= 0; ind--)
        {
            for (int buy = 0; buy <= 1; buy++)
            {
                int profit = 0;
                if (buy)
                    profit =
                        max(-prices[ind] + ahead[0], 0 + ahead[1]);
                else
                    profit =
                        max(prices[ind] + ahead[1], 0 + ahead[0]);

                cur[buy] = profit;
            }
            ahead = cur;
        }
        return ahead[1];
    }
};

// Space optimization
//  T.C => O(n*2)
//  S.C => O(n)
long getMaximumProfit(long *values, int n)
{
    long aheadNotBuy, aheadBuy, curBuy, curNotBuy;
    aheadNotBuy = aheadBuy = 0;

    for(int ind = n-1; ind >= 0; ind--) {

        curNotBuy = max(values[ind] + aheadBuy,
                        0 + aheadNotBuy);

        curBuy = max(-values[ind] + aheadNotBuy,
                     0 + aheadBuy);

        aheadBuy = curBuy;
        aheadNotBuy = curNotBuy;
    }

    return aheadBuy;

    // Write your code here
}