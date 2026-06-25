#include <bits/stdc++.h>
using namespace std;

// TC => O(n² * 4 * α) + O(n² * 4 * log4) + O(n² * α) =  O(n^2)
// SC => O(n^2)

class DisjointSet
{
public:
    vector<int> rank, parent, size;
    DisjointSet(int n)
    {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1, 1);
        for (int i = 0; i <= n; i++)
        {
            parent[i] = i;
        }
    }

    int findUParent(int node)
    { // Ultimate parent
        if (node == parent[node])
        {
            return node;
        }
        return parent[node] = findUParent(parent[node]);
    }

    // TC => O(constant)
    void UnionByRank(int u, int v)
    {
        int ulp_u = findUParent(u);
        int ulp_v = findUParent(v);
        if (ulp_u == ulp_v)
            return;
        if (rank[ulp_v] < rank[ulp_u])
        {
            parent[ulp_v] = parent[ulp_u];
        }
        else if (rank[ulp_v] > rank[ulp_u])
        {
            parent[ulp_u] = parent[ulp_v];
        }
        else
        {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }

    void UnionBySize(int u, int v)
    {
        int ulp_u = findUParent(u);
        int ulp_v = findUParent(v);
        if (ulp_u == ulp_v)
            return;
        if (size[ulp_u] < size[ulp_v])
        {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else
        {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

class Solution
{
private:
    bool isValid(int adjr, int adjc, int n)
    {
        return adjr >= 0 && adjr < n && adjc >= 0 && adjc < n;
    }

public:
    int largestIsland(vector<vector<int>> &grid)
    {
        int n = grid.size();
        DisjointSet ds(n * n);
        // Step 1 => connecting components
        for (int row = 0; row < n; row++)
        {
            for (int col = 0; col < n; col++)
            {
                if (grid[row][col] == 0)
                    continue;
                int dr[] = {-1, 0, 1, 0};
                int dc[] = {0, -1, 0, 1};
                for (int ind = 0; ind < 4; ind++)
                {
                    int newr = row + dr[ind];
                    int newc = col + dc[ind];
                    if (isValid(newr, newc, n) && grid[newr][newc])
                    {
                        int nodeNo = row * n + col;
                        int adjNodeNo = newr * n + newc;
                        ds.UnionBySize(nodeNo, adjNodeNo);
                    }
                }
            }
        }
        // Step 2 => take 0 and try to convert it into one so that max size of 1's in island
        int mx = 0;
        for (int row = 0; row < n; row++)
        {
            for (int col = 0; col < n; col++)
            {
                if (grid[row][col] == 1)
                    continue;
                int dr[] = {-1, 0, 1, 0};
                int dc[] = {0, -1, 0, 1};

                set<int> components;
                for (int ind = 0; ind < 4; ind++)
                {
                    int newr = row + dr[ind];
                    int newc = col + dc[ind];
                    if (isValid(newr, newc, n))
                    {
                        if (grid[newr][newc] == 1)
                        {
                            components.insert(ds.findUParent(newr * n + newc));
                        }
                    }
                }

                int sizeTotal = 0;
                for (auto it : components)
                {
                    sizeTotal += ds.size[it];
                }
                mx = max(mx, sizeTotal + 1); // 1 for the himself
            }
        }

        // If all 1's
        for (int cellNo = 0; cellNo < n * n; cellNo++)
        {
            mx = max(mx, ds.size[ds.findUParent(cellNo)]);
        }

        return mx;
    }
};