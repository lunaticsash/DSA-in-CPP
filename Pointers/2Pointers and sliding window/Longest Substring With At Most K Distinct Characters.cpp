#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int kDistinctChar(string& s, int k) {
        int maxLen = 0;
        int l = 0, r = 0;
        unordered_map<char, int> mpp;

        while(r < s.size()) {
            mpp[s[r]]++;
            if(mpp.size() > k) {
                mpp[s[l]]--;
                if(mpp[s[l]] == 0) mpp.erase(s[l]);
                l++;
            }
            if(mpp.size() <= k) {
                maxLen = max(maxLen, r - l + 1);
            }
            r++;
            
        }
        return maxLen;
    }
};