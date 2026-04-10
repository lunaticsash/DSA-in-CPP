#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPossible(vector<int>& arr, int day, int m, int k) {
        int count = 0;
        int noOfBouqets = 0;

        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] <= day)
                count++;

            else {
                noOfBouqets += (count / k);
                count = 0;
            }
        }
        noOfBouqets += (count / k);
        if (noOfBouqets >= m)
            return true;
        return false;
    }

    int minDays(vector<int>& arr, int m, int k) {
        long long val = m * 1LL * k * 1LL;
        if (val > arr.size())
            return -1;
        int mini = INT_MAX, maxi = INT_MIN;
        for (int i = 0; i < arr.size(); i++) {
            mini = min(mini, arr[i]);
            maxi = max(maxi, arr[i]);
        }

        int low = mini, high = maxi;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (isPossible(arr, mid, m, k)) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }
};