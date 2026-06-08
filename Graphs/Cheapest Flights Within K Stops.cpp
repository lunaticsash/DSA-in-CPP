#include <bits/stdc++.h>
using namespace std;

// TC => O(N + E) + O(N*K) => O(N*K)
// SC => O(N) + O(N) => O(N)


class Solution
{
public:
    int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int K)
    {
        vector<pair<int, int>> adj[n];
        // Directed graph making
        //  Adjacency list:
        //  adj[u] = {v, price}
        //  means there is a directed flight from u to v with given price
        for (auto it : flights)
            adj[it[0]].push_back({it[1], it[2]});

        //Since the constraint is based on stops, we use BFS with a queue to explore paths level-wise by number of stops, instead of greedily choosing the minimum-cost path using a priority queue.
        queue<pair<int, pair<int, int>>> q;
        //{stops,{node,cost}}
        q.push({0, {src, 0}});

        // dist[i] stores the minimum cost found so far to reach city i
        vector<int> dist(n, 1e9);
        dist[src] = 0;
        // Performing Dijkstra's Algorithm
        while (!q.empty())
        {
            auto it = q.front();
            q.pop();

            int stops = it.first;
            int node = it.second.first;
            int cost = it.second.second;

            // If we have already used more than allowed stops,
            // no need to explore further from this node
            if (stops > K)
                continue;

            // Explore all flights from current city
            for (auto iter : adj[node])
            {
                int adjNode = iter.first; // next city
                int edw = iter.second;    // Flight price

                // If going through current node gives cheaper cost
                // and stop limit is still valid, then update
                if (cost + edw < dist[adjNode] && stops <= K)
                {
                    dist[adjNode] = cost + edw;

                    // Move to next city
                    // stops + 1 because we are taking one more flight
                    q.push({stops + 1, {adjNode, cost + edw}});
                }
            }
        }

        // We never reached the destination
        if (dist[dst] == 1e9)
            return -1;
        return dist[dst];
    }
};