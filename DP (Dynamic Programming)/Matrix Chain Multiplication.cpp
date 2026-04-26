#include <bits/stdc++.h>
using namespace std;

// RECURSIVE
// T.C => EXPONENTIAL
class Solution
{
public:
    int f(int i, int j, vector<int> &arr)
    {
        if (i == j)
            return 0;
        int mini = 1e9;
        for (int k = i; k < j; k++)
        {
            int steps = (arr[i - 1] * arr[k] * arr[j]) + f(i, k, arr) + f(k + 1, j, arr);
            if (steps < mini)
                mini = steps;
        }
        return mini;
    }

    int matrixMultiplication(vector<int> &nums)
    {
        int n = nums.size();
        return f(1, n - 1, nums);
    }
};

// RECURSIVE + MEMOIZATION
// T.C => O(N*N)*N = O(N^3)
// S.C => O(N^2) + O(N)
class Solution
{
public:
    int f1(int i, int j, vector<int> &arr, vector<vector<int>> &dp)
    {
        if (i == j)
            return 0;
        int mini = 1e9;
        if (dp[i][j] != -1)
            return dp[i][j];
        for (int k = i; k < j; k++)
        {
            int steps = (arr[i - 1] * arr[k] * arr[j]) + f1(i, k, arr, dp) + f1(k + 1, j, arr, dp);
            if (steps < mini)
                mini = steps;
        }
        return dp[i][j] = mini;
    }

    int matrixMultiplication(vector<int> &nums)
    {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return f1(1, n - 1, nums, dp);
    }
};

// TABULTAION
// Time Complexity: O(N³)
// Space Complexity: O(N²)
class Solution
{
public:
    int matrixMultiplication(vector<int> &nums)
    {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));

        for (int i = n - 1; i >= 1; i--)
        {
            for (int j = i + 1; j <= n - 1; j++)
            {
                int mini = 1e9;
                for (int k = i; k < j; k++)
                {
                    int steps = (nums[i - 1] * nums[k] * nums[j]) + dp[i][k] + dp[k + 1][j];
                    if (steps < mini)
                        mini = steps;
                }
                dp[i][j] = mini;
            }
        }

        return dp[1][n - 1];
    }
};