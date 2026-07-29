#include<bits/stdc++.h>
using namespace std;

    


//TLE
class Solution {
public:
    string smallestPalindrome(string s, int k) {
        vector<int> freq(26, 0);

        for (char c : s)
            freq[c - 'a']++;

        string left = "";
        char middle = '\0';

        for (int i = 0; i < 26; i++) {
            left += string(freq[i] / 2, 'a' + i);

            if (freq[i] % 2)
                middle = 'a' + i;
        }

        vector<string> palindromes;

        sort(left.begin(), left.end());

        do {
            string right = left;
            reverse(right.begin(), right.end());

            string curr = left;
            if (middle != '\0')
                curr += middle;
            curr += right;

            palindromes.push_back(curr);

        } while (next_permutation(left.begin(), left.end()));

        if (k > palindromes.size())
            return "";

        return palindromes[k - 1];
    }
};