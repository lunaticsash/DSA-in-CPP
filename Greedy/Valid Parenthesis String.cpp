#include<bits/stdc++.h>
using namespace std;



class Solution {
public:

    bool isPossible(string &s, int n, int ind, int cnt, vector<vector<int>> &dp){
        if(cnt < 0) return false;
        if(ind == n) return (cnt == 0);

        if(dp[ind][cnt] != -1) return dp[ind][cnt];

        if(s[ind] == '(') 
            return dp[ind][cnt] = isPossible(s, n, ind + 1, cnt + 1, dp);

        if(s[ind] == ')') 
            return dp[ind][cnt] = isPossible(s, n, ind + 1, cnt - 1, dp);

        // '*' case
        return dp[ind][cnt] =
            isPossible(s, n, ind + 1, cnt + 1, dp) ||  // treat as '('
            isPossible(s, n, ind + 1, cnt - 1, dp) ||  // treat as ')'
            isPossible(s, n, ind + 1, cnt, dp);        // treat as empty
    }

    bool checkValidString(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n+1, -1));
        return isPossible(s, n, 0, 0, dp);
    }
};

class Solution {
public:

    bool isPossible(string s, int n, int ind, int cnt){
        if(cnt < 0) return false;
        if(ind == n) return (cnt ==0);

        if(s[ind] == '(') return isPossible(s, n, ind +1, cnt+1);
        if(s[ind] == ')') return isPossible(s, n, ind +1, cnt-1);
        //*
        return isPossible(s, n, ind +1, cnt+1) || isPossible(s, n, ind +1, cnt-1) ||isPossible(s, n, ind +1, cnt);
    }

    bool checkValidString(string s) {
        int n = s.size();
        return isPossible(s,n, 0,  0);
    }
};