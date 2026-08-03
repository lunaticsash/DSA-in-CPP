#include<bits/stdc++.h>
using namespace std;

//Memoization
// TC = O(n)
// SC = O(n) + O(n) (recursive stack space)
class Solution {
public:
    int solve(vector<int>& stoneValue, int i, int n, vector<int> &dp) {
        if (i >= n)
            return 0;

        if(dp[i] != -1) return dp[i];

        int ans = INT_MIN;
        int sum = 0;

        for (int k = 0; k < 3 && i + k < n; k++) {
            sum += stoneValue[i + k];
            ans = max(ans, sum - solve(stoneValue, i + k + 1, n, dp));
        }

        return dp[i] = ans;
    }

    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        vector<int> dp(n, -1);
        int ans = solve(stoneValue, 0, n, dp);
        if (ans > 0)
            return "Alice";
        else if (ans == 0)
            return "Tie";
        else
            return "Bob";
    }
};

//Tabulation
// TC = O(n)
// SC = O(n)
class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();

        vector<int> dp(n + 1, 0);

        for (int i = n - 1; i >= 0; i--) {
            int ans = INT_MIN;
            int sum = 0;

            for (int k = 0; k < 3 && i + k < n; k++) {
                sum += stoneValue[i + k];
                ans = max(ans, sum - dp[i + k + 1]);
            }

            dp[i] = ans;
        }

        if (dp[0] > 0)
            return "Alice";
        else if (dp[0] == 0)
            return "Tie";
        else
            return "Bob";
    }
};

//Space Optimization
//TC = O(n)
//SC = O(1)
class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();

        int dp1 = 0; // dp[i+1]
        int dp2 = 0; // dp[i+2]
        int dp3 = 0; // dp[i+3]

        for (int i = n - 1; i >= 0; i--) {
            int ans = INT_MIN;
            int sum = 0;

            // Take 1 stone
            sum += stoneValue[i];
            ans = max(ans, sum - dp1);

            // Take 2 stones
            if (i + 1 < n) {
                sum += stoneValue[i + 1];
                ans = max(ans, sum - dp2);
            }

            // Take 3 stones
            if (i + 2 < n) {
                sum += stoneValue[i + 2];
                ans = max(ans, sum - dp3);
            }

            // Shift the window
            dp3 = dp2;
            dp2 = dp1;
            dp1 = ans;
        }

        if (dp1 > 0)
            return "Alice";
        else if (dp1 == 0)
            return "Tie";
        else
            return "Bob";
    }
};