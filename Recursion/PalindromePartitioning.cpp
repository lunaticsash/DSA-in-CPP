#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s, int start, int end){
        while(start < end){
            if(s[start++] != s[end--]) return false; 
        }
        return true;
    }

    void solve(vector<vector<string>> &ans, string s, vector<string>& path, int index){
        if(index == s.size()) {
            ans.push_back(path);
            return;
        }

        for(int i = index; i < s.size(); i++){
            if(isPalindrome(s, index, i)){
                path.push_back(s.substr(index, i - index + 1)); //Always gives 1 less
                solve(ans, s, path, i+1);
                //Backtrack
                path.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> path;

        solve(ans, s, path, 0);
        return ans;
    }
};