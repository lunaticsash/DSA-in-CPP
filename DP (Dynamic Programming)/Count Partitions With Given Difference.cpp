#include<bits/stdc++.h>
using namespace std;

int mod = 1e9 + 7;

//recursive + memoization
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

    return dp[ind][sum] = (notTake + take) % mod;
}

int findWays(vector<int> &num, int tar)
{
    int n = num.size();

    vector<vector<int>> dp(n, vector<int>(tar + 1, -1));
    return f2(n-1, tar, num, dp);
    

}

int countPartitions ( int n , int d, vector<int> &arr){
    int totsum = 0;
    for(auto &it: arr) totsum += it ;
    if((totsum - d) <0 || (totsum -d) %2) return 0;
    return findWays(arr, (totsum - d)/2);
}


//Tabulation
int findWaysTabulation(vector<int> &num, int tar)
{
    int n = num.size();

    vector<vector<int>> dp(n, vector<int>(tar + 1, 0));

    if(num [0] == 0) dp[0][0] = 2; //we have 2 cases take or not take 
    else dp[0][0] = 1; //we have only one case that is not take

    // num[0] = 0
    if(num[0] != 0 && num[0] <= tar) dp[0][num[0]] = 1; //we have only one case that is take
    for(int i = 1; i<n; i++){
        for(int sum = 0; sum<=tar; sum++){
            int notTake = dp[i-1][sum];
            int take = 0;
            if(num[i] <= sum) take = dp[i-1][sum-num[i]];
            dp[i][sum] = (notTake + take)% mod;
        }
    }
    return dp[n-1][tar];
}

