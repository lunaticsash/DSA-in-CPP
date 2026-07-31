#include<bits/stdc++.h>
using namespace std;

//priority_queue
class Solution {
public:
    int minimumPushes(string word) {
        vector<int> freq(26, 0);

        for (char ch : word)
            freq[ch - 'a']++;

        sort(freq.begin(), freq.end(), greater<int>());

        priority_queue<int> pq;

        for (int x : freq) {
            if (x > 0)
                pq.push(x);
        }

        int ans = 0;
        int index = 0;

        while (!pq.empty()) {
            ans += pq.top() * (index / 8 + 1);
            pq.pop();
            index++;
        }

        return ans;
    }
};

//Sort
class Solution {
public:
    int minimumPushes(string word) {
        vector<int> freq(26, 0);

        for (char ch : word)
            freq[ch - 'a']++;

        sort(freq.begin(), freq.end(), greater<int>());

        int ans = 0;

        for (int i = 0; i < 26; i++) {
            ans += freq[i] * (i / 8 + 1);
        }
        return ans;
    }
};