#include <bits/stdc++.h>
using namespace std;

// TC => O(N)
// SC => O(1)
class Solution {
public:
    int jump(vector<int>& nums) {
        int jump = 0;
        int currEnd = 0;
        int farthest = 0;

        for(int i = 0; i < nums.size() - 1; i++){
            farthest = max(farthest, i + nums[i]);
            if(i == currEnd){
                jump++;
                currEnd = farthest; 
            }
        }

        return jump;

    }
};