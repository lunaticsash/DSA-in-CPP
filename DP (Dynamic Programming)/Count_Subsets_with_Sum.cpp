#include <bits/stdc++.h>
using namespace std;

// recursive
// TC -> O(2^n)
// SC -> O(n)  aux stack space
int f(int ind, int sum, vector<int> &num)
{
    if (sum == 0)
        return 1;
    if (ind == 0)
        return num[0] == sum;

    int notTake = f(ind - 1, sum, num);
    int take = 0;
    if (num[ind] <= sum)
        take = f(ind - 1, sum - num[ind], num);

    return notTake + take;
}

// memoization
//TC -> O(n * tar)
//SC -> O(n * tar) + O(n) aux stack space
int f2(int ind, int sum, vector<int> &num, vector<vector<int>> &dp)
{
    if (sum == 0)
        return 1;
    if (ind == 0)
        return num[0] == sum;

    if (dp[ind][sum] != -1)
        return dp[ind][sum];

    int notTake = f2(ind - 1, sum, num, dp);
    int take = 0;
    if (num[ind] <= sum)
        take = f2(ind - 1, sum - num[ind], num, dp);

    return dp[ind][sum] = notTake + take;
}

int findWays(vector<int> &num, int tar)
{
    int n = num.size();

    vector<vector<int>> dp(n, vector<int>(tar + 1, -1));
    return f2(n - 1, tar, num, dp);
}


//Tabulation
//TC -> O(n * tar)
//SC -> O(n) aux stack space
int findWaysTabulation(vector<int> &num, int tar)
{
    int n = num.size();

    vector<vector<int>> dp(n, vector<int>(tar + 1, 0));

    for(int i =0; i<n; i++){
        dp[i][0] = 1;
    }

    if(num[0] <= tar) dp[0][num[0]] = 1;
    
    for(int i = 1; i<n; i++){
        for(int sum = 0; sum<=tar; sum++){
            int notTake = dp[i-1][sum];
            int take = 0;
            if(num[i] <= sum) take = dp[i-1][sum-num[i]];
            dp[i][sum] = notTake + take;
        }
    }
    return dp[n-1][tar];
}

//Space Optimization
//TC -> O(n * tar)
//SC -> O(tar) aux stack space
int findWaysSpaceOptimization(vector<int> &num, int tar)
{
    int n = num.size();

    vector<int> prev(tar + 1, 0);
    vector<int> cur(tar + 1, 0);

    prev[0] = cur[0] = 1;

    if(num[0] <= tar) prev[num[0]] = 1;
    
    for(int i = 1; i<n; i++){
        for(int sum = 0; sum<=tar; sum++){
            int notTake = prev[sum];
            int take = 0;
            if(num[i] <= sum) take = prev[sum-num[i]];
            cur[sum] = notTake + take;
        }
        prev = cur;
    }
    return prev[tar];
}
