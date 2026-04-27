#include <bits/stdc++.h>
using namespace std;

// RECURSIVE
// T.C => EXPONENTIAL
// S.C => O(N)
class Solution
{
public:
    bool isPalindrome(int i, int j, string &s)
    {
        while (i < j)
        {
            if (s[i] != s[j])
            {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }

    int f(int i, int n, string &s)
    {
        if (i == n)
            return 0;
        int minCost = INT_MAX;

        // i....j
        for (int j = i; j < n; j++)
        {
            if (isPalindrome(i, j, s))
            {
                int cost = 1 + f(j + 1, n, s);
                minCost = min(minCost, cost);
            }
        }
        return minCost;
    }

    int minCut(string s)
    {
        int n = s.size();

        return f(0, n, s) - 1;
    }
};

// MEMOIZATION
class Solution
{
public:
    bool isPalindrome(int i, int j, string &s)
    {
        while (i < j)
        {
            if (s[i] != s[j])
            {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }

    int f1(int i, int n, string &s, vector<int> &dp)
    {
        if (i == n)
            return 0;
        int minCost = INT_MAX;

        if (dp[i] != -1)
            return dp[i];
        // i....j
        for (int j = i; j < n; j++)
        {
            if (isPalindrome(i, j, s))
            {
                int cost = 1 + f1(j + 1, n, s, dp);
                minCost = min(minCost, cost);
            }
        }
        return dp[i] = minCost;
    }

    int minCut(string s)
    {
        int n = s.size();
        vector<int> dp(n, -1);
        return f1(0, n, s, dp) - 1;
    }
};

// TABULATION
class Solution
{
public:
    bool isPalindrome(int i, int j, string &s)
    {
        while (i < j)
        {
            if (s[i] != s[j])
            {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }

    int minCut(string s)
    {
        int n = s.size();
        vector<int> dp(n + 1, 0);
        for (int i = n - 1; i >= 0; i--)
        {
            int minCost = INT_MAX;

            // i....j
            for (int j = i; j < n; j++)
            {
                if (isPalindrome(i, j, s))
                {
                    int cost = 1 + dp[j + 1];
                    minCost = min(minCost, cost);
                }
            }
            dp[i] = minCost;
        }
        return dp[0] - 1;
    }
};

//MORE OPTIMIZED
class Solution {
public:
    int minCut(string s) {
        int n = s.size();
        vector<int> dp(n, 0);
        vector<vector<bool>> pal(n, vector<bool>(n, false));

        for (int i = 0; i < n; i++) {
            dp[i] = i;
            for (int j = 0; j <= i; j++) {
                if (s[i] == s[j] && (i - j <= 2 || pal[j + 1][i - 1])) {
                    pal[j][i] = true;
                    dp[i] = (j == 0) ? 0 : min(dp[i], dp[j - 1] + 1);
                }
            }
        }
        return dp[n - 1];
    }
};