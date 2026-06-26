#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    void dfs(int node, vector<int> &vis, vector<int> adj[], stack<int> &st)
    {
        vis[node] = 1;

        for (auto it : adj[node])
        {
            if (!vis[it])
            {
                dfs(it, vis, adj, st);
            }
        }

        st.push(node);
    }

    void dfs2(int node, vector<int> &vis, vector<int> adjT[])
    {
        vis[node] = 1;

        for (auto it : adjT[node])
        {
            if (!vis[it])
            {
                dfs2(it, vis, adjT);
            }
        }
    }

public:
    int kosarajuAlgo(int V, vector<int> adj[])
    {
        vector<int> vis(V, 0);
        stack<int> st;

        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {
                dfs(i, vis, adj, st);
            }
        }

        vector<int> adjT[V];
        for (int i = 0; i < V; i++)
        {
            vis[i] = 0;
            for (auto it : adj[i])
            {
                // reversing the edges
                adjT[it].push_back(i);
            }
        }

        int scc = 0;
        while (!st.empty())
        {
            int node = st.top();
            st.pop();

            if (!vis[node])
            {
                scc++;
                dfs2(node, vis, adjT);
            }
        }

        return scc;
    }
};













/*
    1. If we think let's say that our graph has n Strongly Connected Component, say sc1, sc2 ...scn. Then whole graph will be visited in order, `sc1-->sc2-->sc3-->....-->scn`.
    2. Now if we remove all the edges which connect the 2 connected component then in one visit we will be traversing 1 Strongly Connected Component. `sc1, sc2, sc3,...,scn`.
    3. So, Idea is to remove link between connected component. Ok! but how we know in advance exactly which edge is link? Ans is we don't. And that's why instead of removing edge, we will reverse all the edge. so a link edge b/w `sc1-->sc2` became `sc2-->sc1` and thus if you start with sc1, you will only visit sc1 component.
    4. Does reversing edge will not affect component's like sc1,sc2 etc. Ans is no because they are Strongly Connected component, if you reverse each edge of a Strongly Connected Component, it will still be a Strongly Connected Component.
    5. Ok! Alright, One final caveat, let's say we start traversing from sc2? Then in one visit we can traverse both sc1,sc2. To prevent this, we will sort the vertices in finish time of dfs and visit the vertices who finished last. So, if in original graph, there is a relation like `sc1-->sc2`, sc1 will always finish last and thus will be picked first.
    6. Does BFS work? No, we have to sort according to finish time.


*/