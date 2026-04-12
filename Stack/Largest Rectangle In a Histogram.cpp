#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    vector<int> previousSmallerElement(vector<int>& arr) {
        int n = arr.size();
        stack<int> st;
        vector<int> ans(n);

        for (int i = 0; i < n; i++) {

            while (!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }

            if (st.empty()) ans[i] = -1;
            else ans[i] = st.top();

            st.push(i);
        }

        return ans;
    }

    vector<int> nextSmallerElement(vector<int>& arr) {
        int n = arr.size();
        stack<int> st;
        vector<int> ans(n);

        for (int i = n - 1; i >= 0; i--) {

            while (!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }

            if (st.empty()) ans[i] = n;
            else ans[i] = st.top();

            st.push(i);
        }

        return ans;
    }

    int largestRectangleArea(vector<int>& heights) {
        vector<int> nse = nextSmallerElement(heights);
        vector<int> pse = previousSmallerElement(heights);

        int n = heights.size();
        int maxi = 0;

        for(int i = 0; i < n; i++){
            int width = nse[i] - pse[i] - 1;
            int area = heights[i] * width;
            maxi = max(maxi, area);
        }

        return maxi;
    }
};