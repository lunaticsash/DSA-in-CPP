#include <bits/stdc++.h>
using namespace std;

void findCommonElements(vector<vector<int>> &mat)
{
    int m = mat.size(), n = mat[0].size();

    // Frequency array (assuming elements are within 0 to 9999)
    int freq[10000] = {0};

    // Mark first row elements as seen (freq[element] = 1)
    for (int j = 0; j < n; j++)
    {
        if (freq[mat[0][j]] == 0) // Avoid duplicates
            freq[mat[0][j]] = 1;
    }

    // Traverse remaining rows
    for (int i = 1; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            // Check if the element was seen in the previous row
            if (freq[mat[i][j]] == i)
            {
                freq[mat[i][j]] = i + 1; // Mark it for this row
            }
        }
    }

    // Print common elements (those appearing in all m rows)
    for (int num = 0; num < 10000; num++)
    {
        if (freq[num] == m)
        {
            cout << num << " ";
        }
    }
}

int main()
{
    vector<vector<int>> mat = {{1, 2, 1, 4, 8},
                               {3, 7, 8, 5, 1},
                               {8, 7, 7, 3, 1},
                               {8, 1, 2, 7, 9}};

    findCommonElements(mat);
    return 0;
}
