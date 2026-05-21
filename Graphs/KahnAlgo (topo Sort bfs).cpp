#include <bits/stdc++.h>
using namespace std;

// TC AND SC ARE O(V+E) AS BFS
class Solution
{
public:
    vector<int> topoSort(int V, vector<vector<int>> &adj)
    {
        vector<int> indegree(V, 0);
        for (int i = 0; i < V; i++)
        {
            for (auto it : adj[i])
            {
                indegree[it]++;
            }
        }
        queue<int> q;
        for (int i = 0; i < V; i++)
        {
            if (indegree[i] == 0)
            {
                q.push(i);
            }
        }
        vector<int> result;
        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            result.push_back(node);
            // Node is in your topo sort
            // so please remove it from the indegree of its adjacent nodes
            for (auto it : adj[node])
            {
                indegree[it]--;
                if (indegree[it] == 0)
                {
                    q.push(it);
                }
            }
        }
        return result;
    }
};