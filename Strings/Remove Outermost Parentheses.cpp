#include <bits/stdc++.h>
using namespace std;

// INPLACE SOLUTION
// TC = O(N)
// SC= O(1)
class Solution
{
public:
    string removeOuterParentheses(string s)
    {
        int count = 0;
        int j = 0; // position where we write valid brackets

        for (char ch : s)
        {
            if (ch == '(')
            {
                if (count > 0)
                {
                    s[j++] = ch; // keep only inner '('
                }
                count++;
            }
            else
            {
                count--;
                if (count > 0)
                {
                    s[j++] = ch; // keep only inner ')'
                }
            }
        }

        s.resize(j); // remove extra leftover characters
        return s;
    }
};