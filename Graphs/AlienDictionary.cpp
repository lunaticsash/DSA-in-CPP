#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
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

public:
    string findOrder(string dict[], int N, int K)
    {
        vector<vector<int>> adj(K);
        for (int i = 0; i < N - 1; i++)
        {
            string s1 = dict[i];
            string s2 = dict[i + 1];
            int len = min(s1.size(), s2.size());
            for (int ptr = 0; ptr < len; ptr++)
            {
                if (s1[ptr] != s2[ptr])
                {
                    adj[s1[ptr] - 'a'].push_back(s2[ptr] - 'a');
                    break;
                }
            }
        }
        vector<int> topo = topoSort(K, adj);
        string result = "";
        for (int i = 0; i < K; i++)
        {
            result += char(topo[i] + 'a'); // convert back to character and since subtracted 'a'
        }
        return result;
    }
};