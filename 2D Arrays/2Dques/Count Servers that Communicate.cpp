#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int n = grid[0].size();
        int m = grid.size();

        vector<int> colServerCount(n,0); // Kis col mai kkitne server
        vector<int> RowAkelaServerCol(m,-1);// Konse row mai ek matra akela server hai

        int resultServers = 0;
        for(int row = 0; row < m; row++){
            int countServersRow = 0;
            for(int col = 0; col < n ; col++){
                if(grid[row][col] == 1){
                    countServersRow += 1;
                    colServerCount[col]++;
                    RowAkelaServerCol[row] = col;
                }
            }

            if(countServersRow > 1){
                resultServers += countServersRow;
                RowAkelaServerCol[row] = -1; // No akela server in this row
            }

        }

        // Check Akela servers in each row
        for(int row = 0; row < m ; row++){
            if(RowAkelaServerCol[row] != -1){
                int col = RowAkelaServerCol[row];
                if(colServerCount[col] > 1){
                    resultServers += 1;
                }
            }
        }

        return resultServers;

    }
};