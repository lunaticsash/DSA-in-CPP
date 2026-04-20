#include <bits/stdc++.h>
using namespace std;

// RECURSION + MEMOIZATION
// T.C => O(N*2*K)
// S.C => O(N*2*K) + O(N)
class Solution
{
public:
    int f(int ind, int buy, vector<int> &prices, int n,
          vector<vector<vector<int>>> &dp, int k)
    {   
        if (ind == n || k == 0)
            return 0;
        if (dp[ind][buy][k] != -1)
            return dp[ind][buy][k];
        int profit = 0;
        if (buy)
            profit = max(-prices[ind] + f(ind + 1, 0, prices, n, dp, k),
                         0 + f(ind + 1, 1, prices, n, dp, k));
        else
            profit = max(prices[ind] + f(ind + 1, 1, prices, n, dp, k - 1),
                         0 + f(ind + 1, 0, prices, n, dp, k));

        return dp[ind][buy][k] = profit;
    }
    int maxProfit(int k, vector<int> &prices)
    {
        int n = prices.size();
        vector<vector<vector<int>>> dp(
            n, vector<vector<int>>(2, vector<int>(k + 1, -1)));
        return f(0, 1, prices, n, dp, k);
    }
};

// MEMOIZATION
class Solution
{
public:
    int f(int ind, int trano, vector<int> &prices, int n,
          vector<vector<int>> &dp, int k)
    {

        if (ind == n || trano == k * 2)
            return 0;
        if (dp[ind][trano] != -1)
            return dp[ind][trano]; // fixed: removed extra bracket

        int profit = 0;
        if (trano % 2 == 0) // even → buy phase
            profit = max(-prices[ind] + f(ind + 1, trano + 1, prices, n, dp, k),
                         0 + f(ind + 1, trano, prices, n, dp, k));
        else // odd → sell phase
            profit = max(prices[ind] + f(ind + 1, trano + 1, prices, n, dp, k),
                         0 + f(ind + 1, trano, prices, n, dp, k));

        return dp[ind][trano] = profit; // fixed: correct dp dimensions
    }

    int maxProfit(int k, vector<int> &prices)
    {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2 * k, -1));
        return f(0, 0, prices, n, dp, k); // fixed: start trano at 0
    }
};

// TABULATION
// T.C => O(N*2*K)
// S.C => O(N*2*K)
class Solution
{
public:
    int maxProfit(int k, vector<int> &prices)
    {
        int n = prices.size();
        // dp[ind][buy][cap] = 0 handles all base cases implicitly
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(k + 1, 0)));

        for (int ind = n - 1; ind >= 0; ind--)
        {
            for (int buy = 0; buy <= 1; buy++)
            {
                for (int cap = 1; cap <= k; cap++)
                {
                    if (buy)
                        dp[ind][buy][cap] =
                            max(-prices[ind] + dp[ind + 1][0][cap],
                                0 + dp[ind + 1][1][cap]);
                    else
                        dp[ind][buy][cap] =
                            max(prices[ind] + dp[ind + 1][1][cap - 1],
                                0 + dp[ind + 1][0][cap]);
                }
            }
        }

        return dp[0][1][k];
    }
};

// TABULATION OPTIMIZED IN 2D DP
class Solution
{
public:
    int maxProfit(int k, vector<int> &prices)
    {
        int n = prices.size();
        // dp[ind][trano] = 0 handles all base cases implicitly
        // ind == n and trano == 2*k both return 0
        vector<vector<int>> dp(n + 1, vector<int>(2 * k + 1, 0));

        for (int ind = n - 1; ind >= 0; ind--)
        {
            for (int trano = 2 * k - 1; trano >= 0; trano--)
            {
                int profit = 0;
                if (trano % 2 == 0) // buy phase
                    profit = max(-prices[ind] + dp[ind + 1][trano + 1],
                                 0 + dp[ind + 1][trano]);
                else // sell phase
                    profit = max(prices[ind] + dp[ind + 1][trano + 1],
                                 0 + dp[ind + 1][trano]);

                dp[ind][trano] = profit;
            }
        }

        return dp[0][0];
    }
};

// SPACE OPTIMIZATION
// T.C => O(n)
// S.C => O(2K) 2D DP
class Solution
{
public:
    int maxProfit(int k, vector<int> &prices)
    {
        int n = prices.size();

        vector<int> after(2 * k + 1, 0);
        vector<int> cur(2 * k + 1, 0);

        for (int ind = n - 1; ind >= 0; ind--)
        {
            for (int trano = 2 * k - 1; trano >= 0; trano--)
            {
                int profit = 0;
                if (trano % 2 == 0) // buy phase
                    profit = max(-prices[ind] + after[trano + 1],
                                 0 + after[trano]);
                else // sell phase
                    profit = max(prices[ind] + after[trano + 1],
                                 0 + after[trano]);

                cur[trano] = profit;
            }
            after = cur;
        }

        return after[0];
    }
};