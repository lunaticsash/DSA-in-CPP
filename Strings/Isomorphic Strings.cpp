#include <bits/stdc++.h>
using namespace std;

// Time Complexity: O(n)
// Space Complexity: O(1)
class Solution
{
public:
    bool isIsomorphic(string s, string t)
    {
        unordered_map<char, int> cS;
        unordered_map<char, int> cT;
        for (int i = 0; i < s.size(); i++)
        {
            char chs = s[i];
            if (cS.find(chs) == cS.end())
            {
                cS[chs] = i;
            }
            char cht = t[i];
            if (cT.find(cht) == cT.end())
            {
                cT[cht] = i;
            }
            if (cT[cht] != cS[chs])
            {
                return false;
            }
        }
        return true;
    }
};

class Solution2
{
    bool isIsomorphic(string s, string t)
    {
        map<char, char> mp1; // s -> t
        map<char, char> mp2; // t -> s

        for (int i = 0; i < s.length(); i++)
        {
            char ch1 = s[i];
            char ch2 = t[i];

            if (mp1.count(ch1) && mp1[ch1] != ch2)
            {
                return false;
            }

            if (mp2.count(ch2) && mp2[ch2] != ch1)
            {
                return false;
            }

            mp1[ch1] = ch2;
            mp2[ch2] = ch1;
        }

        return true;
    }
};