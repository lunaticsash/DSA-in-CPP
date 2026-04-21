#include <bits/stdc++.h>
using namespace std;

// TC => O(N)
// SC => O(1)
class Solution
{
public:
    bool canJump(vector<int> &nums)
    {
        int maxReach = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            if (i > maxReach)
                return false;
            maxReach = max(maxReach, i + nums[i]);
        }
        return true;
    }
};