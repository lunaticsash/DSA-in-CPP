#include <bits/stdc++.h>
using namespace std;

#include <sstream>

class Solution {
public:
    int lengthOfLastWord(string s) {
        stringstream ss(s);
        string word;
        vector<string>ans;
        
        while(ss >> word){
            ans.push_back(word);
        }

        int n = ans.size();
        string ok = ans[n-1];
        int k = ok.length();

        return k;

    }
};