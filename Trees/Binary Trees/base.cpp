#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

int main()
{
    struct Node* root = new Node(1);

    root->left = new Node(2);
    root->right = new Node(3);
    root->right->left = new Node(4);

    return 0;
}