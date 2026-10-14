#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        // 1. Transpose of a matrirx

        int n = matrix[0].size();
        int i = 0;

        while (i < n) {
            int j = i + 1;

            while (j < n) {
                swap(matrix[i][j], matrix[j][i]);
                j++;
            }

            i++;
        }

        //2. Reverse the rows the matrix

        for (int i = 0; i < n; i++) {
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};