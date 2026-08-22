#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();

        int l = 0, r=0;

        while(l< n1 && r<n2){
            if(nums1[l] == nums2[r]){
                return nums1[l];
            }else if(nums1[l] > nums2[r]) {
                r++;
            }else{
                l++;
            }
        }

        return -1;
    }
};