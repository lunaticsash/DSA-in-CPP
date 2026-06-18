#include <bits/stdc++.h>
using namespace std;

//Time complexity: O(n³)
//Space complexity: O(1), because matrix is updated in-place.
class Solution
{
public:
    void shortest_distance(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        // Preprocessing the matrix to replace -1 with a large number and set diagonal to 0
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (matrix[i][j] == -1)
                {
                    matrix[i][j] = 1e9;
                }
                if (i == j)
                    matrix[i][j] = 0;
            }
        }

        // Main
        for (int k = 0; k < n; k++)
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j]);
                }
            }
        }

        // For negative cycle checking
        for (int i = 0; i < n; i++)
        {
            if (matrix[i][i] < 0)
            {
                cout << "Negative Cycle Detected" << endl;
                return;
            }
        }

        // Postprocessing the matrix to replace large numbers with -1
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (matrix[i][j] == 1e9)
                {
                    matrix[i][j] = -1;
                }
            }
        }
    }
};