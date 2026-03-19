#include <bits/stdc++.h>
using namespace std;

struct Node
{
    Node *links[2]; //) 0 and 1
    bool containsKey(int bit)
    {
        return (links[bit] != NULL);
    }

    Node *get(int bit)
    {
        return links[bit];
    }

    void put(int bit, Node *node)
    {
        links[bit] = node;
    }
};

class Trie
{
public:
    Node *root;
    Trie()
    {
        root = new Node();
        ;
    }

public:
    void insert(int num)
    {
        Node *node = root;
        for (int i = 31; i >= 0; i--)
        {
            int bit = (num >> i) & 1;
            if (!node->containsKey(bit))
            {
                node->put(bit, new Node());
            }
            node = node->get(bit);
        }
    }

public:
    int getMax(int num){
        Node* node = root;
        int maxNum = 0;
        for( int i = 31 ; i >= 0; i--){
            int bit = (num >> i) & 1;
            if(node->containsKey(1 - bit)){//inorder to see opposite
                maxNum = maxNum  | (1 << i);
                node = node->get(1 - bit);
            }
            else{// if it does not contain the opposite bit 
                node = node->get(bit);
            }
        }
        return maxNum;
    }

};

int maxXOR(int n, int m, vector<int> &arr1, vector<int> &arr2)
{
    Trie trie;
    for(auto &it : arr1) trie.insert(it);
    int maxi = 0;
    for(auto &it: arr2){
        maxi = max(maxi, trie.getMax(it));
    }
}

int main()
{
    // Example usage:
    vector<int> arr1 = {5, 1, 7};
    vector<int> arr2 = {3, 10, 6};
    int result = maxXOR(arr1.size(), arr2.size(), arr1, arr2);
    cout << "Maximum XOR is: " << result << endl;

    return 0;
}



