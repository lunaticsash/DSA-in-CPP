#include <bits/stdc++.h>
using namespace std;

// T.C => O(n log n + n^2 * L)
// S.C => O(n)
class Solution
{
public:
    bool checkPossible(string &s1, string &s2)
    {
        if (s1.size() != s2.size() + 1)
            return false; // s1 is greater guy
        int first = 0;
        int second = 0;
        while (first < s1.size())
        {
            if (s1[first] == s2[second])
            {
                first++;
                second++;
            }
            else
            {
                first++;
            }

            if (first == s1.size() && second == s2.size())
                return true;
        }
        return false;
    }

    static bool comp(string &s1, string &s2) { return s1.size() < s2.size(); }

    int longestStrChain(vector<string> &arr)
    {
        sort(arr.begin(), arr.end(), comp);
        int n = arr.size();
        int maxi = 1;
        vector<int> dp(n, 1);

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (checkPossible(arr[i], arr[j]) && dp[i] < dp[j] + 1)
                {
                    dp[i] = dp[j] + 1;
                }
            }
            if (dp[i] > maxi)
            {
                maxi = dp[i];
            }
        }

        return maxi;
    }
};