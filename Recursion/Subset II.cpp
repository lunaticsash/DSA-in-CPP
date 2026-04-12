// Given an integer array nums that may contain duplicates, return all possible subsets (the power set).

// The solution set must not contain duplicate subsets. Return the solution in any order.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void f(int ind, vector<int> &ds, vector<vector<int>> &ans,
           vector<int> &nums)
    {
        // Base case
        if (ind == nums.size())
        {
            ans.push_back(ds);
            return;
        }

        // Take
        ds.push_back(nums[ind]);
        f(ind + 1, ds, ans, nums);
        ds.pop_back();

        // Not Take
        int next = ind + 1;
        while (next < nums.size() && nums[next] == nums[ind])
            next++;

        f(next, ds, ans, nums);
    }

    vector<vector<int>> subsetsWithDup(vector<int> &nums)
    {
        vector<vector<int>> ans;
        vector<int> ds;

        sort(nums.begin(), nums.end()); //For handling Duplicates
        f(0, ds, ans, nums);
        return ans;
    }
};