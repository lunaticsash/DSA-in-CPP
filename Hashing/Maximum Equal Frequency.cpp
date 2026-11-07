#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxEqualFreq(vector<int>& nums) {
        unordered_map<int,int> freq;
        unordered_map<int,int> ff;

        int ans = 0;

        for(int i = 0; i < nums.size(); i++) {

            int x = nums[i];

            int oldFreq = freq[x];

            if(oldFreq > 0) {
                ff[oldFreq]--;
            }

            freq[x]++;

            int newFreq = freq[x];

            ff[newFreq]++;

            int maxFreq = 0;

            for(auto p : ff) {
                if(p.second > 0) {
                    maxFreq = max(maxFreq, p.first);
                }
            }

            int len = i + 1;

            // Case 1
            if(maxFreq == 1) {
                ans = len;
            }

            // Case 2
            else if(ff[1] == 1 &&
                    ff[1] + ff[maxFreq] * maxFreq == len) {
                ans = len;
            }

            // Case 3
            else if(ff[maxFreq] == 1 &&
                    (maxFreq - 1) * (ff[maxFreq-1] + 1) + 1 == len) {
                ans = len;
            }
        }

        return ans;
    }
};