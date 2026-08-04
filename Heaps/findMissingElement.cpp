#include<bits/stdc++.h>
using namespace std;

//TC = O(nlogn) + O(n) + O(n) = O(nlogn)
//SC = O(n) + O(n) = O(n)
class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int minVal = nums.front();
        int maxVal = nums.back();

        unordered_set<int> st(nums.begin(), nums.end());

        vector<int> ans;

        for (int x = minVal; x <= maxVal; x++) {
            if (!st.count(x))
                ans.push_back(x);
        }

        return ans;
    }
};

//TC = O(nlogn) + O(n) + O(n) = O(nlogn)
//SC = O(n) + O(n) = O(n)
class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int minel = nums.front();
        int maxel = nums.back();

        vector<int> ans;

        vector<int> freq(maxel+1,0);
        for(auto it: nums){
            freq[it]++;
        }

        for(int i = minel ; i <= maxel; i++){
            if(freq[i] == 0)
                ans.push_back(i);
        }

        return ans;
    }
};