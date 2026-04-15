#include<bits/stdc++.h>
using namespace std;


//TC => O(N)
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l = 0, r = 0;
        int zeros = 0;
        int maxi = 0;

        while(r < nums.size()) {

            // Expand
            if(nums[r] == 0) zeros++;

            // Shrink if invalid
            while(zeros > k) {
                if(nums[l] == 0) zeros--;
                l++;
            }

            // Update answer
            maxi = max(maxi, r - l + 1);
            r++;
        }

        return maxi;
    }
};