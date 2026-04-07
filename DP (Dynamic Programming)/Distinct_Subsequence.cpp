#include <bits/stdc++.h>
using namespace std;

// RECURSION + MEMOIZATION
// T.C => O(N*M)
// S.C => O(N*M) + O(N*M)
class Solution
{
public:
    int f(int i, int j, string s1, string s2, vector<vector<int>> dp)
    {
        if (j == 0)
            return 1;
        if (i == 0)
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        if (s1[i - 1] == s2[j - 1])
            return dp[i][j] =
                       f(i - 1, j - 1, s1, s2, dp) + f(i - 1, j, s1, s2, dp);
        else
            return dp[i][j] = f(i - 1, j, s1, s2, dp);
    }
    int numDistinct(string s, string t)
    {
        int n = s.size();
        int m = t.size();

        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        return f(n, m, s, t, dp);
    }
};

// TABULATION
class Solution
{
public:
    int numDistinct(string s, string t)
    {
        int n = s.size();
        int m = t.size();

        vector<vector<double>> dp(n + 1, vector<double>(m + 1, 0));
        for (int i = 0; i <= n; i++)
            dp[i][0] = 1;

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (s[i - 1] == t[j - 1])
                    dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
                else
                    dp[i][j] = dp[i - 1][j];
            }
        }
        return (int)dp[n][m];
    }
};

// Why we go from j = m to 1 (important for you in DSA)

// Think of it like updating exam marks:

// dp[j] depends on previous row’s dp[j-1]

// If we go forward, we overwrite values too early.

// Going backward preserves the previous state correctly.

//Space optimized
//S.C => O(N)
int numDistinct(string s, string t) {
    int n = s.size();
    int m = t.size();

    vector<double> dp(m + 1, 0);

    // Base case: empty target string
    dp[0] = 1;

    for (int i = 1; i <= n; i++) {
        // Traverse backwards to avoid overwriting needed values
        for (int j = m; j >= 1; j--) {
            if (s[i - 1] == t[j - 1]) {
                dp[j] = dp[j - 1] + dp[j];
            }
        }
    }

    return (int)dp[m];
}
