#include <iostream>
#include <string>
using namespace std;

class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        int freq[26];
        if (s.length() != t.length())
            return false;
        for (auto ch : s)
        {
            freq[ch - 'a']++;
        }

        for (auto ch : t)
        {
            if (freq[ch - 'a']-- <= 0)
                return false;
        }

        return true;
    }
};