#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxSubarrayLength(vector<int> &nums, int k)
    {
        int maxlen = 0, l = 0, r = 0;
        unordered_map<int, int> mpp;

        while (r < nums.size())
        {
            mpp[nums[r]]++;
            while (mpp[nums[r]] > k)
            {
                mpp[nums[l]]--;
                l++;
            }
            maxlen = max(maxlen, r - l + 1);
            r++;
        }
        return maxlen;
    }
};