#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> createGrid(int m, int n) {
        string first(n, '.');
        string all(n, '#');
        all[n - 1] = '.';

        vector<string> ans(m, all);
        ans[0] = first;

        return ans;
    }
};