#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();

        vector<int> freq(51, 0);

        for (int x : nums) {
            freq[x]++;
        }
        if (k == n) {
            return *max_element(nums.begin(), nums.end());
        }
        if (k == 1) {
            int ans = -1;

            for (int x : nums) {
                if (freq[x] == 1) {
                    ans = max(ans, x);
                }
            }

            return ans;
        }

        int ans = -1;

        if (freq[nums[0]] == 1) {
            ans = max(ans, nums[0]);
        }

        if (freq[nums[n - 1]] == 1) {
            ans = max(ans, nums[n - 1]);
        }

        return ans;
    }
};

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