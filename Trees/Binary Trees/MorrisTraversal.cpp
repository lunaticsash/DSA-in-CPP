#include <bits/stdc++.h>
using namespace std;

class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int value) : val(value), left(nullptr), right(nullptr) {}
};

vector<int> morrisInorderTraversal(TreeNode *root)
{
    vector<int> inorder;
    TreeNode *cur = root;

    while (cur != nullptr)
    {
        if (cur->left == nullptr)
        {
            inorder.push_back(cur->val);
            cur = cur->right;
        }
        else
        { // Exist left
            TreeNode *prev = cur->left;
            while (prev->right != nullptr && prev->right != cur)
            { // Find predecessor
                prev = prev->right;
            }

            if (prev->right == nullptr)
            {
                prev->right = cur; // Create thread
                cur = cur->left;
            }
            else
            {
                prev->right = nullptr; // Remove thread
                inorder.push_back(cur->val);
                cur = cur->right;
            }
        }
    }
    return inorder;
}

vector<int> morrisPreorderTraversal(TreeNode *root)
{
    vector<int> preorder;
    TreeNode *cur = root;

    while (cur != nullptr)
    {
        if (cur->left == nullptr)
        {
            preorder.push_back(cur->val);
            cur = cur->right;
        }
        else
        { // Exist left
            TreeNode *prev = cur->left;
            while (prev->right != nullptr && prev->right != cur)
            {
                prev = prev->right;
            }

            if (prev->right == nullptr)
            {
                prev->right = cur; // Create thread
                preorder.push_back(cur->val);
                cur = cur->left;
            }
            else
            {
                prev->right = nullptr; // Remove thread
                cur = cur->right;
            }
        }
    }
    return preorder;
}

int main()
{

    /*
            1
           / \
          2   3
         / \
        4   5
    */

    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    vector<int> inorder = morrisInorderTraversal(root);
    vector<int> preorder = morrisPreorderTraversal(root);

    cout << "Inorder Traversal: ";
    for (int val : inorder)
    {
        cout << val << " ";
    }
    cout << endl;

    cout << "Preorder Traversal: ";
    for (int val : preorder)
    {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}