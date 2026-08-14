#include <bits/stdc++.h>
using namespace std;
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */


 //Brute force 
 //TC = O(2N)
 //SC = O(N)
class Solution {
public:
    void inorderforBST(TreeNode* root, vector<int>& inorder) {
        if (root == NULL)
            return;
        inorderforBST(root->left, inorder);
        inorder.push_back(root->val);
        inorderforBST(root->right, inorder);
    }

    bool findTarget(TreeNode* root, int k) {
        vector<int> inorder;
        inorderforBST(root, inorder); // sorted inorder

        int n = inorder.size();
        int l = 0, r = n - 1;

        while (l < r) {
            int sum = inorder[l] + inorder[r];

            if (sum == k)
                return true;
            else if (sum < k)
                l++;
            else
                r--;
        }

        return false;
    }
};