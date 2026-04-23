#include <bits/stdc++.h>
using namespace std;

//T.C => O(N^2)
//S.C => O(N)
//Modified tabulation code of longest increasing subsequence
class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1), cnt(n, 1);
        int maxi = 0;
        for (int i = 0; i < n; i++) {
            for (int prev = 0; prev < i; prev++) {
                if (nums[prev] < nums[i] && dp[prev] + 1 > dp[i]) {
                    dp[i] = dp[prev] + 1;
                    // inherit
                    cnt[i] = cnt[prev];
                } else if (dp[prev] + 1 == dp[i] && nums[prev] < nums[i]) {

                    // increase the count when recieved same
                    cnt[i] = cnt[prev] + cnt[i];
                }
            }
            maxi = max(maxi, dp[i]);
        }

        int number = 0;
        for (int i = 0; i < n; i++)
            if (dp[i] == maxi)
                number = cnt[i] + number;

        return number;
    }
};