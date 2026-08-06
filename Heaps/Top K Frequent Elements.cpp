#include<bits/stdc++.h>
using namespace std;

//TC = O(nlogk) + O(n) + O(klogk) = O(nlogk)
//SC = O(n) + O(k) = O(n)
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        vector<int> ans;

        // Count frequencies
        for (int x : nums) {
            freq[x]++;
        }

        // Max Heap -> {frequency, key}
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            pq;

        for (auto& [key, f] : freq) {
            pq.push({f, key});

            if (pq.size() > k)
                pq.pop(); // Remove the smallest frequency
        }

        while (!pq.empty()) {
            ans.push_back(pq.top().second);
            pq.pop();
        }

        return ans;
    }
};


//TC = O(nlogn) + O(n) + O(klogn) = O(nlogn)
//SC = O(n) + O(k) = O(n)
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        vector<int> ans;

        // Count frequencies
        for (int x : nums) {
            freq[x]++;
        }

        // Max Heap -> {frequency, key}
        priority_queue<pair<int, int>> pq;

        for (auto& [key, f] : freq) {
            pq.push({f, key});
        }

        while(!pq.empty() && k > 0){
            auto [f, key] = pq.top();

            pq.pop();

            ans.push_back(key);
            k--;
        }

        return ans;
    }
};