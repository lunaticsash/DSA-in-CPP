#include <bits/stdc++.h>
using namespace std;

//Same as Hand of Straights.cpp in Heaps folder
class Solution
{
public:
    bool isPossibleDivide(vector<int> &nums, int k)
    {
        sort(nums.begin(), nums.end());
        queue<pair<int, int>> q;
        int requiredCount = 0;
        int pos = 0;
        while (pos < nums.size())
        {
            if (pos != 0 && (nums[pos] - 1) != nums[pos - 1] && !q.empty())
            {
                return false;
            }
            int cur = nums[pos];
            int count = 0;
            while (pos < nums.size() && nums[pos] == cur)
            {
                count++;
                pos++;
            }
            if (count < requiredCount)
            {
                return false;
            }
            else if (count > requiredCount)
            {
                q.push(make_pair(cur + k - 1, count - requiredCount));
                requiredCount = count;
            }
            if (!q.empty() && cur == q.front().first)
            {
                requiredCount = requiredCount - q.front().second;
                q.pop();
            }
        }
        if (!q.empty())
        {
            return false;
        }
        return true;
    }
};