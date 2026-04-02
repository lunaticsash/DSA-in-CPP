#include <bits/stdc++.h>
using namespace std;

// Recusrive
class Solution
{
public:
    int f(int ind, int T, vector<int> &nums)
    {
        if (ind == 0)
        {
            if (T % nums[ind] == 0)
                return T / nums[ind];
            else
                return 1e9;
        }

        int notTake = 0 + f(ind - 1, T, nums);
        int take = INT_MAX;
        if (nums[ind] <= T)
            take = 1 + f(ind, T - nums[ind], nums);

        return min(take, notTake);
    }
    int coinChange(vector<int> &coins, int amount)
    {
        int n = coins.size();
        int ans = f(n - 1, amount, coins);

        if (ans >= 1e9)
            return -1;
        return ans;
    }
};

// Recusive + Memoization
class Solution
{
public:
    int f(int ind, int T, vector<int> &nums, vector<vector<int>> &dp)
    {
        if (ind == 0)
        {
            if (T % nums[ind] == 0)
                return T / nums[ind];
            else
                return 1e9;
        }

        if (dp[ind][T] != -1)
            return dp[ind][T];

        int notTake = 0 + f(ind - 1, T, nums, dp);
        int take = INT_MAX;
        if (nums[ind] <= T)
            take = 1 + f(ind, T - nums[ind], nums, dp);

        return dp[ind][T] = min(take, notTake);
    }
    int coinChange(vector<int> &coins, int amount)
    {
        int n = coins.size();

        vector<vector<int>> dp(n + 1, vector<int>(amount + 1, -1));

        int ans = f(n - 1, amount, coins, dp);

        if (ans >= 1e9)
            return -1;
        return ans;
    }
};

// Tabulation
int coinChange(vector<int> &coins, int amount)
{
    int n = coins.size();

    vector<vector<int>> dp(n, vector<int>(amount + 1, 0));

    for (int T = 0; T <= amount; T++)
    {
        if (T % coins[0] == 0)
        {
            dp[0][T] = T / coins[0];
        }
        else
        {
            dp[0][T] = 1e9;
        }
    }

    for (int ind = 1; ind <= n - 1; ind++)
    {
        for (int tar = 0; tar <= amount; tar++)
        {
            int notTake = 0 + dp[ind - 1][tar];
            int take = INT_MAX;
            if (coins[ind] <= tar)
                take = 1 + dp[ind][tar - coins[ind]];

            dp[ind][tar] = min(take, notTake);
        }
    }

    int ans = dp[n - 1][amount];

    if (ans >= 1e9)
        return -1;
    return ans;
}

// Space Optimization
int coinChange(vector<int> &coins, int amount)
{
    int n = coins.size();

    vector<int> prev(amount + 1, 0), cur(amount + 1, 0);

    for (int T = 0; T <= amount; T++)
    {
        if (T % coins[0] == 0)
        {
            prev[T] = T / coins[0];
        }
        else
        {
            prev[T] = 1e9;
        }
    }

    for (int ind = 1; ind <= n - 1; ind++)
    {
        for (int tar = 0; tar <= amount; tar++)
        {
            int notTake = 0 + prev[tar];
            int take = INT_MAX;
            if (coins[ind] <= tar)
                take = 1 + cur[tar - coins[ind]];

            cur[tar] = min(take, notTake);
        }
        prev = cur;
    }

    int ans = prev[amount];

    if (ans >= 1e9)
        return -1;
    return ans;
}
