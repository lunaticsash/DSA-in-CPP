#include<bits/stdc++.h>
using namespace std;


//TC => O(E log V) + O(V) => O(E log V)
//SC => O(V) + O(V) + O(V) => O(V)
class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {

        vector<pair<int, int>> adj[n];
        for (auto it : roads) {
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }

        // long long for distance values
        priority_queue<pair<long long, int>, 
                       vector<pair<long long, int>>,
                       greater<pair<long long, int>>> pq;

        vector<long long> dist(n, 1e18); // long long infinity
        vector<int> ways(n, 0);

        dist[0] = 0;
        ways[0] = 1;
        pq.push({0, 0});

        int mod = 1e9 + 7;

        while (!pq.empty()) {
            long long dis = pq.top().first; // long long
            int node = pq.top().second;
            pq.pop();

            for (auto it : adj[node]) {
                int adjNode = it.first;
                int edW = it.second;

                if (dis + edW < dist[adjNode]) {
                    dist[adjNode] = dis + edW;
                    pq.push({dis + edW, adjNode});
                    ways[adjNode] = ways[node];
                }
                else if (dis + edW == dist[adjNode]) {
                    ways[adjNode] = (ways[adjNode] + ways[node]) % mod;
                }
            }
        }

        return ways[n - 1] % mod;
    }
};