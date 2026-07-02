#include<bits/stdc++.h> 
using namespace std;

// Modified Dijkstra's algorithm to find a safe walk through a grid
//TC = O(N*M*log(N*M)), SC = O(N*M)
class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int n = grid.size();
        int m = grid[0].size();
        vector<int> d{0, 1, 0, -1, 0};
        vector<vector<int>> cost(n, vector<int>(m, INT_MIN)); // dist array
        cost[0][0] = health - grid[0][0];
        // max-heap to prioritize paths with more health left
        priority_queue<pair<int, pair<int, int>>> pq; // max pq
        pq.push({cost[0][0], {0, 0}});

        while (!pq.empty()) {

            auto it = pq.top();
            pq.pop();

            int healthLeft = it.first;
            int i = it.second.first;
            int j = it.second.second;

            if (healthLeft != cost[i][j])
                continue;

            if (healthLeft < 1)
                break;

            if (i == n - 1 && j == m - 1)
                return true;

            for (int k = 0; k < 4; k++) {

                int ni = i + d[k];
                int nj = j + d[k + 1];

                if (ni >= 0 && ni < n && nj >= 0 && nj < m) {

                    int newHealth = healthLeft - grid[ni][nj];

                    if (newHealth > cost[ni][nj]) {

                        
                        cost[ni][nj] = newHealth;
                        pq.push({newHealth, {ni, nj}});
                    }
                }
            }
        }
    return false;
    }
};