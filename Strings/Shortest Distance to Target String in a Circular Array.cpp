#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        int n = words.size();
        int ans = INT_MAX;

        for (int i = 0; i < n; i++) {
            if (words[i] == target) {
                int diff = abs(i - startIndex);

                int circularDist = min(diff, n - diff);

                ans = min(ans, circularDist);
            }
        }

        return ans == INT_MAX ? -1 : ans;
    }
};