
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool solve(vector<int>& sticks, int index,
               int side1, int side2, int side3, int side4,
               int target) {

        // All sticks used
        if (index == sticks.size()) {
            return side1 == target &&
                   side2 == target &&
                   side3 == target &&
                   side4 == target;
        }

        int stick = sticks[index];

        // Try putting current stick on side 1
        if (side1 + stick <= target) {
            if (solve(sticks, index + 1,
                      side1 + stick, side2, side3, side4, target))
                return true;
        }

        // Try side 2
        if (side2 + stick <= target) {
            if (solve(sticks, index + 1,
                      side1, side2 + stick, side3, side4, target))
                return true;
        }

        // Try side 3
        if (side3 + stick <= target) {
            if (solve(sticks, index + 1,
                      side1, side2, side3 + stick, side4, target))
                return true;
        }

        // Try side 4
        if (side4 + stick <= target) {
            if (solve(sticks, index + 1,
                      side1, side2, side3, side4 + stick, target))
                return true;
        }

        return false;
    }

    bool makesquare(vector<int>& matchsticks) {

        int sum = 0;

        for (int x : matchsticks)
            sum += x;

        if (sum % 4 != 0)
            return false;

        int target = sum / 4;

        return solve(matchsticks, 0, 0, 0, 0, 0, target);
    }
};

class Solution {
public:
    bool makesquare(vector<int>& matchsticks) {

        int n = matchsticks.size();

        int total = accumulate(matchsticks.begin(),
                               matchsticks.end(), 0);

        if (total % 4 != 0)
            return false;

        int target = total / 4;

        vector<int> dp(1 << n, -1);

        dp[0] = 0;

        for (int mask = 0; mask < (1 << n); mask++) {

            if (dp[mask] == -1)
                continue;

            for (int i = 0; i < n; i++) {

                if (mask & (1 << i))
                    continue;

                if (dp[mask] + matchsticks[i] > target)
                    continue;

                int newMask = mask | (1 << i);

                dp[newMask] =
                    (dp[mask] + matchsticks[i]) % target;
            }
        }

        return dp[(1 << n) - 1] == 0;
    }
};