#include<bits/stdc++.h>
using namespace std;

#define ll long long int
class Solution {
public:
    int maximumLength(vector<int>& nums) {
        map<ll,int> freq;
        int one = 0;
        for(auto it : nums){
            if(it==1){
                one++;
            }
            else{
                freq[it]++;
            }
        }

        if(one != 0 && one%2 ==0){
            one--;
        }

        int ans = one;

        for(auto it : freq){
            ll val = it.first;
            ll base = sqrt(val);

            if((base*base == val) && freq.count(base) && freq[base] > 1){
                continue;
            }

            int count = 0;

            while(freq.count(val)&& freq[val] > 1){
                count += 2;
                val = (val*1ll*val);
            }

            if(freq[val] == 1){
                count++;
            }
            else{
                count--;
            }
            ans = max(ans,count);
        }
        return ans;
    }
};


/*
You are given an array of positive integers nums.

You need to select a subset of nums which satisfies the following condition:

You can place the selected elements in a 0-indexed array such that it follows the pattern: [x, x2, x4, ..., xk/2, xk, xk/2, ..., x4, x2, x] (Note that k can be be any non-negative power of 2). For example, [2, 4, 16, 4, 2] and [3, 9, 3] follow the pattern while [2, 4, 8, 4, 2] does not.
Return the maximum number of elements in a subset that satisfies these conditions.
*/