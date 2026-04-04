#include <bits/stdc++.h>
using namespace std;

// Recursive
// T.C -> O(2^n) >>, close to exponential
// S.C -> O(n) aux stack space
int f(int ind, int T, vector<int> &a)
{
    if (ind == 0)
        return (T % a[0] == 0);

    int notTake = 0 + f(ind - 1, T, a);
    int take = 0;
    if (a[ind] <= T)
        take = f(ind, T - a[ind], a);

    return (take + notTake);
}

int change(int amount, vector<int> &coins)
{
    int n = coins.size();

    return f(n - 1, amount, coins);
}

// Recusrion+ memoization
// T.C -> O(n * tar)
// S.C -> O(n * tar) + O(n) aux stack space
class Solution2
{
public:
    int f2(int ind, int T, vector<int> &a, vector<vector<int>> &dp)
    {
        if (ind == 0)
            return (T % a[0] == 0);

        if (dp[ind][T] != -1)
            return dp[ind][T];
        int notTake = 0 + f2(ind - 1, T, a, dp);
        int take = 0;
        if (a[ind] <= T)
            take = f2(ind, T - a[ind], a, dp);

        return dp[ind][T] = (take + notTake);
    }

    int change2(int amount, vector<int> &coins)
    {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));

        return f2(n - 1, amount, coins, dp);
    }
};

// Tabulation
// T.C -> O(n * tar)
// S.C -> O(n * tar)
int changeTabulation(int amount, vector<int> &coins)
{
    int n = coins.size();
    vector<vector<int>> dp(n, vector<int>(amount + 1, 0));
    for (int T = 0; T <= amount; T++)
    {
        dp[0][T] = (T % coins[0] == 0);
    }

    for (int ind = 1; ind <= n - 1; ind++)
    {
        for (int T = 0; T <= amount; T++)
        {
            int notTake = 0 + dp[ind - 1][T];
            int take = 0;
            if (coins[ind] <= T)
                take = dp[ind][T - coins[ind]];

            dp[ind][T] = (take + notTake);
        }
    }

    return dp[n - 1][amount];
}

// Space Optimization
//  T.C -> O(n * tar)
//  S.C -> O(tar)
int change(int amount, vector<int> &coins)
{
    int n = coins.size();
    vector<long long> prev(amount + 1, 0);
    vector<long long> cur(amount + 1, 0);
    for (int T = 0; T <= amount; T++)
    {
        prev[T] = (T % coins[0] == 0);
    }

    for (int ind = 1; ind <= n - 1; ind++)
    {
        for (int T = 0; T <= amount; T++)
        {
            long long notTake = 0 + prev[T];
            long long take = 0;
            if (coins[ind] <= T)
                take = cur[T - coins[ind]];

            cur[T] = (take + notTake);
        }
        prev = cur;
    }

    return prev[amount];
}

// 1D mai convert
//  T.C -> O(n * tar)
//  S.C -> O(tar)
int change(int amount, vector<int> &coins)
{

    vector<long long> dp(amount + 1, 0);
    dp[0] = 1;

    for (int coin : coins)
    {
        for (int T = coin; T <= amount; T++)
        {
            dp[T] += dp[T - coin];
        }
    }

    return (int)dp[amount];
}
