#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int calPoints(vector<string>& a) {
        vector<int> v;
        for (string s : a) {
            if (s == "+") {
                int n = v.size();
                v.push_back(v[n-1] + v[n-2]);
            } else if (s == "D") {
                v.push_back(v.back()*2);
            } else if (s == "C") {
                v.pop_back();
            } else {
                v.push_back(stoi(s));
            }
        }
        int ans = 0;
        for (int i : v) ans += i;
        return ans;
    }
};