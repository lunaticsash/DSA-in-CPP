#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to count elements less than or equal to mid in a row
int countSmallerThanMid(vector<int> &row, int mid)
{
    return upper_bound(row.begin(), row.end(), mid) - row.begin();
}

// Function to find median in a row-wise sorted matrix
int findMedian(vector<vector<int>> &matrix, int rows, int cols)
{
    int minVal = matrix[0][0], maxVal = matrix[0][cols - 1];

    // Finding the global min and max in the matrix
    for (int i = 1; i < rows; i++)
    {
        minVal = min(minVal, matrix[i][0]);
        maxVal = max(maxVal, matrix[i][cols - 1]);
    }

    int desiredCount = (rows * cols) / 2; // Median position

    while (minVal < maxVal)
    {
        int mid = minVal + (maxVal - minVal) / 2;
        int count = 0;

        // Count elements ≤ mid in each row
        for (int i = 0; i < rows; i++)
        {
            count += countSmallerThanMid(matrix[i], mid);
        }

        if (count <= desiredCount)
        {
            minVal = mid + 1; // Move right
        }
        else
        {
            maxVal = mid; // Move left
        }
    }

    return minVal; // The median value
}

int main()
{
    vector<vector<int>> mat = {
        {1, 3, 5},
        {2, 6, 9},
        {3, 6, 9}};

    int rows = mat.size(), cols = mat[0].size();
    cout << "Median: " << findMedian(mat, rows, cols) << endl;
    return 0;
}
