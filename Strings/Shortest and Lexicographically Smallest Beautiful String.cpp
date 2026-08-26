#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int minLen = INT_MAX;
        int l = 0, r = 0;

        int countOne = 0;

        int n = s.length();

        string ans = "";

        while (r < n) {

            // Add s[r] to window
            if (s[r] == '1') {
                countOne++;
            }

            // Window has k ones
            while (countOne == k) {

                int currLen = r - l + 1;
                if (currLen < minLen) {
                    minLen = currLen;
                    ans = s.substr(l, currLen);
                } else if (currLen == minLen) {
                    string temp = s.substr(l, currLen);

                    if (ans > temp)
                        ans = temp;
                }

                // Remove s[l]
                if (s[l] == '1') { 
                    countOne--;
                }

                l++;
            }

            // Move right
            r++;
        }

        return ans;
    }
};