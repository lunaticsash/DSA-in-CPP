#include <bits/stdc++.h>
using namespace std;


//Recusion
//T.c => O(2^n)
//S.C => O(n) (recursive stack space)
class Solution
{
public:
    int f(int ind, int prev_ind, int n, vector<int> &nums)
    {
        if(ind == n) return 0;

        int len = 0 + f(ind + 1, prev_ind, n, nums); // NotTake
        if (prev_ind == -1 || nums[ind] > nums[prev_ind])//take
            len = max(len, 1 + f(ind + 1, ind,n, nums));
        return len;
    }

    int LIS(vector<int> &nums)
    {
        int n = nums.size();
        return f(0, -1, n, nums);
    }
};

//Recursion + Memoization
//T.c => O(n*n)
//S.C => O(n^n) + O(n) (recursive stack space)
class Solution
{
public:
    int f2(int ind, int prev_ind, int n, vector<int> &nums, vector<vector<int>> &dp)
    {
        if(ind == n) return 0;

        if(dp[ind][prev_ind + 1] != -1) return dp[ind][prev_ind + 1];

        int len = 0 + f2(ind + 1, prev_ind, n, nums, dp); // NotTake
        if (prev_ind == -1 || nums[ind] > nums[prev_ind])//take
            len = max(len, 1 + f2(ind + 1, ind,n, nums, dp));
        return dp[ind][prev_ind + 1] = len;
    }

    int LIS(vector<int> &nums)
    {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        return f2(0, -1, n, nums, dp);
    }
};

//Tabulation
//T.C => O(n^2)
//S.C => O(n^2)
class Solution
{
public:
    int LIS(vector<int> &nums)
    {
        int n = nums.size();
        // dp[ind][prev_ind + 1]
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

        // Base case: dp[n][anything] = 0 (already handled by initialization)

        for (int ind = n - 1; ind >= 0; ind--)
        {
            for (int prev_ind = ind - 1; prev_ind >= -1; prev_ind--)
            {
                int len = dp[ind + 1][prev_ind + 1]; // NotTake

                if (prev_ind == -1 || nums[ind] > nums[prev_ind]) // Take
                    len = max(len, 1 + dp[ind + 1][ind + 1]);

                dp[ind][prev_ind + 1] = len;
            }
        }

        return dp[0][0]; // ind=0, prev_ind=-1 => prev_ind+1=0
    }
};

//Space Optimization
//T.C => O(n^2)
//S.C => O(n)
class Solution
{
public:
    int LIS(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> dp(n, 1); // every element is LIS of length 1

        int ans = 1;
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (nums[j] < nums[i])
                    dp[i] = max(dp[i], 1 + dp[j]);
            }
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};

//BINARY SEARCH
//T.C => O(n log n)
//S.C => O(n)
class Solution
{
public:
    int LIS(vector<int> &nums)
    {
        vector<int> temp;
        for (int x : nums)
        {
            auto it = lower_bound(temp.begin(), temp.end(), x);
            if (it == temp.end())
                temp.push_back(x);
            else
                *it = x; // replace to maintain smallest possible tail
        }
        return temp.size();
    }
};