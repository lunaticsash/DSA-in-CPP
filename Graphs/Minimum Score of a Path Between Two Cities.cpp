/*
You are given a positive integer n representing n cities numbered from 1 to n. You are also given a 2D array roads where roads[i] = [ai, bi, distancei] indicates that there is a bidirectional road between cities ai and bi with a distance equal to distancei. The cities graph is not necessarily connected.

The score of a path between two cities is defined as the minimum distance of a road in this path.

Return the minimum possible score of a path between cities 1 and n.

Note:

A path is a sequence of roads between two cities.
It is allowed for a path to contain the same road multiple times, and you can visit cities 1 and n multiple times along the path.
The test cases are generated such that there is at least one path between 1 and n.
*/
#include<bits/stdc++.h>
using namespace std;

//TC AND SC : O(N+E), N = number of nodes, E = number of edges
class Solution {
public:
    void dfs(int node,
             vector<vector<pair<int, int>>> &adj,
             vector<int> &vis,
             int &ans) {

        vis[node] = 1;

        for (auto &it : adj[node]) {
            int ngbr = it.first;
            int wt = it.second;

            // Check every edge in the connected component
            ans = min(ans, wt);

            if (!vis[ngbr]) {
                dfs(ngbr, adj, vis, ans);
            }
        }
    }

    int minScore(int n, vector<vector<int>>& roads) {

        // Adjacency List: node -> (neighbor, weight)
        vector<vector<pair<int, int>>> adj(n + 1);

        for (auto &road : roads) {
            int u = road[0];
            int v = road[1];
            int wt = road[2];

            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }

        vector<int> vis(n + 1, 0);
        int ans = INT_MAX;

        dfs(1, adj, vis, ans);

        return ans;
    }
};