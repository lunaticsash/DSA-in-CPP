#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Function to find shortest distance from source S
    vector<int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        set<pair<int, int>> st;
        vector<int> dist(V, 1e9);

        st.insert({0, S});
        dist[S] = 0;

        while (!st.empty())
        {
            auto it = *(st.begin()); //points to beginning el of set
            int node = it.second;
            int distance = it.first;
            st.erase(it);

            for (auto it : adj[node])
            {
                int adjNode = it[0];
                int edgeWeight = it[1];

                if (distance + edgeWeight < dist[adjNode])
                {
                    //Erase if it existed before
                    if (dist[adjNode] != 1e9)
                    {
                        st.erase({dist[adjNode], adjNode});
                    }
                    dist[adjNode] = distance + edgeWeight;
                    st.insert({dist[adjNode], adjNode});
                }
            }
        }
        return dist;
    }
};