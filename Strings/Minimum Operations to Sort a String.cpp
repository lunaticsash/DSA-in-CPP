#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minOperations(string s)
    {
        int n = s.size();

        if(is_sorted(s.begin(),s.end())) return 0;

        if( n==2) return -1;

        char mn = *min_element(s.begin(),s.end());
        char mx = *max_element(s.begin(),s.end());

        if(s[0] == mn && s[n-1] == mx && count(s.begin(),s.end(),mn) == 1 && count(s.begin(),s.end(),mx) == 1) return 3;

        if (s[0] == mn || s[n - 1] == mx)
            return 1;

        return 2;
    }
};