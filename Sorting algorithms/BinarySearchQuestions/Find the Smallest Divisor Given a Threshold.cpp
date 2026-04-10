#include <bits/stdc++.h>
using namespace std;

//TC=> O(N log M) where N is the size of the input array and M is the maximum element in the array.
//SC=> O(1) as we are using only a constant amount of extra space.
class Solution
{
public:
    // Function to check if divisor is valid
    bool isPossible(vector<int> &nums, int divisor, int threshold)
    {
        int sum = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            sum += (nums[i] + divisor - 1) / divisor; // ceil division
        }

        return sum <= threshold;
    }

    int smallestDivisor(vector<int> &nums, int threshold)
    {
        int start = 1;
        int end = *max_element(nums.begin(), nums.end());
        int ans = end;

        while (start <= end)
        {
            int mid = start + (end - start) / 2;

            if (isPossible(nums, mid, threshold))
            {
                ans = mid;
                end = mid - 1; // try smaller divisor
            }
            else
            {
                start = mid + 1; // need bigger divisor
            }
        }

        return ans;
    }
};