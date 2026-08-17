#include <bits/stdc++.h>
using namespace std;

//Time:  O(n^3)
// Space: O(n)
// OPTIMIZATION IN DP FOLDER
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