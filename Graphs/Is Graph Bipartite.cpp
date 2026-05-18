#include <bits/stdc++.h>
using namespace std;

//TC: O(V + E)  SC: O(V) for color array and O(V) for recursion stack in worst case
class Solution {
public:
    bool dfs(int node, int col, int color[], vector<vector<int>>& adj) {
        color[node] = col;

        for (auto it : adj[node]) {
            if (color[it] == -1) {
                // If neighbor is uncolored, recurse with opposite color
                if (!dfs(it, !col, color, adj))
                    return false;
            } else if (color[it] == col)
            // Neighbor has same color → not bipartite
                return false;
        }
        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int V = graph.size();
        int color[V];
        for (int i = 0; i < V; i++)
            color[i] = -1;

        for (int i = 0; i < V; i++) {
            if (color[i] == -1) {
                if (dfs(i, 0, color, graph) == false)
                    return false;
            }
        }
        return true;
    }
};