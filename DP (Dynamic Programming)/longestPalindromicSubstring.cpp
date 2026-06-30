#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int f1(int i, int j, string &s, string &t, vector<vector<int>> &dp)
    {
        if (i < 0 || j < 0)
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        if (s[i] == t[j])
            return dp[i][j] = 1 + f1(i - 1, j - 1, s, t, dp);

        return dp[i][j] = max(f1(i - 1, j, s, t, dp),
                              f1(i, j - 1, s, t, dp));
    }
    string longestPalindrome(string s)
    {
        string t = s;
        reverse(t.begin(), t.end());

        int n = s.size();
        int m = t.size();

        vector<vector<int>> dp(n, vector<int>(m, -1));
        int len = f1(n - 1, m - 1, s, t, dp);

        string ans = "";
        int i = n - 1;
        int j = m - 1;

        while (i >= 0 && j >= 0)
        {
            if (s[i] == t[j])
            {
                ans += s[i];
                i--;
                j--;
            }
            else
            {
                if (dp[i][j] == dp[i - 1][j])
                    i--;
                else
                    j--;
            }
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};