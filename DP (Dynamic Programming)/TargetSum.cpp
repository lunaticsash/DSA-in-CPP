#include <bits/stdc++.h>
using namespace std;


//tc -> O(n * tar)
//sc -> O(n * tar)

class Solution {
public:
    int findWays(vector<int>& num, int tar) {
        int n = num.size();

        vector<vector<int>> dp(n, vector<int>(tar + 1, 0));

        if (num[0] == 0)
            dp[0][0] = 2; // we have 2 cases take or not take
        else
            dp[0][0] = 1; // we have only one case that is not take

        // num[0] = 0
        if (num[0] != 0 && num[0] <= tar)
            dp[0][num[0]] = 1; // we have only one case that is take
        for (int i = 1; i < n; i++) {
            for (int sum = 0; sum <= tar; sum++) {
                int notTake = dp[i - 1][sum];
                int take = 0;
                if (num[i] <= sum)
                    take = dp[i - 1][sum - num[i]];
                dp[i][sum] = (notTake + take);
            }
        }
        return dp[n - 1][tar];
    }

    int countPartitions(int n, int d, vector<int>& arr) {
        int totsum = 0;
        for (auto& it : arr)
            totsum += it;
        if ((totsum - d) < 0 || (totsum - d) % 2)
            return 0;
        return findWays(arr, (totsum - d) / 2);
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        return countPartitions(nums.size(), target, nums);
    }
};