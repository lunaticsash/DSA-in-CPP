#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char, string> mp1;
        unordered_map<string, char> mp2;
        int j = 0, l = 0;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == ' '){
                string cur = s.substr(l, i-l);
                l = i+1;
                if(j >= pattern.size())return false;
                if(mp1.count(pattern[j]) && (mp1[pattern[j]] != cur))return false;
                mp1[pattern[j]] = cur;
                if(mp2.count(cur) && (mp2[cur] != pattern[j]))return false;
                mp2[cur] = pattern[j];
                j++;
            }
        }
        string cur = s.substr(l, s.size()-l);
        if(j >= pattern.size())return false;
        if(mp1.count(pattern[j]) && (mp1[pattern[j]] != cur))return false;
        if(mp2.count(cur) && (mp2[cur] != pattern[j]))return false;
        j++;
        if(j != pattern.size())return false;
        return true;
    }
};