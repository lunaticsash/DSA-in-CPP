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







