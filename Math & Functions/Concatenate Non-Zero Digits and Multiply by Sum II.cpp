#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll MOD = 1e9 + 7;

class Solution {

public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int n = s.length();
        
        vector<int> nonZeroCount(n,0);
        vector<ll> numberUpTo(n,0);
        vector<ll> digitSumUpTo(n,0);
        vector<ll> pow10(n+1, 0);

        pow10[0] = 1;
        for(int i =1; i <= n ; i++){
            pow10[i] = (pow10[i-1] * 10) % MOD;
        }

        nonZeroCount[0] = (s[0] != '0') ? 1 : 0;
        for(int i = 1; i < n; i++){
            int digit = s[i] - '0';
            nonZeroCount[i] = nonZeroCount[i-1] + ((digit != 0) ? 1 : 0);
        }

        numberUpTo[0] = s[0] - '0';
        for(int i = 1; i < n ; i++){
            int digit = s[i] - '0';
            if(digit != 0) {
                numberUpTo[i] = ((numberUpTo[i-1] * 10) + digit) % MOD;
            }
            else{
                numberUpTo[i] = numberUpTo[i - 1];
            }
        }

        digitSumUpTo[0] = s[0] - '0';
        for(int i = 1; i < n ; i++){
            int digit = s[i] - '0';
            digitSumUpTo[i] = digitSumUpTo[i - 1] + digit;
        }

        int q = queries.size();
        vector<int> result(q);
        for(int i = 0; i < q; i++){
            int l = queries[i][0];
            int r = queries[i][1];

            ll sum = digitSumUpTo[r] - ((l == 0) ? 0 : digitSumUpTo[l-1]);

            ll numBefore = (l == 0) ? 0 : numberUpTo[l-1];

            int k = nonZeroCount[r] - ((l == 0) ? 0 : nonZeroCount[l-1]);

            ll x = (numberUpTo[r] - (numBefore*pow10[k] % MOD) + MOD) % MOD;

            result[i] = (int)((x*sum) % MOD);

        }

        return result ;
    }
};