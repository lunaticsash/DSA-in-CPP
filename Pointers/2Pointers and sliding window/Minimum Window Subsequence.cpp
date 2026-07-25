#include<bits/stdc++.h>
using namespace std;

// match-forward/verify-backward

//TC = O(m*n);
//SC = O(1);
class Solution {
public:
    string minWindow(string s1, string s2) {
        int i = 0, j = 0;
        int n = s1.size();
        int m = s2.size();

        int startIndex = -1, minLen = INT_MAX;

        while (i < n) {
            if (s1[i] == s2[j]) {
                j++;
                if (j == m) {                 // found a full match ending at i
                    int end = i;
                    j--;                       // step back into s2
                    while (j >= 0) {
                        if (s1[i] == s2[j]) j--;
                        i--;                   // walk s1 backward regardless
                    }
                    i++;                       // i now points to the true start
                    if (end - i + 1 < minLen) {
                        minLen = end - i + 1;
                        startIndex = i;
                    }
                    j = 0;                     // reset for next search
                }
            }
            i++;
        }
        return startIndex == -1 ? "" : s1.substr(startIndex, minLen);
    }
};


// The core mental shift from Minimum Window Substring code: Minimum Window Substring is a set-coverage problem (frequencies), while Minimum Window Subsequence is a sequence-alignment problem (order matters), so it needs match-forward/verify-backward instead of a single counting pass.