#include <bits/stdc++.h>
using namespace std;

//TC => O(N + E) + O(N + E) + O(N) ~ O(N + E)
//SC => O(N) + O(N) + O(N) ~ O(N)
class Solution
{
private:
    void topoSort(int node, vector<pair<int, int>> adj[], vector<int> &vis, stack<int> &st)
    {
        vis[node] = 1;
        for (auto it : adj[node])
        {
            int v = it.first;
            if (!vis[v])
                topoSort(v, adj, vis, st);
        }
    }

public:
    vector<int> shortestPath(int N, int M, vector<int> edges[])
    {
        vector<pair<int, int>> adj[N];
        for (int i = 0; i < M; i++) // M cz no. of edges
        {
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];
            adj[u].push_back({v, wt});
        }

        // find the topo sort
        vector<int> vis(N, 0);
        stack<int> st;
        for (int i = 0; i < N; i++)
        {
            if (!vis[i])
            {
                topoSort(i, adj, vis, st);
            }
        }

        // Do the Distance thing
        vector<int> dist(N, 1e9);
        dist[0] = 0; // if source node is 0
        while (!st.empty())
        {
            int node = st.top();
            st.pop();
            // relaxing nodes
            for (auto it : adj[node])
            {
                int v = it.first;
                int wt = it.second;

                if (dist[node] + wt < dist[v])
                {
                    dist[v] = dist[node] + wt;
                }
            }
        }
        return dist;
    }
};