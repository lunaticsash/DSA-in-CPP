#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int kvalue(vector<int>& nums,int val, int n){
        int k = 0;
        for(int i = 0; i < n; i++){
            if(nums[i] == val){
                nums[i] = INT_MAX;
                k++;
            }
        }
        return k;
    }
    int removeElement(vector<int>& nums, int val) {
        
        int n = nums.size();

        int k = kvalue(nums,val,n);

        sort(nums.begin(), nums.end());

        return n - k;
        
    }
};