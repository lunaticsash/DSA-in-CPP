#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int longestWPI(vector<int>& hours) {
        int n = hours.size();
        vector<int> prefix(n + 1, 0);

        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] +
                            (hours[i] > 8 ? 1 : -1);
        }

        stack<int> st;

        for (int i = 0; i <= n; i++) {
            if (st.empty() || prefix[i] < prefix[st.top()]) {
                st.push(i);
            }
        }

        int ans = 0;

        for (int j = n; j >= 0; j--) {
            while (!st.empty() && st.top() >= j) {
                st.pop();
            }

            while (!st.empty() && prefix[j] > prefix[st.top()]) {
                ans = max(ans, j - st.top());
                st.pop();
            }
        }

        return ans;
    }
};

class Solution {
public:
    int longestWPI(vector<int>& hours) {
        int n = hours.size();
        int sum = 0, ans = 0;
        unordered_map<int, int> mp;

        for (int i = 0; i < n; i++) {
            if (hours[i] > 8)
                sum += 1;
            else
                sum -= 1;

            if (sum > 0)
                ans = i + 1;
            else if (mp.find(sum - 1) != mp.end())
                ans = max(ans, i - mp[sum - 1]);

            if (mp.find(sum) == mp.end())
                mp[sum] = i;
        }

        return ans;
    }
};  

class Solution {
public:
    int longestWPI(vector<int>& hours) {
        int n = hours.size();

        for(int i = 0; i < n; i++){
            if(hours[i] > 8)
                hours[i] = 1;
            else 
                hours[i] = -1;
        }

        int ans = INT_MIN;
        for(int i = 0; i <n; i++){
            int total = 0;
            for(int j = i ; j < n ; j++){
                total += hours[j];
                if(total > 0)
                    ans = max(ans, j-i+1);
            }
        }

        if(ans > 0) return ans;
        else return 0;
    }
};