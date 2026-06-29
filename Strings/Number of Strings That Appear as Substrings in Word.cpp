#include<bits/stdc++.h>
using namespace std;

//TC = O(n*m) where n = number of patterns and m = length of word
//SC = O(1)
class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int count = 0;

        for (auto pattern : patterns) {
            if (word.find(pattern) < word.length()) {
                count++;
            }
        }

        return count;
    }
};


//WITHOUT FIND FUNCTION
class Solution2 {
public:
    bool isSubstring(string pattern, string word) {
        int n = word.length();
        int m = pattern.length();

        if (m > n) return false;

        for (int i = 0; i <= n - m; i++) {
            bool matched = true;

            for (int j = 0; j < m; j++) {
                if (word[i + j] != pattern[j]) {
                    matched = false;
                    break;
                }
            }

            if (matched == true) {
                return true;
            }
        }

        return false;
    }

    int numOfStrings(vector<string>& patterns, string word) {
        int count = 0;

        for (int i = 0; i < patterns.size(); i++) {
            if (isSubstring(patterns[i], word)) {
                count++;
            }
        }

        return count;
    }
};