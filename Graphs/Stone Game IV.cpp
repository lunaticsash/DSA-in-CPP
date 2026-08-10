#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    bool winnerSquareGame(int n) {
        vector<int> dp(n+1, 0);

        // "Can I make a move that puts my opponent in a losing state?"
        for(int i = 1; i <= n; i++){
            for(int j = 1; j*j <= i ; j++){

                // If dp[i - j*j] == false, it means after I remove j*j stones from i, my opponent gets a losing position. Therefore, i is a winning position, so we set dp[i] = true.
                if(dp[i - j*j] == false){
                    dp[i] = true;
                    break;
                }
            }
        }

        return dp[n];
    }
};