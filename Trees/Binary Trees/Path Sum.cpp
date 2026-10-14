#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (root == NULL) {
            return false;
        }

        // Leaf node
        if (root->left == NULL && root->right == NULL) {
            return targetSum == root->val;
        }

        targetSum -= root->val;

        return hasPathSum(root->left, targetSum) ||
               hasPathSum(root->right, targetSum);
    }
};


class Solution {
public:
    bool flag = false;

    bool solve(TreeNode* root, int targetSum, int sum) {
        if (root == NULL) {
            return false;
        }

        sum += root->val;

        if (root->left == NULL && root->right == NULL) {
            if (sum == targetSum) {
                flag = true;
                return true;
            }
            return false;
        }

        if (root->left != NULL) {
            solve(root->left, targetSum, sum);
        }

        if (root->right != NULL) {
            solve(root->right, targetSum, sum);
        }

        return flag;
    }

    bool hasPathSum(TreeNode* root, int targetSum) {
        flag = false;

        return solve(root, targetSum, 0);
    }
};