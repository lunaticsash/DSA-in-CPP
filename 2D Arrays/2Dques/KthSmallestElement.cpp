#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int kthSmallest(int mat[][4], int n, int k)//int mat[MAX][MAX]
{
    //making a new vector
    vector<int> a;
    
    //putting all elements of matrix in a
    int index = 0;
    for(int i = 0; i< n; i++){
        for(int j = 0; j<n; j++){
            a.push_back(mat[i][j]);
        }
    }
    
    //taking out min element for k;
    int count = 0;
    for (int i = 0; i < k; i++) {
        auto minIt = min_element(a.begin(), a.end());  // Iterator to min element
        count = *minIt;  // Store the value
        a.erase(minIt);  // Remove the min element
    }
    
    return count;
    
}


//BINARY SEARCH APPROACH

// #include <bits/stdc++.h>
// using namespace std;

// // Function to count numbers ≤ mid
// int countLessEqual(vector<vector<int>>& mat, int n, int mid) {
//     int count = 0, row = n - 1, col = 0;
//     while (row >= 0 && col < n) {
//         if (mat[row][col] <= mid) {
//             count += (row + 1); // All elements in this column up to row are ≤ mid
//             col++;
//         } else {
//             row--;
//         }
//     }
//     return count;
// }

// // Function to find Kth smallest element
// int kthSmallest(vector<vector<int>>& mat, int n, int k) {
//     int low = mat[0][0], high = mat[n - 1][n - 1];
    
//     while (low < high) {
//         int mid = low + (high - low) / 2;
//         if (countLessEqual(mat, n, mid) < k)
//             low = mid + 1;
//         else
//             high = mid;
//     }
//     return low;
// }

// // Driver Code
// int main() {
//     vector<vector<int>> matrix = {
//         {16, 28, 60, 64},
//         {22, 41, 63, 91},
//         {27, 50, 87, 93},
//         {36, 78, 87, 94}
//     };
//     int k = 3;
//     cout << "The " << k << "rd smallest element is: " << kthSmallest(matrix, 4, k);
//     return 0;
// }
