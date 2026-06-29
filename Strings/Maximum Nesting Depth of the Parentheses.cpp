#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int maxDepth(string s) {
        int ans = 0;
        int count = 0;
        for(auto ch : s){
            if(ch == '('){
                count++;
                ans = max(count, ans);
            }else if(ch == ')'){
                count--;
                ans = max(count, ans);
            }
        }
        return ans;
    }
};