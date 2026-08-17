#include <bits/stdc++.h>
using namespace std;

//tc = O(n^2)
class Solution {
public:
    int stoneGameV(vector<int>& stoneValue) {

        int n = stoneValue.size();

        // dp[i][j] = answer for interval [i...j]
        vector<vector<int>> dp(n, vector<int>(n, 0));

        // mx[i][j]:
        // max(dp[i][k] + sum(i...k)) for k in [i...j]
        //
        // mx[j][i]:
        // max(dp[k][j] + sum(k...j)) for k in [i...j]
        vector<vector<int>> mx(n, vector<int>(n, 0));

        // For one stone:
        // dp[i][i] = 0
        // mx[i][i] = stoneValue[i]
        for (int i = 0; i < n; i++) {
            mx[i][i] = stoneValue[i];
        }

        // j = right endpoint
        for (int j = 1; j < n; j++) {

            int mid = j;

            // Sum of current right part
            int rightSum = 0;

            // Total sum of current interval
            int totalSum = stoneValue[j];

            // Move i from right -> left
            for (int i = j - 1; i >= 0; i--) {

                totalSum += stoneValue[i];

                /*
                    We maintain:

                    [i ... mid] | [mid+1 ... j]

                    rightSum = sum(mid+1 ... j)
                */

                while (mid > i &&
                       (rightSum + stoneValue[mid]) * 2 <= totalSum) {

                    rightSum += stoneValue[mid];
                    mid--;
                }

                // Equal case:
                // sum(i...mid) == sum(mid+1...j)
                if (rightSum * 2 == totalSum) {
                    dp[i][j] = mx[i][mid];
                }

                // Left side is smaller
                if (mid != i) {
                    dp[i][j] = max(dp[i][j],
                                   mx[i][mid - 1]);
                }

                // Right side is smaller
                if (mid != j) {
                    dp[i][j] = max(dp[i][j],
                                   mx[j][mid + 1]);
                }

                /*
                    Update mx tables.

                    sum(i...j) = totalSum
                */

                mx[i][j] = max(
                    mx[i][j - 1],
                    dp[i][j] + totalSum
                );

                mx[j][i] = max(
                    mx[j][i + 1],
                    dp[i][j] + totalSum
                );
            }
        }

        return dp[0][n - 1];
    }
};

//Tabulation
class Solution {
public:
    int stoneGameV(vector<int>& stoneValue) {
        int n = stoneValue.size();

        vector<int> prefix(n + 1, 0);

        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + stoneValue[i];
        }

        vector<vector<int>> dp(n, vector<int>(n, 0));

        for (int len = 2; len <= n; len++) {
            for (int i = 0; i <= n - len; i++) {
                int j = i + len - 1;
                for (int k = i; k < j; k++) {
                    int leftSum = prefix[k + 1] - prefix[i];
                    int rightSum = prefix[j + 1] - prefix[k + 1];
                    if (leftSum < rightSum) {
                        dp[i][j] = max(dp[i][j], leftSum + dp[i][k]);
                    } else if (leftSum > rightSum) {
                        dp[i][j] = max(dp[i][j], rightSum + dp[k + 1][j]);
                    } else {
                        dp[i][j] = max(dp[i][j], max(leftSum + dp[i][k], rightSum + dp[k + 1][j]));
                    }
                }
            }
        }

        return dp[0][n - 1];
    }
};
//Memoization
//Time:  O(n^2)
// Space: O(n^2)
class Solution {
public:
    vector<int> stoneValue;
    vector<int> prefix;

    int solve(int l, int r, vector<vector<int>>& dp) {

        // Base case
        if (l == r)
            return 0;

        // Already calculated
        if (dp[l][r] != -1)
            return dp[l][r];

        int ans = 0;

        // Try every possible split
        for (int i = l; i < r; i++) {

            // Sum of [l ... i]
            int leftSum = prefix[i + 1] - prefix[l];

            // Sum of [i + 1 ... r]
            int rightSum = prefix[r + 1] - prefix[i + 1];

            // Left part is smaller
            if (leftSum < rightSum) {

                ans = max(ans,
                          leftSum + solve(l, i, dp));
            }

            // Right part is smaller
            else if (leftSum > rightSum) {

                ans = max(ans,
                          rightSum + solve(i + 1, r, dp));
            }

            // Both parts are equal
            else {

                ans = max(ans,
                          max(leftSum + solve(l, i, dp),
                              rightSum + solve(i + 1, r, dp)));
            }
        }

        return dp[l][r] = ans;
    }

    int stoneGameV(vector<int>& stoneValue) {

        this->stoneValue = stoneValue;

        int n = stoneValue.size();

        // Prefix Sum
        prefix.resize(n + 1, 0);

        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + stoneValue[i];
        }

        // 2D DP for memoization
        vector<vector<int>> dp(n, vector<int>(n, -1));

        return solve(0, n - 1, dp);
    }
};

//Time:  O(n^3)
// Space: O(n)
class Solution {
public:
    vector<int> stoneValue;

    int solve(int l, int r) {
        // base case
        if (l == r)
            return 0;

        int ans = 0;

        for (int i = l; i < r; i++) {
            int leftSum = 0;
            int rightSum = 0;

            // Calculate left sum: [l ... i]
            for (int j = l; j <= i; j++) {
                leftSum += stoneValue[j];
            }

            // Calculate right sum: [i+1 ... r]
            for (int j = i + 1; j <= r; j++) {
                rightSum += stoneValue[j];
            }

            // 3 cases
            if (leftSum < rightSum) {
                ans = max(ans, leftSum + solve(l, i));
            } 
            else if (leftSum > rightSum) {
                ans = max(ans, rightSum + solve(i + 1, r));
            } 
            else {
                ans = max(ans, max(leftSum + solve(l, i),
                                   rightSum + solve(i + 1, r)));
            }
        }

        return ans;
    }
    int stoneGameV(vector<int>& stoneValue) {
        this->stoneValue = stoneValue;
        
        return solve(0, stoneValue.size() - 1);
    }
};