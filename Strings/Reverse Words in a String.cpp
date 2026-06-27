#include <bits/stdc++.h>
using namespace std;

// TC = O(N)
// SC = O(N)
class Solution
{
public:
    string reverseWords(string s)
    {
        vector<string> words;
        string s1 = "";

        for (auto ch : s)
        {
            if (ch == ' ')
            {
                if (s1 != "")
                {
                    words.push_back(s1);
                    s1 = "";
                }
            }
            else
            {
                s1.push_back(ch);
            }
        }

        if (s1 != "")
        {
            words.push_back(s1);
        }

        reverse(words.begin(), words.end());

        string ans = "";

        for (int i = 0; i < words.size(); i++)
        {
            ans += words[i];

            if (i != words.size() - 1)
            {
                ans += ' ';
            }
        }

        return ans;
    }
};







/*
IN-PLACE SOLTUION WITH SC = O(1)
class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();

        // Step 1: reverse whole string
        reverse(s.begin(), s.end());

        int i = 0;
        int j = 0;

        // Step 2: remove extra spaces and store words in same string
        while (i < n) {
            // skip spaces
            while (i < n && s[i] == ' ') {
                i++;
            }

            // if this is not the first word, add one space before next word
            if (j != 0 && i < n) {
                s[j++] = ' ';
            }

            // copy current word
            while (i < n && s[i] != ' ') {
                s[j++] = s[i++];
            }
        }

        // remove leftover extra characters
        s.resize(j);

        // Step 3: reverse every word individually
        int start = 0;

        for (int end = 0; end <= s.size(); end++) {
            if (end == s.size() || s[end] == ' ') {
                reverse(s.begin() + start, s.begin() + end);
                start = end + 1;
            }
        }

        return s;
    }
};*/