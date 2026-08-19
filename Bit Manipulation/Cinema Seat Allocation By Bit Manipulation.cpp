#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {

        long long ans = 2LL * n;

        unordered_map<int, int> mp;
        mp.reserve(reservedSeats.size() * 2);

        for (auto &seat : reservedSeats) {
            int row = seat[0];
            int s = seat[1];

            if (s == 1 || s == 10)
                continue;

            mp[row] |= (1 << s);
        }

        int left   = (1 << 2) | (1 << 3) | (1 << 4) | (1 << 5);
        int middle = (1 << 4) | (1 << 5) | (1 << 6) | (1 << 7);
        int right  = (1 << 6) | (1 << 7) | (1 << 8) | (1 << 9);

        for (auto &[row, mask] : mp) {

            bool L = (mask & left) == 0;
            bool M = (mask & middle) == 0;
            bool R = (mask & right) == 0;

            if (L && R)
                continue;

            if (L || M || R)
                ans--;
            else
                ans -= 2;
        }

        return ans;
    }
};