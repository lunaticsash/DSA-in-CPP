#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void solve(int start, int n, int k, vector<int>& temp, vector<vector<int>>& ans) {
        // Base Case: Jab temp ka size 'k' ke barabar ho jaye
        if (temp.size() == k) {
            ans.push_back(temp);
            return;
        }

        // Loop: current number 'start' se le kar 'n' tak explore karo
        for (int i = start; i <= n; i++) {
            // Step 1: Element choose karo
            temp.push_back(i);
            
            // Step 2: Agle numbers ke liye recurse karo (i + 1 se shuru karenge)
            solve(i + 1, n, k, temp, ans);
            
            // Step 3: Backtrack karo (wapas purani state par aao)
            temp.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> temp;
        
        // 1-based indexing hai ( numbers range: [1, n] )
        solve(1, n, k, temp, ans);
        
        return ans;
    }
};