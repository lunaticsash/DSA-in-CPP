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

vector<int> maxXorqueries(vector<int> &arr, vector<vector<int>> &queries)
{
    sort(arr.begin(), arr.end());
    vector<pair<int, pair<int, int>>> oQ;
    int q = queries.size();
    for(int i = 0 ; i <q ; i++){
        oQ.push_back({queries[i][1],{queries[i][0], i}});
    }

    sort(oQ.begin(), oQ.end());
    vector<int> ans(q,0);
    int ind =0;
    int n = arr.size();
    Trie trie;
    for(int i = 0; i<q ; i++){
        int ai = oQ[i].first;
        int xi = oQ[i].second.first;
        int qInd = oQ[i].second.second;
        while(ind < n && arr[ind] <= ai){
            trie.insert(arr[ind]);
            ind++;
        }
        if(ind == 0){
            ans[qInd] = -1;
        }
        else{
            ans[ind] = trie.getMax(xi);
        }
    }
    return ans;
}


int main()
{

    //eg
    vector<int> arr = {0,1,2,3,4};
    vector<vector<int>> queries = {{3,1},{1,3},{5,6}};
    vector<int> ans = maxXorqueries(arr, queries);
    for(auto &it : ans) cout<< it << " ";
    

    return 0;
}
