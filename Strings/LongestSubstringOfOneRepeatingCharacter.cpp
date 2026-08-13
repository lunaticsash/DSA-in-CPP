#include <bits/stdc++.h>
using namespace std;\

//BruteForce
//TC = O(n*m) where n = length of string and m = number of queries
//SC = O(m)
class Solution {
public:

    int longestRepeatingSubstring(string s, int n){
        int ans = 0; int cnt = 1;

        if(n == 1) return 1;

        for(int i = 1; i < n ; i++){
            if(s[i] == s[i-1]) 
                cnt++;
            else
                cnt = 1;

            ans = max(ans,cnt);
        }
        return ans;
    }

    vector<int> longestRepeating(string s, string queryCharacters, vector<int>& queryIndices) {
        vector<int> ans;

        int n = s.size();
        int m =queryIndices.size();

        for(int i = 0; i < m ; i++){
            s[queryIndices[i]] = queryCharacters[i];
            ans.push_back(longestRepeatingSubstring(s,n));
        }

        return ans;
    }
};