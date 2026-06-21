#include<bits/stdc++.h>
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

class Solution{

    public:
    int spanningTree(int V, vector<vector<int>> adj[]){
        vector<pair<int, pair<int,int>>> edges;
        for(int i =0 ; i <V; i++){
            for(auto it: adj[i]){
                int adjNode = it[0];
                int wt = it[1];
                int node = i;

                edges.push_back({wt,{node, adjNode}});
            }
        }

        DisjointSet ds(V);

        sort(edges.begin(), edges.end());

        int mstWT = 0;
        for(auto it: edges){
            int wt = it.first;
            int u = it.second.first;
            int v = it.second.second;

            if(ds.findUParent(u) != ds.findUParent(v)){
                mstWT += wt;
                ds.UnionBySize(u,v);
            }
        }

        return mstWT;
    }

};