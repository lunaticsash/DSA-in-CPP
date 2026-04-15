#include<bits/stdc++.h>
using namespace std;

//TC => O(N)
//SC => O(1)
class Solution {
public:
    int characterReplacement(string s, int k) {
        int l = 0, r = 0;
        int maxf = 0;
        int maxlen = 0;
        int hash[26] = {0};

        while (r < s.length()) {

            // Expand
            hash[s[r] - 'A']++;
            maxf = max(maxf, hash[s[r] - 'A']);

            // Shrink if invalid
            while ((r - l + 1) - maxf > k) {
                hash[s[l] - 'A']--;
                l++;
            }

            // Update answer
            maxlen = max(maxlen, r - l + 1);

            r++;
        }

        return maxlen;
    }
};