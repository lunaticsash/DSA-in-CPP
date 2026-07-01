#include <bits/stdc++.h>
using namespace std;

class Solution
{

    // Recursive Function to find all
    // substrings of a string
    void subString(string &s, int n, int index,
                   string &cur, vector<string> &res)
    {

        // if we have reached the
        // end of the string
        if (index == n)
        {
            return;
        }

        // add the character s[index]
        // to the current string
        cur.push_back(s[index]);

        // add the current string in result
        res.push_back(cur);

        // move to next index
        subString(s, n, index + 1, cur, res);

        // remove the current character
        // from the current string
        cur.pop_back();

        // if current string is empty
        // skip the current index to
        // start the new substring
        if (cur.empty())
        {
            subString(s, n, index + 1, cur, res);
        }
    }

    // Function to find all substrings
    vector<string> findSubstrings(string s)
    {

        // to store all substrings
        vector<string> res;

        // to store current string
        string cur = "";
        subString(s, s.length(), 0, cur, res);
        return res;
    }

    int main()
    {
        string s = "abc";
        vector<string> res = findSubstrings(s);
        for (auto i : res)
        {
            cout << i << " ";
        }
        return 0;
    }
};

class Solution
{
    // Function to find all substrings
    vector<string> findSubstrings(string &s)
    {

        // to store all substrings
        vector<string> res;

        for (int i = 0; i < s.length(); i++)
        {
            for (int j = i; j < s.length(); j++)
            {

                // substr function takes starting index
                // and length as parameters
                res.push_back(s.substr(i, j - i + 1));
            }
        }

        return res;
    }

    int main()
    {
        string s = "abc";
        vector<string> res = findSubstrings(s);
        for (auto i : res)
        {
            cout << i << " ";
        }
        return 0;
    }
};