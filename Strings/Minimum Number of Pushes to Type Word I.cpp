#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumPushes(string word) {
        int n = word.size();
        return min(n, 8)
             + max(0, min(n - 8, 8)) * 2
             + max(0, min(n - 16, 8)) * 3
             + max(0, n - 24) * 4;
    }
};

class Solution {
public:
    int minimumPushes(string word) {
        int n = word.length();
        int take = INT_MAX;
        int cost = 1;
        int ans = 0;
        while (n > 0) {
            take = min(8, n);
            ans += take * cost;
            cost++;
            n -= take;
        }
        return ans;
    }
};