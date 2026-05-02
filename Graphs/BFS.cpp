#include <bits/stdc++.h>
using namespace std;

// TC=>O(N) + O(2E) => O(N + E)
// SC=>O(3N) => O(N)

class Solution
{

    vector<int> bfsOfGraph(int V, vector<int> adj[])
    {
        // 0 based indexing
        int vis[V] = {0};
        vis[0] = 1; // marking the source node as visited
        queue<int> q;
        q.push(0);
        vector<int> bfs;
        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            bfs.push_back(node);

            for (auto it : adj[node])
            {
                if (!vis[it])
                {
                    vis[it] = 1;
                    q.push(it);
                }
            }
        }
        return bfs;
    }
};