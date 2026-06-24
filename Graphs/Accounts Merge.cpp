#include <bits/stdc++.h>
using namespace std;

class DisjointSet
{
    vector<int> rank, parent, size;

public:
    DisjointSet(int n)
    {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1, 1);
        for (int i = 0; i <= n; i++)
        {
            parent[i] = i;
        }
    }

    int findUParent(int node)
    { // Ultimate parent
        if (node == parent[node])
        {
            return node;
        }
        return parent[node] = findUParent(parent[node]);
    }

    // TC => O(constant)
    void UnionByRank(int u, int v)
    {
        int ulp_u = findUParent(u);
        int ulp_v = findUParent(v);
        if (ulp_u == ulp_v)
            return;
        if (rank[ulp_v] < rank[ulp_u])
        {
            parent[ulp_v] = parent[ulp_u];
        }
        else if (rank[ulp_v] > rank[ulp_u])
        {
            parent[ulp_u] = parent[ulp_v];
        }
        else
        {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }

    void UnionBySize(int u, int v)
    {
        int ulp_u = findUParent(u);
        int ulp_v = findUParent(v);
        if (ulp_u == ulp_v)
            return;
        if (size[ulp_u] < size[ulp_v])
        {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else
        {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

class Solution
{
public:
    vector<vector<string>> accountsMerge(vector<vector<string>> &details)
    {
        int n = details.size();
        DisjointSet ds(n);  
        unordered_map<string, int> mapMailNode;
        for(int i = 0; i < n ; i++){
            for(int j = 1; j < details[i].size(); j++){
                string mail = details[i][j];
                if(mapMailNode.find(mail) == mapMailNode.end()){
                    mapMailNode[mail] = i;
                }
                else{
                    ds.UnionBySize(i, mapMailNode[mail]);
                }
            }
        }

        vector<string> mergeMail[n];
        for(auto it : mapMailNode){
            string mail = it.first;
            int node = ds.findUParent(it.second);
            mergeMail[node].push_back(mail);    
        }

        vector<vector<string>> ans;

        for(int i =00 ; i < n ; i++){
            if(mergeMail[i].size() == 0) continue;
            sort(mergeMail[i].begin(), mergeMail[i].end());
            vector<string> temp;
            temp.push_back(details[i][0]);
            for(auto it: mergeMail[i]){
                temp.push_back(it);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};