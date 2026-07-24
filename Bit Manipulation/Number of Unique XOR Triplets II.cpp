#include <bits/stdc++.h>
using namespace std;

class Solution
{
    int uniqueXorTriplets(vector<int> &nums)
    {

        int n = nums.size();
        // Store all pairs XORS
        int maxEl = *max_element(nums.begin(), nums.end());

        int T = 1;
        while(T<= maxEl){
            T<<=1; //T = T*2
        }

        vector<bool>s1(T, false); //XOR PAIR VALUES SET TO TRUE
        vector<bool> s2(T, false); // XOR TRIPLE VALUES SET TO TRUE

        for(int i = 0 ; i < n ; i++){
            for(int j = i ; j < n ; j++){
                s1[nums[i] ^ nums[j]] = true;
            }
        }

        for(int i = 0; i < T ; i++){
            if(s1[i] == true){
                for(int &num : nums){
                    s2[i^ num] = true;
                }
            }
        }

        int count = 0; // unique xor count
        for(int i = 0; i < T ; i++){
            if(s2[i] == true){
                count++;
            }
        }
        return count;

    }
};

class Solution
{
    int uniqueXorTriplets(vector<int> &nums)
    {

        int n = nums.size();
        // Store all pairs XORS
        unordered_set<int> s1;

        for (int i = 0; i < n; i++)
        {
            for (int j = i; j < n; j++)
            {
                s1.insert(nums[i] ^ nums[j]);
            }
        }

        // Find all triplets xors(unique) in the set

        unordered_set<int> s2;
        for (int pairXor : s1)
        {
            for (int &num : nums)
            {
                s2.insert(pairXor ^ num);
            }
        }

        return s2.size();
    }
};