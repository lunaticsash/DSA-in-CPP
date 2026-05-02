#include<bits/stdc++.h>
using namespace std;


class Solution{
    public:
    void dfs(int node, vector<int> adj[], int vis[], vector<int>& dfs){
        vis[node] = 1; //marking the source node as visited
        dfs.push_back(node);
        for(auto it: adj[node]){
            if(!vis[it]){
                dfs(it, adj, vis, dfs);
            }
        }
    }

    vector<int> dfsOfGraph(int V, vector<int> adj[]){
        // 0 based indexing
        int vis[V] = {0};
        vector<int> dfs;
        for(int i = 0; i<V; i++){
            if(!vis[i]){
                dfs(i, adj, vis, dfs);
            }
        }
        return dfs;
    }
};
