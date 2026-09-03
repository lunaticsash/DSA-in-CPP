#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool uniformArray(vector<int> &nums1)
    {
        int minel = *minel(begin(nums1), end(nums1));

        // check for if the min is odd then parity change will always will be possible
        if (minel % 2 == 1)
        { // min is odd
            return true;
        }

        // if it is even
        // Check if we can make all even
        for (int &num : nums1)
        {
            if (num % 2 == 1)
            {
                return false;
            }
        }

        return true;
    }
};