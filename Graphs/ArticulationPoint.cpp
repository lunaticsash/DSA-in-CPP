#include <bits/stdc++.h>
using namespace std;

// SC = O(3N)
// TC = O(V+2E) + O(2N)

class Solution
{
private:
    int timer = 0;

private:
    void dfs(int node, int parent, vector<int> adj[], vector<int> &tin, vector<int> &low, vector<int> &mark)
    {
        tin[node] = low[node] = timer;
        timer++;
        int child = 0;
        for (auto it : adj[node])
        {
            if (it == parent)
                continue;
            if (tin[it] == -1)
            {
                dfs(it, node, adj, tin, low, mark);
                low[node] = min(low[node], low[it]);
                // node---it
                if (low[it] >= tin[node] && parent != -1)
                {
                    mark[node] = 1;
                }
                child++;
            }
            else
            {
                low[node] = min(low[node], tin[it]);
            }
        }
        if (child > 1 && parent == -1)
        {
            mark[node] = 1;
        }
    }

public:
    vector<int> articulationPoints(int n, vector<int> adj[])
    {

        vector<int> tin(n, -1);
        vector<int> low(n, -1);

        vector<int> mark(n, 0);
        for (int i = 0; i < n; i++)
        {
            if (tin[i] == -1)
            {
                dfs(i, -1, adj, tin, low, mark);
            }
        }
        vector<int> ans;
        for (int i = 0; i < n; i++)
        {
            if (mark[i] == 1)
            {
                ans.push_back(i);
            }
        }
        if (ans.size() == 0)
            return {-1};
        return ans;
    }
};

/*class Solution {
    private:
    int timer = 0;

private:
    void dfs(int node, int parent, vector<int> adj[], vector<int> &tin, vector<int> &low, vector<int> &mark)
    {
        tin[node] = low[node] = timer;
        timer++;
        int child = 0;
        for (auto it : adj[node])
        {
            if (it == parent)
                continue;
            if (tin[it] == -1)
            {
                dfs(it, node, adj, tin, low, mark);
                low[node] = min(low[node], low[it]);
                // node---it
                if (low[it] >= tin[node] && parent != -1)
                {
                    mark[node] = 1;
                }
                child++;
            }
            else
            {
                low[node] = min(low[node], tin[it]);
            }
        }
        if(child > 1 && parent == -1){
            mark[node] = 1;
        }
    }
public:

    vector<int> articulationPoints(int n, vector<int>adj[]) {


        vector<int> tin(n, -1);
vector<int> low(n, -1);

        vector<int> mark(n,0);
        for(int i =0; i < n ; i++){
            if(tin[i] == -1){
                dfs(i, -1, adj, tin, low, mark);

            }

        }
        vector<int> ans;
        for(int i = 0  ; i< n; i++){
            if(mark[i] == 1){
                ans.push_back(i);
            }
        }
        if(ans.size() == 0) return {-1};
        return ans;
    }
};
*/