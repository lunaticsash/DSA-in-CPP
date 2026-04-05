#include <bits/stdc++.h>
using namespace std;

int f(int i, int j, string &s, string &t, vector<vector<int>> &dp, int &ans)
{
    if (i < 0 || j < 0)
        return 0;

    if (dp[i][j] != -1)
        return dp[i][j];

    int length = 0;

    if (s[i] == t[j])
    {
        length = 1 + f(i - 1, j - 1, s, t, dp, ans);
        ans = max(ans, length); // track global max
    }
    else
    {
        length = 0; // reset because substring must be continuous
    }

    // ❗ Still call for other combinations to explore all pairs
    f(i - 1, j, s, t, dp, ans);
    f(i, j - 1, s, t, dp, ans);

    return dp[i][j] = length;
}

// Tabulation directly through largest common subsequence with some small changes
int lcs3(string s, string t)
{
    int n = s.size();
    int m = t.size();

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0)); //

    for (int i = 0; i <= n; i++)
        dp[i][0] = 0;
    for (int j = 0; j <= m; j++)
        dp[0][j] = 0;

    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (s[i - 1] == t[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
                ans = max(ans, dp[i][j]);
            }
            else
                dp[i][j] = 0;
        }
    }

    return ans;
}

// Space Optimization
int lcs3(string s, string t)
{
    int n = s.size();
    int m = t.size();

    vector<int> prev(m + 1, 0);
    vector<int> cur(m + 1, 0);

    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (s[i - 1] == t[j - 1])
            {
                cur[j] = 1 + prev[j - 1];
                ans = max(ans, cur[j]);
            }
            else
                cur[j] = 0;
        }
        prev = cur;
    }

    return ans;
}


//Memoization
int helper(string s1, string s2, int m, int n, int count) {

        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        if (m < 0 || n < 0) {
            return count;
        }

        if (dp[m][n][count] != -1) {
            return dp[m][n][count];
        }

        int currCount = count;

        // case 1: characters match → extend substring
        if (s1.charAt(m) == s2.charAt(n)) {
            currCount = helper(s1, s2, m - 1, n - 1, count + 1);
        }

        // case 2: mismatch → restart from neighbors
        int left = helper(s1, s2, m - 1, n, 0);
        int up   = helper(s1, s2, m, n - 1, 0);

        return dp[m][n][count] = Math.max(currCount, Math.max(left, up));
 }