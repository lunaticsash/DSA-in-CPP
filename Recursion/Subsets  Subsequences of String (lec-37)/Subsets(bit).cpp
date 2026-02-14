#include <bits/stdc++.h>
using namespace std;
//✨BITWISE APPROACH
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        
        int n = nums.size();
        int subset = 1<<n;
        vector<vector<int>>ans;
        for(int num = 0;num<subset;num++)
        {
            vector<int>temp;
            for(int i = 0;i<n;i++)
            {
                if(num & (1<<i)) temp.push_back(nums[i]);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};

//✅ITERATIVE APPROACH   
// vector<vector<int>> outer = {{}};
// for (int num : nums) {
//     int n = outer.size();
//     for (int i = 0; i < n; i++) {
//         vector<int> internal = outer[i];
//         internal.push_back(num);
//         outer.push_back(internal);
//     }
// }
// return outer;

// | Approach                             | Description                                                                | Time & Space                             | Pros                                           | Cons                                       |
// | ------------------------------------ | -------------------------------------------------------------------------- | ---------------------------------------- | ---------------------------------------------- | ------------------------------------------ |
// | **1. Recursion (Backtracking)**      | Make a choice (include/exclude each element), go deeper                    | ⏱ `O(2^n * n)`<br>🧠 Stack Space: `O(n)` | Easy to understand<br>Matches decision tree    | Slower due to function call overhead       |
// | **2. Iterative (expanding subsets)** | Start with `[]`, and for each element, add it to existing subsets          | ⏱ `O(2^n * n)`<br>🧠 Space: `O(2^n)`     | Clean logic<br>No recursion<br>Memory friendly | Less intuitive for deep branching problems |
// | **3. Bitmasking**                    | Use binary numbers from `0` to `2^n - 1` to represent all possible subsets | ⏱ `O(2^n * n)`<br>🧠 Fastest in practice | Fast execution<br>No recursion<br>Elegant      | Requires understanding of bitwise ops      |
