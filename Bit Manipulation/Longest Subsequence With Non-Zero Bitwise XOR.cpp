#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n = nums.size();
        int xr = 0;

        for (int x : nums) {
            xr ^= x;
        }

        // Entire array has non-zero XOR
        if (xr != 0)
            return n;

        // Entire array XOR is 0.
        // If any element is non-zero, remove it.
        for (int x : nums) {
            if (x != 0)
                return n - 1;
        }

        // All elements are 0
        return 0;
    }
};