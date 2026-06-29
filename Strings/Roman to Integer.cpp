#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    int getValue(char c) {
        if (c == 'I')
            return 1;
        else if (c == 'V')
            return 5;
        else if (c == 'X')
            return 10;
        else if (c == 'L')
            return 50;
        else if (c == 'C')
            return 100;
        else if (c == 'D')
            return 500;
        else if (c == 'M')
            return 1000;
        return 0; // default, in case of invalid char
    }

public:
    int romanToInt(string s) {
        vector<int> v;
        int count = 0;

        // v =[]
        for (int i = 0; i < s.size(); i++) {
            v.push_back(getValue(s[i]));
        }

        for (int i = 0; i < v.size(); i++) {
            if ((i + 1) < v.size() && v[i] < v[i + 1]) {
                count += (v[i + 1] - v[i]);
                i++;
            } else {
                count += v[i];
            }
        }
        return count;
    }
};