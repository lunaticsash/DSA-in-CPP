#include <bits/stdc++.h>
using namespace std;

// TC => O(E log V) + O(V) for returning the distance vector
class Solution
{
public:
    // Function to find shortest distance from source S
    vector<int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // Min-heap → {distance, node}
        priority_queue<pair<int, int>,
                       vector<pair<int, int>>,
                       greater<pair<int, int>>>
            pq;

        vector<int> dist(V, 1e9); // initialize with infinity

        dist[S] = 0;
        pq.push({0, S}); // {distance, node}

        while (!pq.empty())
        {
            int dis = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            // Traverse neighbors
            for (auto it : adj[node])
            {
                int adjNode = it[0];    // neighbor node
                int edgeWeight = it[1]; // weight

                // Relaxation step
                if (dis + edgeWeight < dist[adjNode])
                {
                    dist[adjNode] = dis + edgeWeight;
                    pq.push({dist[adjNode], adjNode});
                }
            }
        }

        return dist;
    }
};