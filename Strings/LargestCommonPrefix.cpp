#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string prefix = "";

        // Loop through characters of the first string
        for (int i = 0; i < strs[0].size(); i++) {
            char c = strs[0][i]; // current character to compare

            // Compare with every other string
            for (int j = 1; j < strs.size(); j++) {
                // If mismatch or end of any string → stop
                if (i >= strs[j].size() || strs[j][i] != c) {
                    return prefix;
                }
            }

            // If all matched, add this character to prefix
            prefix += c;
        }

        return prefix;
    }
};