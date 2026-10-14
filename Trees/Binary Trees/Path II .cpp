#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    void solve(TreeNode* root, int targetSum, int sum,
               vector<int>& path, vector<vector<int>>& ans) {

        if (root == NULL) {
            return;
        }

        sum += root->val;
        path.push_back(root->val);

        // Leaf node
        if (root->left == NULL && root->right == NULL) {
            if (sum == targetSum) {
                ans.push_back(path);
            }

            path.pop_back();  // Backtrack
            return;
        }

        solve(root->left, targetSum, sum, path, ans);
        solve(root->right, targetSum, sum, path, ans);

        path.pop_back();  // Backtrack
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> path;

        solve(root, targetSum, 0, path, ans);

        return ans;
    }
};
