//Instead of generating all subarrays, it focuses on how many subarrays have a particular element as their minimum. This reduces the problem to counting the number of subarrays where each element is the smallest, and then summing these contributions.
//explains how to handle edge cases, particularly when there are duplicate elements, by adjusting the comparison conditions in the previous smaller element function to use “smaller or equal” instead of just “smaller.” 
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findNSE(vector<int>& arr) {
        int n = arr.size();
        vector<int> nse(n);
        stack<int> st;
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }
            nse[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        return nse;
    }

    vector<int> findPSEE(vector<int>& arr) {
        int n = arr.size();
        vector<int> psee(n);
        stack<int> st;
        for (int i = 0; i <= n - 1; i++) {
            while (!st.empty() && arr[st.top()] > arr[i]) {
                st.pop();
            }
            psee[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return psee;
    }

    int sumSubarrayMins(vector<int>& arr) {
        vector<int> nse = findNSE(arr);
        vector<int> pse = findPSEE(arr);
        int n = arr.size();

        int total = 0;
        int mod = (int)(1e9 + 7);

        for (int i = 0; i <= n - 1; i++) {
            int left = i - pse[i];
            int right = nse[i] - i;

            total =(total + ((1LL * left * right % mod) * arr[i]) % mod) % mod;
        }
        return (int)total;
    }
};