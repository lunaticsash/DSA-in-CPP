#include <bits/stdc++.h>
#include <deque>
using namespace std;

// 0-1 BFS is an optimized version of Dijkstra used when all edge weights are only 0 or 1. It replaces the priority queue with a deque: if an edge has weight 0, push the node to the front (push_front()); if the edge has weight 1, push it to the back (push_back()). This maintains nodes in increasing order of distance, achieving O(V + E) time complexity.

int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, int>>> graph(n);

    for (int i = 0; i < m; i++)
    {
        int u, v, wt;
        cin >> u >> v >> wt;

        graph[u].push_back({v, wt});
        graph[v].push_back({u, wt}); // Remove if graph is directed
    }

    int src;
    cin >> src;

    vector<int> dist(n, INT_MAX);
    deque<int> dq;

    dist[src] = 0;
    dq.push_front(src);

    while (!dq.empty())
    {
        int node = dq.front();
        dq.pop_front();

        for (auto it : graph[node])
        {
            int adj = it.first;
            int wt = it.second;

            if (dist[node] + wt < dist[adj])
            {
                dist[adj] = dist[node] + wt;

                if (wt == 0)
                    dq.push_front(adj);
                else
                    dq.push_back(adj);
            }
        }
    }

    cout << "Shortest Distance:\n";

    for (int i = 0; i < n; i++)
        cout << src << " -> " << i << " = " << dist[i] << '\n';
}