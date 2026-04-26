#include <bits/stdc++.h>
using namespace std;

// RECURSIVE + MEMOIZATION
//  TIME COMPLEXITY IS NEAR ABOUT O(N^3)
//  SPACE COMPLEXITY IS NEAR ABOUT O(N^2) + O(N)
class Solution
{
public:
    int f(int i, int j, vector<int> &arr, vector<vector<int>> &dp)
    {
        if (i > j)
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];

        int maxi = 0;
        for (int k = i; k <= j; k++)
        {
            // k is burst LAST in range [i,j]
            // arr[i-1] and arr[j+1] are still alive as boundaries
            int coins = arr[i - 1] * arr[k] * arr[j + 1] +
                        f(i, k - 1, arr, dp) + f(k + 1, j, arr, dp);
            maxi = max(maxi, coins);
        }
        return dp[i][j] = maxi;
    }

    int maxCoins(vector<int> &nums)
    {
        int n = nums.size();
        // Add boundary balloons with value 1
        nums.insert(nums.begin(), 1);
        nums.push_back(1);

        // dp is (n+2) x (n+2), solve for range [1, n]
        vector<vector<int>> dp(n + 2, vector<int>(n + 2, -1));
        return f(1, n, nums, dp);
    }
};


// TABULATION
class Solution2
{
public:
    int maxCoins(vector<int> &nums)
    {
        int n = nums.size();
        // Add boundary balloons with value 1
        nums.insert(nums.begin(), 1);
        nums.push_back(1);

        // dp is (n+2) x (n+2), solve for range [1, n]
        vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));
        for (int i = n; i >= 1; i--)
        {
            for (int j = 1; j <= n; j++)
            {
                if (i > j)
                    continue;
                int maxi = 0;
                for (int k = i; k <= j; k++)
                {
                    int coins = nums[i - 1] * nums[k] * nums[j + 1] +
                                dp[i][k - 1] + dp[k + 1][j];
                    maxi = max(maxi, coins);
                }
                dp[i][j] = maxi;
            }
        }

        return dp[1][n];
    }
};