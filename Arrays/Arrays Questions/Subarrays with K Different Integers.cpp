#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int subarraysWithKDistinct(vector<int> &nums, int k)
    {
        return atMostK(nums, k) - atMostK(nums, k - 1);
    }
    int atMostK(vector<int> &nums, int k)
    {
        int n = nums.size();
        unordered_map<int, int> count;
        int left = 0, right = 0;
        int result = 0;

        while (right < n)
        {
            if (count[nums[right]] == 0)
            {
                k--;
            }
            count[nums[right]]++;
            right++;

            while (k < 0)
            {
                count[nums[left]]--;
                if (count[nums[left]] == 0)
                {
                    k++;
                }
                left++;
            }

            result += right - left;
        }

        return result;
    }
};