#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long minMoves(vector<int>& nums) {
        int n = nums.size();
        int minel = *min_element(nums.begin(),nums.end());
        int ans = 0;

        for(int it: nums){
            ans += abs(it - minel);
        }

        return ans;
    }      
};