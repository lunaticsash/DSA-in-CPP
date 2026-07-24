#include<bits/stdc++.h>
using namespace std;

//TC = O(n) and SC = O(1)
class Solution {
public:
    string minWindow(string s, string t) {
        int hash[256] = {0};
        int l = 0, r = 0;
        int n = s.size();
        int m = t.size();

        for (int i = 0; i < m; i++) {
            hash[t[i]]++;
        }

        int cnt = 0;
        int minLen = INT_MAX;
        int start = 0;

        while (r < n) {
            if (hash[s[r]] > 0) {
                cnt++;
            }
            hash[s[r]]--;

            while (cnt == m) {
                if (r - l + 1 < minLen) {
                    minLen = r - l + 1;
                    start = l;
                }
                hash[s[l]]++;
                if (hash[s[l]] > 0) {
                    cnt--;
                }
                l++;
            }
            r++;
        }

        if (minLen == INT_MAX) {
            return "";
        }
        return s.substr(start, minLen);
    }
};

//TC = O(n) and SC = O(1)
class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> mpp;

        for (auto c : t)
            mpp[c]++;

        int l = 0, r = 0;
        int cnt = mpp.size();
        int len = INT_MAX;
        string ans = "";

        while (r < s.size()) {

            if (mpp.find(s[r]) != mpp.end()) {
                mpp[s[r]]--;

                if (mpp[s[r]] == 0)
                    cnt--;
            }

            while (cnt == 0) {

                if (len > r - l + 1) {
                    len = r - l + 1;
                    ans = s.substr(l, len);
                }

                if (mpp.find(s[l]) != mpp.end()) {
                    mpp[s[l]]++;

                    if (mpp[s[l]] > 0)
                        cnt++;
                }

                l++;
            }

            r++;
        }

        return ans;
    }
};