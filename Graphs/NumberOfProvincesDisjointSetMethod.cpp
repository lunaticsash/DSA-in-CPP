#include <bits/stdc++.h>
using namespace std;

class DisjointSet
{

public:
    vector<int> rank, parent, size;
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
    int numberOfProvinces(vector<vector<int>> adj, int V)
    {
        DisjointSet ds(V);

        for (int i = 0; i < V; i++)
        {
            for (int j = 0; j < V; j++)
            {
                if (adj[i][j] == 1)
                {
                    ds.UnionBySize(i, j);
                }
            }
        }

        int count = 0;
        for (int i = 0; i < V; i++)
        {
            if (ds.parent[i] == i)
                count++;
        }

        return count;
    }
};