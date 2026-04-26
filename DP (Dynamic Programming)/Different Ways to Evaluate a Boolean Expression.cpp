#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    long long f(int i, int j,int isTrue, string &exp, vector<vector<vector<long long>>> &dp){
        if(i >j) return 0;
        if(i == j ) {
            if(isTrue) return exp[i] == 'T';
            else return exp [i] == 'F';
        }

        if(dp[i][j][isTrue] != -1) return dp[i][j][isTrue];
        long long ways = 0;

        for(int ind = i+1; ind<= j-1; ind += 2){
            long long lt = f(i, ind - 1, 1, exp, dp);
            long long lf = f(i, ind - 1, 0, exp, dp);
            long long rt = f(ind + 1, j, 1, exp, dp);
            long long rf = f(ind + 1, j, 0, exp, dp);

            if(exp[ind] == '&'){
                if(isTrue) ways = ways+ (rt * lt);
                else ways =  ways + (rt*lf) + (rf*lt) + (rf*lf);
            }

            else if(exp[ind] == '|'){
                if(isTrue){
                    ways = ways + (lt*rt) +(lt*rf) + (lf*rt);
                }
                else ways = ways + + (rf*lf);
            }

            else{// "^"
                if(isTrue) ways = ways + (lt*rf) + lf*rt; 
                else ways = ways + (lt*rt) + (lf*rf);
            }
        } 
        return dp[i][j][isTrue] = ways ;
    }


    int countstr(string expression) {
        int n = expression.size();

        vector<vector<vector<long long>>> dp(n, vector<vector<long long>>(n, vector<long long>(2, -1)));
        return f(0, n-1, 1, expression, dp);
    }
};