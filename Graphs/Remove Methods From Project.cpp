#include <bits/stdc++.h>
using namespace std;

// Complexity
//  Building graph: O(E)
//  DFS: O(V + E)
//  Checking edges: O(E)
//  Building answer: O(V)
//  Overall: O(V + E)
class Solution {
public:
    void dfsforSus(int node, vector<vector<int>>& adj, vector<int>& vis,
                   vector<int>& sus) {
        vis[node] = 1;
        sus[node] = 1;

        for (auto it : adj[node]) {
            if (!vis[it]) {
                dfsforSus(it, adj, vis, sus);
            }
        }
    }

    vector<int> remainingMethods(int n, int k,
                                 vector<vector<int>>& invocations) {
        vector<int> ans;
        vector<int> vis(n, 0);
        vector<int> sus(n, 0);

        vector<vector<int>> adj(n);

        for (auto& edge : invocations) {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
        }

        // Dfs for sus
        dfsforSus(k, adj, vis, sus);

        for (auto& edge : invocations) {
            int u = edge[0];
            int v = edge[1];

            if (!sus[u] && sus[v]) {
                // Outside -> Inside
                // Removal is impossible.
                if (!sus[u] && sus[v]) {
                    vector<int> ans2;
                    for (int i = 0; i < n; i++)
                        ans2.push_back(i);
                    return ans2;
                }
            }
        }

        // Removal is possible
        for (int i = 0; i < n; i++) {
            if (!sus[i])
                ans.push_back(i);
        }

        return ans;
    }
};