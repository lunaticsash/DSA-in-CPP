#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // Step 1: Get the number of rows and columns
        int row = matrix.size();         // Total number of rows
        int col = matrix[0].size();      // Total number of columns

        // Step 2: Start searching from the top-right corner
        int rowIndex = 0;                // Start with the first row
        int colIndex = col - 1;          // Start with the last column

        // Step 3: Perform the search
        while (rowIndex < row && colIndex >= 0) {
            int element = matrix[rowIndex][colIndex]; // Current element to compare

            if (element == target) {     // Case 1: If target is found
                return true;             // Return true
            }
            if (element < target) {      // Case 2: If element is smaller than target
                rowIndex++;              // Move down to the next row
            } else {                     // Case 3: If element is larger than target
                colIndex--;              // Move left to the previous column
            }
        }

        // Step 4: If the loop ends, the target was not found
        return false;
    }
};
