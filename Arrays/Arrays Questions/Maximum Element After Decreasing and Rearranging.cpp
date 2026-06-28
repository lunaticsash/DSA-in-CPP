#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        int n = arr.size();

        // freq[i] = how many numbers can be treated as value i
        vector<int> freq(n + 1, 0);

        for (int i = 0; i < n; i++) {
            // Values bigger than n are capped at n
            freq[min(arr[i], n)]++;
        }

        int ans = 0;

        for (int i = 1; i <= n; i++) {
            if (freq[i] == 0) continue;

            // We have freq[i] numbers of value i
            // ans can grow by freq[i], but cannot cross i
            ans = min(ans + freq[i], i);
        }

        return ans;
    }
};

class Solution2 {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        arr[0] = 1;
        int maxm = arr[0];
        for (int i = 1; i <= arr.size() - 1; i++) {
            if (abs(arr[i] - arr[i - 1]) <= 1) {
                maxm = arr[i];
                continue;
            } else {
                arr[i] = arr[i - 1] + 1;
            }
            maxm = arr[i];
        }

        return maxm;
    }
};

class Solution3 {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        sort(arr.begin(), arr.end());

        arr[0] = 1;

        for (int i = 1; i < arr.size(); i++) {
            if (arr[i] > arr[i - 1] + 1) {
                arr[i] = arr[i - 1] + 1;
            }
        }

        return arr[arr.size() - 1];
    }
};