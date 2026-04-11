#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void solve(int open, int close, int n, string temp, vector<string>& ans) {
        // Base case
        if (temp.length() == 2 * n) {
            ans.push_back(temp);
            return;
        }

        // Add '('
        if (open < n) {
            solve(open + 1, close, n, temp + "(", ans);
        }

        // Add ')'
        if (close < open) {
            solve(open, close + 1, n, temp + ")", ans);
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        solve(0, 0, n, "", ans);
        return ans;
    }
};