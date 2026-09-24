#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int smallestIndex(vector<int>& arr) {

        int n = arr.size();
        for (int i = 0; i < n; i++) {
            int sum = 0;
            while (arr[i] > 0) {
                int digit = arr[i] % 10;
                arr[i] = arr[i] / 10;
                sum += digit;
            }
            if(sum == i) return i;
        }

        return -1;
    }
};