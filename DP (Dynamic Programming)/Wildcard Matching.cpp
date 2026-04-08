#include <bits/stdc++.h>
using namespace std;

// RECURSIVE
// T.C = exponential
// S.C = O(N+M)
class Solution
{
public:
    bool f(int i, int j, string &pattern, string &text)
    {
        if (i < 0 && j < 0)
            return true;
        if (i < 0 && j >= 0)
            return false;
        if (j < 0 && i >= 0)
        {
            for (int ii = 0; ii <= i; ii++)
            {
                if (pattern[ii] != '*')
                    return false;
            }
            return true;
        }
        if (pattern[i] == text[j] || pattern[i] == '?')
            return f(i - 1, j - 1, pattern, text);
        if (pattern[i] == '*')
        {
            return f(i - 1, j, pattern, text) ||
                   f(i, j - 1, pattern, text);
        }
        return false;
    }

    bool isMatch(string s, string p)
    {
        int n = s.size();
        int m = p.size();

        return f(m - 1, n - 1, p, s);
    }
};

// RECURSIVE + MEMOIZATION
// T.C = O(N*M)
// S.C = O(N+M) + O(N*M)
// RECURSIVE + MEMOIZATION
// T.C = O(N*M)
// S.C = O(N+M) + O(N*M)
class Solution
{
public:
    bool f2(int i, int j, string &pattern, string &text,
            vector<vector<int>> &dp)
    {
        if (i == 0 && j == 0)
            return true;
        if (i == 0 && j > 0)
            return false;

        if (j == 0 && i > 0)
        {
            for (int ii = 1; ii <= i; ii++)
            {
                if (pattern[ii - 1] != '*')
                    return false;
            }
            return true;
        }

        if (dp[i][j] != -1)
            return dp[i][j];
        if (pattern[i - 1] == text[j - 1] || pattern[i - 1] == '?')
            return dp[i][j] = f2(i - 1, j - 1, pattern, text, dp);
        if (pattern[i - 1] == '*')
        {
            return dp[i][j] = f2(i - 1, j, pattern, text, dp) ||
                              f2(i, j - 1, pattern, text, dp);
        }
        return dp[i][j] = false;
    }

    bool isMatch(string s, string p)
    {
        int n = s.size();
        int m = p.size();

        vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
        return f2(m, n, p, s, dp);
    }
};

// Tabulation
// T.C = O(N*M)
// S.C = O(N+M)
class Solution
{
public:
    bool isMatch(string s, string p)
    {
        int n = s.size(), m = p.size();
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));

        dp[0][0] = true;

        for (int i = 1; i <= m; i++)
        {
            bool flag = true;
            for (int ii = 1; ii <= i; ii++)
            {
                if (p[ii - 1] != '*')
                {
                    flag = false;
                    break;
                }
            }
            dp[i][0] = flag;
        }

        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (p[i - 1] == s[j - 1] || p[i - 1] == '?')
                    dp[i][j] = dp[i - 1][j - 1];
                else if (p[i - 1] == '*')
                    dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
                else
                    dp[i][j] = false;
            }
        }

        return dp[m][n];
    }
};

// SPACE OPTIMIZATION
// T.C = O(N*M)
//  S.C = O(N)
class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.size(), m = p.size();
        vector<int> prev(n + 1, false), cur(n + 1, false);

        prev[0] = true;

        for (int i = 1; i <= m; i++) {
            bool flag = true;
            for (int ii = 1; ii <= i; ii++) {
                if (p[ii - 1] != '*') {
                    flag = false;
                    break;
                }
            }
            // for every row
            // You are assigning the 0th column's value
            cur[0] = flag;

            for (int j = 1; j <= n; j++) { 
                if (p[i - 1] == s[j - 1] || p[i - 1] == '?')
                    cur[j] = prev[j - 1];
                else if (p[i - 1] == '*')
                    cur[j] = prev[j] || cur[j - 1];
                else
                    cur[j] = false;
            }
            prev = cur;
        }

        return prev[n];
    }
};