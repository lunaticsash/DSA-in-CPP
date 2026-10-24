#include <bits/stdc++.h>
using namespace std;


//MEMOIZATION
class Solution
{
public:
    bool isPalindrome(string &s, int i, int j, vector<vector<int>> &dp)
    {
        if (i >= j)
            return true;

        if (dp[i][j] != -1)
            return dp[i][j];

        if (s[i] != s[j])
            return dp[i][j] = false;

        return dp[i][j] = isPalindrome(s, i + 1, j - 1, dp);
    }

    void solve(vector<vector<string>> &ans, string s, vector<string> &path,
               int index, vector<vector<int>> &dp)
    {
        if (index == s.size())
        {
            ans.push_back(path);
            return;
        }

        for (int i = index; i < s.size(); i++)
        {
            if (isPalindrome(s, index, i, dp))
            {
                path.push_back(
                    s.substr(index, i - index + 1)); // Always gives 1 less
                solve(ans, s, path, i + 1, dp);
                // Backtrack
                path.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s)
    {
        int n = s.size();
        vector<vector<string>> ans;
        vector<string> path;
        vector<vector<int>> dp(n, vector<int>(n, -1));
        solve(ans, s, path, 0, dp);
        return ans;
    }
};

//TABULATION
class Solution {
public:
    void solve(vector<vector<string>>& ans, string& s,
               vector<string>& path, int index,
               vector<vector<bool>>& dp) {

        if (index == s.size()) {
            ans.push_back(path);
            return;
        }

        for (int i = index; i < s.size(); i++) {
            if (dp[index][i]) {
                path.push_back(s.substr(index, i - index + 1));

                solve(ans, s, path, i + 1, dp);

                path.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        int n = s.size();

        vector<vector<bool>> dp(n, vector<bool>(n, false));

        for (int i = n - 1; i >= 0; i--) {
            for (int j = i; j < n; j++) {
                if (s[i] == s[j] &&
                    (j - i <= 2 || dp[i + 1][j - 1])) {
                    dp[i][j] = true;
                }
            }
        }

        vector<vector<string>> ans;
        vector<string> path;

        solve(ans, s, path, 0, dp);

        return ans;
    }
};

class Solution
{
public:
    bool isPalindrome(string s, int start, int end)
    {
        while (start < end)
        {
            if (s[start++] != s[end--])
                return false;
        }
        return true;
    }

    void solve(vector<vector<string>> &ans, string s, vector<string> &path, int index)
    {
        if (index == s.size())
        {
            ans.push_back(path);
            return;
        }

        for (int i = index; i < s.size(); i++)
        {
            if (isPalindrome(s, index, i))
            {
                path.push_back(s.substr(index, i - index + 1)); // Always gives 1 less
                solve(ans, s, path, i + 1);
                // Backtrack
                path.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s)
    {
        vector<vector<string>> ans;
        vector<string> path;

        solve(ans, s, path, 0);
        return ans;
    }
};