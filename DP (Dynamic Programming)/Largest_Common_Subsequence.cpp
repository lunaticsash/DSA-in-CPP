#include <bits/stdc++.h>
using namespace std;

// Recusrion +Memoization
// T.C => O(N x M)
// S.C => O(N x M) + O(N+M)
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

int lcs(string s, string t)
{
    int n = s.size();
    int m = t.size();

    vector<vector<int>> dp(n, vector<int>(m, -1));
    return f1(n - 1, m - 1, s, t, dp);
}

// Shifting for easier base case which I'll use inn tabulation
int f2(int i, int j, string &s, string &t, vector<vector<int>> &dp)
{
    if (i == 0 || j == 0) //
        return 0;

    if (dp[i][j] != -1)
        return dp[i][j];

    if (s[i - 1] == t[j - 1]) //
        return dp[i][j] = 1 + f2(i - 1, j - 1, s, t, dp);

    return dp[i][j] = max(f2(i - 1, j, s, t, dp),
                          f2(i, j - 1, s, t, dp));
}

int lcs2(string s, string t)
{
    int n = s.size();
    int m = t.size();

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1)); //
    return f2(n, m, s, t, dp);                             //
}

// Tabulation
// TC => O(n*m)
// SC => O(n * m)
int lcs3(string s, string t)
{
    int n = s.size();
    int m = t.size();

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0)); //

    for (int i = 0; i <= n; i++)
        dp[i][0] = 0;
    for (int j = 0; j <= m; j++)
        dp[0][j] = 0;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (s[i - 1] == t[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j],
                               dp[i][j - 1]);
        }
    }

    return dp[n][m]; //
}

// Space optimization
// TC => O(n*m)
// SC => O(2N) = O(N)
int lcs4(string s, string t)
{
    int n = s.size();
    int m = t.size();

    vector<int> prev(m + 1, 0);
    vector<int> cur(m + 1, 0);

    for (int j = 0; j <= m; j++)
        prev[j] = 0;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (s[i - 1] == t[j - 1])
                cur[j] = 1 + prev[j - 1];
            else
                cur[j] = max(prev[j],
                             cur[j - 1]);
        }
        prev = cur;
    }

    return prev[m]; //
}