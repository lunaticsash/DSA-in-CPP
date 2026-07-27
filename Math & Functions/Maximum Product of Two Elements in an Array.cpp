#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int largest = nums[0];
        int secondLargest = INT_MIN;

        int n = nums.size();

        for(int i = 1; i < n ; i++){
            if(nums[i] >= largest){
                secondLargest = largest;
                largest =nums[i];
            }else if (nums[i] > secondLargest){
                secondLargest = nums[i];
            }
        }

        return (largest - 1) * (secondLargest - 1);
    }
};

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size() - 1;
        return (nums[n] - 1) * (nums[n-1] - 1);
    }
};