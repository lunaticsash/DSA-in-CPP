#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    int atMost(vector<int>& nums, int k) {
        int i = 0, res = 0;

        for(int j = 0; j < nums.size(); j++) {

            if(nums[j] % 2 != 0) k--;  // odd mila

            while(k < 0) {
                if(nums[i] % 2 != 0) k++;
                i++;
            }

            res += (j - i + 1); // all subarrays ending at j
        }

        return res;
    }

    int numberOfSubarrays(vector<int>& nums, int k) {
        return atMost(nums, k) - atMost(nums, k - 1);
    }
};