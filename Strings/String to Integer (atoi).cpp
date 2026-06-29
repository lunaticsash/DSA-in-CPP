#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int myAtoi(string s)
    {
        int i = 0;
        int n = s.length();

        // 1. Skip leading spaces
        while (i < n && s[i] == ' ')
        {
            i++;
        }

        // 2. Check sign
        int sign = 1;

        if (i < n && (s[i] == '-' || s[i] == '+'))
        {
            if (s[i] == '-')
            {
                sign = -1;
            }
            i++;
        }

        // 3. Read digits
        long long ans = 0;

        while (i < n && s[i] >= '0' && s[i] <= '9')
        {
            int digit = s[i] - '0';

            ans = ans * 10 + digit;

            // 4. Overflow check
            if (sign == 1 && ans > INT_MAX)
            {
                return INT_MAX;
            }

            if (sign == -1 && -ans < INT_MIN)
            {
                return INT_MIN;
            }

            i++;
        }

        return sign * ans;
    }
};