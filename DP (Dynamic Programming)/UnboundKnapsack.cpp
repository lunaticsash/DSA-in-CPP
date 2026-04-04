#include <bits/stdc++.h>
using namespace std;

// Recursive
//  T.C => Greater than O(2^n) because of the unbounded nature of the problem.. Hence, exponential time complexity
// S.C => O(W) for the recursion stack space
int f(int ind, int w, vector<int> &profit, vector<int> &weight)
{
    if (ind == 0)
    {
        return (w / weight[0]) * profit[0];
    }

    int notTake = f(ind - 1, w, profit, weight);
    int take = INT_MIN;
    if (weight[ind] <= w)
    {
        take = profit[ind] + f(ind, w - weight[ind], profit, weight);
    }

    return max(take, notTake);
}

int unboundedKnapsack1(int n, int w, vector<int> &profit, vector<int> &weight)
{
    return f(n - 1, w, profit, weight);
}

// Recursive + memoization
// T.C = O(N * W)
// S.C = O(N * W) + O(N) recursion stack
int f2(int ind, int w, vector<int> &profit, vector<int> &weight, vector<vector<int>> &dp)
{
    if (ind == 0)
    {
        return (w / weight[0]) * profit[0];
    }

    if (dp[ind][w] != -1)
        return dp[ind][w];

    int notTake = f2(ind - 1, w, profit, weight, dp);
    int take = INT_MIN;
    if (weight[ind] <= w)
    {
        take = profit[ind] + f2(ind, w - weight[ind], profit, weight, dp);
    }

    return dp[ind][w] = max(take, notTake);
}

int unboundedKnapsack2(int n, int w, vector<int> &profit, vector<int> &weight)
{
    vector<vector<int>> dp(n, vector<int>(w + 1, -1));
    return f2(n - 1, w, profit, weight, dp);
}

// Tabulation
//  T.C => O(N*W)
//  S.C => O(N*W) for the dp array
int unboundedKnapsack3(int n, int w, vector<int> &profit, vector<int> &weight)
{
    vector<vector<int>> dp(n, vector<int>(w + 1, 0));

    for (int W = 0; W <= w; W++)
    {
        dp[0][W] = ((int)(W / weight[0]) * profit[0]);
    }

    for (int ind = 1; ind < n; ind++)
    {
        for (int W = 0; W <= w; W++)
        {
            int notTake = dp[ind - 1][W];
            int take = INT_MIN;
            if (weight[ind] <= W)
            {
                take = profit[ind] + dp[ind][W - weight[ind]];
            }

            dp[ind][W] = max(take, notTake);
        }
    }

    return dp[n - 1][w];
}

// Space optimization
//  T.C => O(N*W)
//  S.C => O(2*(w+1)) = O(w)

int unboundedKnapsack4(int n, int w, vector<int> &profit, vector<int> &weight)
{
    vector<int> prev(w + 1, 0);
    vector<int> cur(w + 1, 0);
    for (int W = 0; W <= w; W++)
    {
        prev[W] = ((int)(W / weight[0]) * profit[0]);
    }

    for (int ind = 1; ind < n; ind++)
    {
        for (int W = 0; W <= w; W++)
        {
            int notTake = prev[W];
            int take = INT_MIN;
            if (weight[ind] <= W)
            {
                take = profit[ind] + cur[W - weight[ind]];
            }

            cur[W] = max(take, notTake);
        }
        prev = cur;
    }

    return prev[w];
}

// Space optimization into one array. In 1D optimization, loop order matters.
//  T.C => O(N*W)
//  S.C =>O(w)
int unboundedKnapsack5(int n, int w, vector<int> &profit, vector<int> &weight)
{
    vector<int> prev(w + 1, 0);
    for (int W = 0; W <= w; W++)
    {
        prev[W] = ((int)(W / weight[0]) * profit[0]);
    }

    for (int ind = 1; ind < n; ind++)
    {
        for (int W = 0; W <= w; W++) // If it were 0/1 you must go backward(w → 0)
        {
            int notTake = prev[W];
            int take = INT_MIN;
            if (weight[ind] <= W)
            {
                take = profit[ind] + prev[W - weight[ind]];
            }

            prev[W] = max(take, notTake); // rewritter
        }
    }

    return prev[w];
}
