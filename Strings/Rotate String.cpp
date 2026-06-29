#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution
{
public:
    bool rotateString(string s, string goal)
    {
        if (s.length() != goal.length())
        {
            return false;
        }
        string s3 = s + s;
        for (int i = 0; i < s.length(); i++)
        {
            if (goal == s3.substr(i, s.length()))
            {
                return true;
            }
        }
        return false;
    }
};

class Solution2
{
public:
    bool rotateString(string s, string goal)
    {
        int n = s.size();

        if (n != goal.size())
            return false;

        for (int shift = 0; shift < n; shift++)
        {
            bool match = true;

            for (int i = 0; i < n; i++)
            {
                if (s[(i + shift) % n] != goal[i])
                {
                    match = false;
                    break;
                }
            }

            if (match)
                return true;
        }

        return false;
    }
};

class Solution3
{
public:
    void leftRotateByOne(string &s)
    {
        reverse(s.begin(), s.begin() + 1);
        reverse(s.begin() + 1, s.end());
        reverse(s.begin(), s.end());
    }

    bool rotateString(string s, string goal)
    {
        if (s.size() != goal.size())
            return false;

        int n = s.size();

        for (int i = 0; i < n; i++)
        {
            if (s == goal)
                return true;
            leftRotateByOne(s);
        }

        return false;
    }
};

class Solution4
{
public:
    bool rotateString(string s, string goal)
    {
        if (s.size() != goal.size())
            return false;

        int n = s.size();

        for (int i = 0; i < n; i++)
        {
            if (s == goal)
                return true;

            char first = s[0];
            s.erase(s.begin());
            s.push_back(first);
        }

        return false;
    }
};