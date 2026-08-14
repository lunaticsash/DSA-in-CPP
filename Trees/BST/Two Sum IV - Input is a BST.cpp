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

class BSTIterator
{
    stack<TreeNode *> myStack;
    //if reverse is true then it will give next largest element or before in inorder traversal
    //else next smallest element or next in inorder traversal
    bool reverse;

public:
    BSTIterator(TreeNode *root, bool isReverse)
    {
        reverse = isReverse;
        pushAll(root);
    }

    int next()
    {
        TreeNode *tempNode = myStack.top();
        myStack.pop();

        if (!reverse)
            pushAll(tempNode->right);
        else
            pushAll(tempNode->left);

        return tempNode->val;
    }

    bool hasNext()
    {
        return !myStack.empty();
    }

private:
    void pushAll(TreeNode *node)
    {
        while (node != NULL)
        {
            myStack.push(node);

            if (reverse)
                node = node->right;
            else
                node = node->left;
        }
    }
};

class Solution
{
public:
    bool findTarget(TreeNode *root, int k)
    {

        BSTIterator l(root, false); // smallest → largest
        BSTIterator r(root, true);  // largest → smallest

        int i = l.next();
        int j = r.next();

        while (i < j)
        {

            if (i + j == k)
                return true;

            else if (i + j < k)
                i = l.next();

            else
                j = r.next();
        }

        return false;
    }
};

// Brute force
// TC = O(2N)
// SC = O(N)
class Solution
{
public:
    void inorderforBST(TreeNode *root, vector<int> &inorder)
    {
        if (root == NULL)
            return;
        inorderforBST(root->left, inorder);
        inorder.push_back(root->val);
        inorderforBST(root->right, inorder);
    }

    bool findTarget(TreeNode *root, int k)
    {
        vector<int> inorder;
        inorderforBST(root, inorder); // sorted inorder

        int n = inorder.size();
        int l = 0, r = n - 1;

        while (l < r)
        {
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