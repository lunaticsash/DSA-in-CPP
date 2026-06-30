#include <bits/stdc++.h>
using namespace std;


//O(V + E) TC
//O(V + E) SC   
class Solution
{
private:
    int timer = 0;

private:
    void dfs(int node, int parent, vector<int> &vis, vector<int> adj[], int tin[], int low[], vector<vector<int>> &bridges)
    {
        vis[node] = 1;
        tin[node] = low[node] = timer;
        timer++;
        for (auto it : adj[node])
        {
            if (it == parent)
                continue;
            if (vis[it] == 0)
            {
                dfs(it, node, vis, adj, tin, low, bridges);
                low[node] = min(low[node], low[it]);
                // node---it
                if (low[it] > tin[node])
                {
                    bridges.push_back({it, node});
                }
            }
            else
            {
                low[node] = min(low[node], tin[it]);
            }
        }
    }

public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>> &connections)
    {
        vector<int> adj[n];

        for (auto it : connections)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<int> vis(n, 0);
        int tin[n];
        int low[n];

        vector<vector<int>> bridges;
        dfs(0, -1, vis, adj, tin, low, bridges);
        return bridges;
        
    }
};

// Understading
/*
#include <bits/stdc++.h>
using namespace std;

// TC: O(V + E)
// SC: O(V + E)

class Solution
{
private:
    int timer = 0;

    void dfs(int node, int parent, vector<int> &vis, vector<int> adj[],
             int tin[], int low[], vector<vector<int>> &bridges)
    {
        vis[node] = 1; // Mark current node as visited

        tin[node] = low[node] = timer; // Store insertion time and lowest reachable time
        timer++;

        for (auto it : adj[node])
        {
            if (it == parent)
                continue; // Ignore the edge going back to parent

            if (vis[it] == 0)
            {
                dfs(it, node, vis, adj, tin, low, bridges); // DFS call for unvisited child

                low[node] = min(low[node], low[it]); // Update low value after child DFS

                if (low[it] > tin[node])
                {
                    bridges.push_back({node, it}); // Edge node-it is a bridge
                }
            }
            else
            {
                low[node] = min(low[node], tin[it]); // Back edge found, update low value
            }
        }
    }

public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>> &connections)
    {
        vector<int> adj[n]; // Adjacency list

        for (auto it : connections)
        {
            adj[it[0]].push_back(it[1]); // Add edge u -> v
            adj[it[1]].push_back(it[0]); // Add edge v -> u
        }

        vector<int> vis(n, 0); // Visited array

        int tin[n]; // Insertion time array
        int low[n]; // Lowest reachable time array

        vector<vector<int>> bridges; // Stores all bridge edges

        for (int i = 0; i < n; i++)
        {
            if (!vis[i])
            {
                dfs(i, -1, vis, adj, tin, low, bridges); // DFS for every component
            }
        }

        return bridges;
    }
};
};
*/

/*
class Solution {
    int timer = 1;

    // Passing raw pointers (C-style) to avoid any C++ object overhead during recursion
    void dfs(int u, int p, const int* head, const int* edges, int* tin, int* low, vector<vector<int>>& bridges) {
        tin[u] = low[u] = timer++;

        // In CSR, all edges for node 'u' are stored contiguously from head[u] to head[u+1] - 1
        int start = head[u];
        int end = head[u + 1];

        for (int i = start; i < end; ++i) {
            int v = edges[i];
            if (v == p) continue;

            if (!tin[v]) { // If not visited
                dfs(v, u, head, edges, tin, low, bridges);
                if (low[v] < low[u]) low[u] = low[v];

                // Bridge condition
                if (low[v] > tin[u]) {
                    bridges.push_back({u, v});
                }
            } else {
                // Back-edge
                if (tin[v] < low[u]) low[u] = tin[v];
            }
        }
    }

public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        int m = connections.size();

        // 1. Setup CSR Arrays
        // head[i] will store the starting index of node i's edges in the 'edges' array
        vector<int> head(n + 2, 0);
        vector<int> edges(2 * m);

        // 2. Count the degree (number of edges) for each node
        for (int i = 0; i < m; ++i) {
            head[connections[i][0] + 1]++;
            head[connections[i][1] + 1]++;
        }

        // 3. Compute prefix sums to determine actual starting blocks
        for (int i = 1; i <= n; ++i) {
            head[i] += head[i - 1];
        }

        // 4. Populate the flat edges array
        vector<int> cur_head = head; // Keep track of insertion points
        for (int i = 0; i < m; ++i) {
            int u = connections[i][0];
            int v = connections[i][1];
            edges[cur_head[u]++] = v;
            edges[cur_head[v]++] = u;
        }

        // 5. Run Tarjan's using raw contiguous arrays
        vector<int> tin(n, 0);
        vector<int> low(n, 0);
        vector<vector<int>> bridges;

        // Passing .data() converts the C++ vector into a raw C-pointer
        dfs(0, -1, head.data(), edges.data(), tin.data(), low.data(), bridges);

        return bridges;
    }
};
*/