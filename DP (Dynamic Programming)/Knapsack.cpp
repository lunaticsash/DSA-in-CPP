#include <bits/stdc++.h>
using namespace std;

// recursive + memoization
// TC -> O(n * W)
// SC -> O(n * W) + O(n) aux stack space
int f(int ind, int W, vector<int> &wt, vector<int> &val, vector<vector<int>> &dp)
{
    if (ind == 0)
    {
        if (wt[0] <= W)
            return val[0];
        return 0;
    }

    if (dp[ind][W] != -1)
        return dp[ind][W];

    int nottake = 0 + f(ind - 1, W, wt, val, dp);
    int take = INT_MIN;
    if (wt[ind] <= W)
    {
        take = val[ind] + f(ind - 1, W - wt[ind], wt, val, dp);
    }

    return dp[ind][W] = max(take, nottake);
}

int knapsack(vector<int> &weight, vector<int> &value, int n, int maxWeight)
{
    vector<vector<int>> dp(n, vector<int>(maxWeight + 1, -1));

    return f(n - 1, maxWeight, weight, value, dp);
}

// Tabulation
// TC -> O(n * W)
// SC -> O(n) aux stack space
int knapsackTabulation(vector<int> &wt, vector<int> &val, int n, int maxWeight)
{
    vector<vector<int>> dp(n, vector<int>(maxWeight + 1, 0));

    for (int W = wt[0]; W <= maxWeight; W++)
    {
        dp[0][W] = val[0];
    }

    for (int ind = 1; ind < n; ind++)
    {
        for (int W = 0; W <= maxWeight; W++)
        {
            int nottake = 0 + dp[ind - 1][W];
            int take = INT_MIN;
            if (wt[ind] <= W)
            {
                take = val[ind] + dp[ind - 1][W - wt[ind]];
            }
            dp[ind][W] = max(take, nottake);
        }
    }

    return dp[n - 1][maxWeight];
}

// Space Optimization
// TC -> O(n * W)
// SC -> Two array optimization
int knapsackSapceOptimized(vector<int> &wt, vector<int> &val, int n, int maxWeight)
{
    vector<int> prev(maxWeight + 1, 0), cur(maxWeight + 1, 0);

    for (int W = wt[0]; W <= maxWeight; W++)
    {
        prev[W] = val[0];
    }

    for (int ind = 1; ind < n; ind++)
    {
        for (int W = 0; W <= maxWeight; W++)
        {
            int nottake = 0 + prev[W];
            int take = INT_MIN;
            if (wt[ind] <= W)
            {
                take = val[ind] + prev[W - wt[ind]];
            }
            cur[W] = max(take, nottake);
        }
        prev = cur;
    }

    return prev[maxWeight];
}


// Space Optimization 2
// TC -> O(n * W)
// SC -> single array optimization
int knapsackSapceOptimized2(vector<int> &wt, vector<int> &val, int n, int maxWeight)
{
    vector<int> prev(maxWeight + 1, 0);

    for (int W = wt[0]; W <= maxWeight; W++)
    {
        prev[W] = val[0];
    }

    for (int ind = 1; ind < n; ind++)
    {
        for (int W = maxWeight; W >= 0; W--)
        {
            int nottake = 0 + prev[W];
            int take = INT_MIN;
            if (wt[ind] <= W)
            {
                take = val[ind] + prev[W - wt[ind]];
            }
            prev[W] = max(take, nottake);
        }
    }

    return prev[maxWeight];
}