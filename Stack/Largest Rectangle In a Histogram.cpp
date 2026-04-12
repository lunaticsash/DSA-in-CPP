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

class Solution {
public:
    int largestRectangleArea(vector<int>& arr) {
        stack<int> st;
        int n = arr.size();
        int maxArea = 0;

        for(int i = 0; i < n; i++){
            while(!st.empty() && arr[st.top()] >= arr[i]){
                int element = st.top();
                st.pop();

                int nse = i;
                int pse = st.empty() ? -1 : st.top();

                int width = nse - pse - 1;
                maxArea = max(maxArea, arr[element] * width);
            }
            st.push(i);
        }

        // Remaining elements
        while(!st.empty()){
            int element = st.top();
            st.pop();

            int nse = n;
            int pse = st.empty() ? -1 : st.top();

            int width = nse - pse - 1;
            maxArea = max(maxArea, arr[element] * width);
        }

        return maxArea;
    }
};