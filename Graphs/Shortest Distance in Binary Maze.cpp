#include <bits/stdc++.h>
using namespace std;

class Solution
{

public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source, pair<int, int> destination)
    {
        queue<pair<int, pair<int, int>>> q;
        int n = grid.size();
        int m = grid[0].size();

        if (source == destination)
            return 0;

        vector<vector<int>> dist(n, vector<int>(m, 1e9));
        dist[source.first][source.second] = 0;
        // Push the source cell in the queue with distance 0 from itself
        q.push({0, {source.first, source.second}}); 

        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};

        while (!q.empty())
        {
            auto it = q.front();
            q.pop();
            int dis = it.first;
            
            int r = it.second.first;
            int c = it.second.second;
            for (int i = 0; i < 4; i++)
            {
                int newr = r + dr[i];
                int newc = c + dc[i];

                if (newr >= 0 && newr < n && newc >= 0 && newc < m && grid[newr][newc] == 1 && dis + 1 < dist[newr][newc])// All Boundary and Validity checks
                {
                    dist[newr][newc] = 1 + dis;
                    //If reached destination
                    if (newr == destination.first && newc == destination.second)
                        return dis + 1;
                    q.push({1 + dis, {newr, newc}}); // Push the new cell in the queue with its distance from source
                }
            }
        }
        return -1;
    }
};


// Shortest Distance in Binary Maze Leetcode 1091
//path are 8-directionally connected. So we need to check for all 8 directions in the code. The rest of the code is same as above.
class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();

        if (grid[0][0] == 1 || grid[n - 1][n - 1] == 1) {
            return -1;
        }

        if (n == 1) {
            return 1;
        }

        queue<pair<int, pair<int, int>>> q;

        vector<vector<int>> dist(n, vector<int>(n, 1e9));

        dist[0][0] = 1;
        q.push({1, {0, 0}});

        int dr[] = {-1, -1, -1, 0, 0, 1, 1, 1};
        int dc[] = {-1, 0, 1, -1, 1, -1, 0, 1};

        while (!q.empty()) {
            auto it = q.front();
            q.pop();

            int dis = it.first;
            int r = it.second.first;
            int c = it.second.second;

            for (int i = 0; i < 8; i++) {
                int newr = r + dr[i];
                int newc = c + dc[i];

                if (newr >= 0 && newr < n &&
                    newc >= 0 && newc < n &&
                    grid[newr][newc] == 0 &&
                    dis + 1 < dist[newr][newc]) {

                    dist[newr][newc] = dis + 1;

                    if (newr == n - 1 && newc == n - 1) {
                        return dis + 1;
                    }

                    q.push({dis + 1, {newr, newc}});
                }
            }
        }

        return -1;
    }
};