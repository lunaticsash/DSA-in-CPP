#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool equalFrequency(string w) {
        int f[26] = {0};
        for(char c : w) 
            f[c - 'a']++;
        
        for(int i = 0; i < 26; i++) {
            if(!f[i]) continue;
            
            f[i]--;
            unordered_set<int> st;
            for(int x : f) 
                if(x) st.insert(x);
            
            if(st.size() == 1) return true;
            
            f[i]++;
        }
        
        return false;
    }
};