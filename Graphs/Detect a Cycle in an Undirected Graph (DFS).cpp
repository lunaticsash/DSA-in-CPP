#include <bits/stdc++.h>
using namespace std;

class Solution{

    public:
    bool dfs(int node, int parent, vector<int>& vis, vector<int>adj[]){
        vis[node] = 1;
        for(auto adjacentNode: adj[node]){
            if(!vis[adjacentNode]){
                if(dfs(adjacentNode, node, vis, adj)) return true;
            }
            else if(parent != adjacentNode) return true;
        }
        return false;
    }

    bool isCycle(int V, vector<int> adj[]){
        vector<int> vis(V, 0);
        for(int i = 0; i <V; i++){
            if(!vis[i]){
                if(dfs(i, -1, vis, adj)) return true;
            }
        }
        return false;
    }
};