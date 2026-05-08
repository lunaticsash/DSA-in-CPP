#include<bits/stdc++.h>
using namespace std;

// T.C => O(N*M) + O(N*M) + O(N*M*4) ~ O(N*M)
// S.C => O(N*M) + O(N*M) ~ O(N*M)

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int cntfresh = 0;

        //{{r,c}, time}
        queue<pair<pair<int, int>, int>> q;
        int vis[n][m];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2) {
                    q.push({{i, j}, 0});
                    vis[i][j] = 2;
                } else {
                    vis[i][j] = 0;
                }
                if (grid[i][j] == 1)
                    cntfresh++;
            }
        }

        int tm = 0;
        int drow[] = {-1, 0, +1, 0};
        int dcol[] = {0, 1, 0, -1};
        int cnt = 0;
        while (!q.empty()) {
            int r = q.front().first.first; // first ka first
            int c = q.front().first.second;
            int t = q.front().second;

            q.pop();
            for (int i = 0; i < 4; i++) {
                int nrow = r + drow[i];
                int ncol = c + dcol[i];
                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
                    vis[nrow][ncol] != 2 && grid[nrow][ncol] == 1) {
                    q.push({{nrow, ncol}, t + 1});
                    vis[nrow][ncol] = 2;
                    tm = max(tm, t + 1);
                    cnt++;
                }
            }
        }
        if (cnt != cntfresh)
            return -1;
        return tm;
    }
};