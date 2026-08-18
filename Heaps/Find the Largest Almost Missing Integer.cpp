#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int n = nums.size();

        for (int i = 0; i <= n - k; i++) {
            unordered_set<int> st;

            for (int j = i; j < i + k; j++) {
                st.insert(nums[j]);
            }

            // Count this window only once for each number
            for (int x : st) {
                mp[x]++;
            }
        }

        int ans = -1;

        for (auto &[num, freq] : mp) {
            if (freq == 1) {
                ans = max(ans, num);
            }
        }

        return ans;
    }
};