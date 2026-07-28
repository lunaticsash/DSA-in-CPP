#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string smallestPalindrome(string s) {
        vector<int> freq(26, 0);

        for (char c : s)
            freq[c - 'a']++;

        string left = "";

        for (int i = 0; i < 26; i++)
            left += string(freq[i] / 2, 'a' + i); //string(number_of_times, character)

        char middle = '\0';

        for (int i = 0; i < 26; i++) {
            if (freq[i] % 2) {
                middle = 'a' + i;
                break;
            }
        }

        string right = left;
        reverse(right.begin(), right.end());

        string ans = left;

        if (middle != '\0')
            ans += middle;

        ans += right;

        return ans;
    }
};