#include <bits/stdc++.h>
using namespace std;

// TC => O(N log M) where N is the number of piles and M is the maximum number of bananas in a pile.
// SC=> O(1) as we are using only a constant amount of extra space.
class Solution
{
public:
    bool isPossible(vector<int> &piles, int mid, int h)
    {
        int sum = 0;
        for (int i = 0; i < piles.size(); i++)
        {
            sum += (piles[i] + mid - 1) / mid;
            if (sum > h)
                return false;
        }
        return true;
    }

    int minEatingSpeed(vector<int> &piles, int h)
    {
        int n = piles.size();
        int ans = 0;
        int s = 1;
        int e = *max_element(piles.begin(), piles.end());

        int mid = 0;
        while (s <= e)
        {
            mid = s + (e - s) / 2;
            if (isPossible(piles, mid, h))
            {
                ans = mid;
                e = mid - 1;
            }
            else
                s = mid + 1;
        }
        return ans;
    }
};