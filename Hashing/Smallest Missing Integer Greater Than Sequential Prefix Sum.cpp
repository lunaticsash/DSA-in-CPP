#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int n = nums.size();
        int sum = nums[0];
        unordered_set<int> mp;

        for (auto it : nums) {
            mp.insert(it);
        }

        for(int j = 1 ; j < n ; j++){
            if(nums[j] == nums[j - 1] + 1){
                sum += nums[j];
            }
            else{
                break;
            }
        }

        while (true) {
            if (mp.count(sum)) {
                sum++;
            }
            else {
                return sum;
            }
        }
    }
};